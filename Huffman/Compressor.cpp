#include "Compressor.h"
#include "HelpfulMethods.h"
using namespace std;

Compressor::Compressor() {}

Compressor::~Compressor() {
	safeDelete(charactersDfsOrderPtr);
	safeDelete(dfsCodePtr);
	safeDelete(compressedTextPtr);
}

void Compressor::compress() {
	charactersDfsOrderPtr = new string{};
	dfsCodePtr = new string{};
	compressedTextPtr = new string{};
	createDfsInfo();
	createCompressedText();
}

Compressor::Compressor(string* textPtr, BNode* codesTree)
	       :textPtr(textPtr),
	        codesTree(codesTree) {}

Compressor::Compressor(FileData * fileDataPtr, BNode * codesTree):codesTree(codesTree) {
	auto castedData = (FileToCompressData*)fileDataPtr;
	setTextPtr(castedData->getTextPtr());
}

std::string* Compressor::getCharactersDfsOrderPtr() {
	return charactersDfsOrderPtr;
}

std::string* Compressor::getDfsCodePtr() {
	return dfsCodePtr;
}

std::uint32_t Compressor::getTextSize() {
	return textPtr->size();
}

std::string* Compressor::getCompressedTextPtr() {
	return compressedTextPtr;
}

void Compressor::setCodesTree(BNode* newCodesTree) {
	codesTree = newCodesTree;
}

void Compressor::setTextPtr(string* newTextPtr) {
	textPtr = newTextPtr;
}

void Compressor::createDfsInfo() {
	*dfsCodePtr = "";
	dfsTree(codesTree, "");
}

void Compressor::createCompressedText() {
	byteNumber = 0;
	byteOffset = 0;
	*compressedTextPtr = (char)0;
	for (auto& character : *textPtr) {
		string code = characterCodes.find(character)->second;
		writeCompressed(code);
	}
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

void Compressor::writeCompressed(string code) {
	for (char &charCode : code) {
		writeCompressed(charCode - '0'); //setting '0' to 0 and '1' to 1
	}
}

void Compressor::writeCompressed(char bit) { //unsigned char because signed has left bit as a sign bit
	string& compressedTextRef = *compressedTextPtr;
    char maxOffset = 7;
	char discharge = (bit << (maxOffset -  byteOffset));
	compressedTextRef[byteNumber] |= discharge; 
	if (byteOffset == 7) {
		compressedTextRef.push_back((char)0);
		++byteNumber;
		byteOffset = -1;
	}
	++byteOffset;
}