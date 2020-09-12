#include "Decoder.h"
#include "HelpfulMethods.h"
using namespace std;

Decoder::Decoder() {}

Decoder::Decoder(uint32_t textSize,
	std::string* compressedTextPtr, BNode* codesTree):
	textSize(textSize),
	compressedTextPtr(compressedTextPtr),
	codesTree(codesTree) {}

string* Decoder::getTextPtr() {
	return textPtr;
}

Decoder::~Decoder() {
	safeDelete(textPtr);
}

char Decoder::getCode() {
	auto& compressedRef = *compressedTextPtr;
	char bit = (128 >> offset);
	bit &= compressedRef[curByte];
	if (offset == 7) {
		offset = -1;
		++curByte;
	}
	++offset;
	return bit;
}

void Decoder::moveNode(char bit) {
	if (bit == 0) {
		curNode = curNode->getLeft();
	} else {
		curNode = curNode->getRight();
	}
}

void Decoder::decode() {
	safeDelete(textPtr);
	textPtr = new string;
	curByte = 0;
	offset = 0;
	curNode = codesTree;
	for (auto i = 0; i < textSize; ++i) {
		while (!curNode->isALeaf()) {
			char bit = getCode();
			moveNode(bit);
		}
		textPtr->push_back(curNode->getCharacter());
		curNode = codesTree;
	}
}

