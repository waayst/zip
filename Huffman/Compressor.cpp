#include "Compressor.h"
using namespace std;

Compressor::Compressor() {}

Compressor::Compressor(string* textPtr, BNode* codesTree)
	           :textPtr(textPtr),
	            codesTree(codesTree) {}

void Compressor::setTextPtr(string* newTextPtr) {
	textPtr = newTextPtr;
}

void Compressor::setCodesTree(BNode* newCodesTree) {
	codesTree = newCodesTree;
}

void Compressor::dfsTree(BNode* node, string curCode) {
	if (node->isALeaf()) {
		char leafCharacter = node->getCharacter();
		charactersDfsOrderPtr->push_back(leafCharacter);
		characterCodes.insert({ leafCharacter, curCode });
		return;
	}
	if (node->getLeft() != nullptr) {
		dfsCodePtr->push_back('0');
		dfsTree(node->getLeft(), curCode + '0');
	}
	if (node->getRight() != nullptr) {
		dfsCodePtr->push_back('1');
		dfsTree(node->getRight(), curCode + '1');
	}
}

void Compressor::createDfsInfo() {
	*dfsCodePtr = "";
	dfsTree(codesTree, "");
}

void Compressor::writeCompressed(unsigned char bit) { //unsigned char because signed has left bit as a sign bit
	string& compressedTextRef = *compressedTextPtr;
	bit *= 128; //moving bit to the left side
	char discharge = (bit >> byteOffset);
	compressedTextRef[byteNumber] |= discharge; 

	if (byteOffset == 7) {
		compressedTextRef.push_back((char)0);
		++byteNumber;
		byteOffset = -1;
	}
	++byteOffset;
}

void Compressor::writeCompressed(string code) {
	for (char &charCode : code) {
		writeCompressed(charCode - '0'); //setting '0' to 0 and '1' to 1
	}
}

void Compressor::createCompressedText() {
	byteNumber = 0;
	byteOffset = 0;
	*compressedTextPtr = (char)0;
	string& textRef = *textPtr;
	for (auto& character : textRef) {
		string code = characterCodes.find(character)->second;
		writeCompressed(code);
	}
}

std::string* Compressor::getCharactersDfsOrderPtr() {
	return charactersDfsOrderPtr;
}

std::string* Compressor::getDfsCodePtr() {
	return dfsCodePtr;
}

std::string* Compressor::getCompressedTextPtr() {
	return compressedTextPtr;
}

void Compressor::compress() {
	charactersDfsOrderPtr = new string{};
	dfsCodePtr = new string{};
	compressedTextPtr = new string{};
	createDfsInfo();
	createCompressedText();
}

Compressor::~Compressor() {
	safeDelete(charactersDfsOrderPtr);
	safeDelete(dfsCodePtr);
	safeDelete(compressedTextPtr);
}