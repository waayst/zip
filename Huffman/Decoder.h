#pragma once
#include <iostream>
#include "BNode.h"
/*
Decoder gets not compressed text size, 
bytes to decode, and codes tree than decodes bytes 
and saves result.
*/

class Decoder {
public:
	Decoder();
	Decoder(std::uint32_t textSize,
		    std::string* compressedTextPtr, BNode* codesTree);
	~Decoder();

	void decode();

	std::string* getTextPtr();

private:

	char getCode();
	void moveNode(char bit);
	int curByte;
	int offset;

	std::uint32_t textSize;
	std::string* compressedTextPtr = nullptr;
	std::string* textPtr = nullptr;
	BNode* codesTree = nullptr;	
	BNode* curNode = nullptr;
};