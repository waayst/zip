#pragma once
#include "BNode.h"
#include <iostream>
#include "HelpfulMethods.h"

class Decoder {
public:
	Decoder();
	Decoder(std::uint32_t textSize,
		    std::string* compressedTextPtr, BNode* codesTree);
	
	std::string* getTextPtr();
	void decode();
	~Decoder();
//private:

	char getCode();
	void moveNode(char bit);
	int curByte;
	int offset;

	std::uint32_t textSize;
	std::string* compressedTextPtr;
	std::string* textPtr;
	BNode* codesTree;	
	BNode* curNode;
};

