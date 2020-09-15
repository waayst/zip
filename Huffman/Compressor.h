#pragma once
#include <iostream>
#include <map>
#include "BNode.h"
#include "FileToCompressReader.h"
/*
 * Compressor compressed text using huffman codes tree.
 * 
 * Compressor gets:
 * 1. Text to compress.
 * 2. Huffman codes tree.
 * 
 * Brief description of Compressor work:
 * 1. Dfs tree to get characters codes.
 * 2. Write each character in text as a code, compressed from bytes to bits.
 * 
 * maybe make it compress dfs code too, 
 * maybe use bitset.
 */

class Compressor {
public:
	Compressor();
	Compressor           (std::string* textPtr, BNode* codesTree);
	Compressor           (FileData* fileDataPtr, BNode* codesTree);
	~Compressor();

	void compress();

	std::string* getCharactersDfsOrderPtr();
	std::string* getDfsCodePtr();
	std::uint32_t getTextSize();
	std::string* getCompressedTextPtr();

	void setCodesTree   (BNode* newCodesTree);
	void setTextPtr     (std::string* newTextPtr);

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

