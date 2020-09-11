#include "TextCompressor.h"
using namespace std;

TextCompressor::TextCompressor() {}

TextCompressor::TextCompressor(string* textPtr, BNode* codesTree)
	           :textPtr(textPtr),
	            codesTree(codesTree) {}

void TextCompressor::setTextPtr(string* newTextPtr) {
	textPtr = newTextPtr;
}

void TextCompressor::setCodesTree(BNode* newCodesTree) {
	codesTree = newCodesTree;
}

void TextCompressor::dfsTree(BNode* node, string curCode) {
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

void TextCompressor::createDfsInfo() {
	*dfsCodePtr = "";
	dfsTree(codesTree, "");
}

void TextCompressor::writeCompressed(unsigned char bit) { //unsigned char because signed has left bit as sign bit
	string& compressedTextRef = *compressedTextPtr;
	bit *= 128;
	char discharge = (bit >> byteOffset);
	compressedTextRef[byteNumber] |= discharge; 

	if (byteOffset == 7) {
		compressedTextRef.push_back((char)0);
		++byteNumber;
		byteOffset = -1;
	}
	++byteOffset;
}

void TextCompressor::writeCompressed(string code) {
	for (char &charCode : code) {
		writeCompressed(charCode - '0'); //48 is ascii of zero
	}
}

void TextCompressor::createCompressedText() {
	byteNumber = 0;
	byteOffset = 0;
	*compressedTextPtr = (char)0;
	string& textRef = *textPtr;
	for (auto& character : textRef) {
		string code = characterCodes.find(character)->second;
		writeCompressed(code);
	}
}

std::string* TextCompressor::getCharactersDfsOrderPtr() {
	return charactersDfsOrderPtr;
}

std::string* TextCompressor::getDfsCodePtr() {
	return dfsCodePtr;
}

std::string* TextCompressor::getCompressedTextPtr() {
	return compressedTextPtr;
}

void TextCompressor::compress() {
	charactersDfsOrderPtr = new string{};
	dfsCodePtr = new string{};
	compressedTextPtr = new string{};
	createDfsInfo();
	createCompressedText();
}

TextCompressor::~TextCompressor() {
	safeDelete(charactersDfsOrderPtr);
	safeDelete(dfsCodePtr);
	safeDelete(compressedTextPtr);
}