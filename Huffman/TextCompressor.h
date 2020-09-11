#pragma once
#include "BNode.h"
#include <iostream>
#include <map>

/*
TextCompressor compresses text using codes tree,
also storaging noncompressed text size.
*/

class TextCompressor {
public:
	TextCompressor();
	TextCompressor(std::string* textPtr, BNode* codesTree);
	void setCodesTree(BNode* newCodesTree);
	void setTextPtr(std::string* newTextPtr);
	
	std::string* getCompressedTextPtr();
	std::string* getDfsCodePtr();
	std::string* getCharactersDfsOrderPtr();

	void compress();
	~TextCompressor();
private:
	void createDfsInfo();
	void createCompressedText();

	void dfsTree(BNode* node, std::string curCode);
	void writeCompressed(unsigned char bit);
	void writeCompressed(std::string code);
	int byteNumber;
	int byteOffset;

	std::string* textPtr;
	BNode* codesTree;
	std::map<char, std::string> characterCodes;

	std::string* charactersDfsOrderPtr;
	std::string* dfsCodePtr;
	std::string* compressedTextPtr;
};

