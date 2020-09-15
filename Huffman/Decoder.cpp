#include "Decoder.h"
#include "HelpfulMethods.h"
using namespace std;

Decoder::Decoder() {}

Decoder::Decoder(uint32_t textSize,
	             string* compressedTextPtr,
	             BNode* codesTree)
	    :textSize(textSize),
	     compressedTextPtr(compressedTextPtr),
	     codesTree(codesTree) {}

Decoder::Decoder(FileData * compressedFileDataPtr, BNode* codesTree)
	    :codesTree(codesTree) {
	auto castedData = (CompressedFileData*)(compressedFileDataPtr);
	setTextSize(castedData->getTextSize());
	setCompressedTextPtr(castedData->getCompressedTextPtr());
}

string* Decoder::getTextPtr() const {
	return textPtr;
}

void Decoder::setTextSize(uint32_t newTextSize) {
	textSize = newTextSize;
}

void Decoder::setCompressedTextPtr(string * newCompressedTextPtr) {
	compressedTextPtr = newCompressedTextPtr;
}

void Decoder::setCodesTree(BNode * newCodesTree) {
	codesTree = newCodesTree;
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

