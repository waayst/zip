#pragma once
#include "BNode.h"
#include <iostream>
#include <map>
/*
Compressor gets text and codes tree, 
produces string data: characters in dfs order, dfs Code, compressed text.

maybe make it compress dfs code too...
*/

class Compressor {
public:
	Compressor();
	Compressor           (std::string* textPtr, BNode* codesTree);
	~Compressor();

	void compress();

	void setCodesTree(BNode* newCodesTree);
	void setTextPtr(std::string* newTextPtr);

	std::string* getCharactersDfsOrderPtr();
	std::string* getDfsCodePtr();
	std::string* getCompressedTextPtr();
private:
	void createDfsInfo();
	void createCompressedText();

	void dfsTree        (BNode* node, std::string curCode);
	void writeCompressed(std::string code);
	void writeCompressed(char bit);

	BNode* codesTree;
	std::string* textPtr;

	int byteNumber;
	int byteOffset;
	std::map<char, std::string> characterCodes;

	std::string* charactersDfsOrderPtr;
	std::string* dfsCodePtr;
	std::string* compressedTextPtr;
};

