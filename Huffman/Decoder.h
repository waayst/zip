#pragma once
#include <iostream>
#include "BNode.h"
#include "HelpfulMethods.h"

/*
Decoder decodes compressed text using built codes tree, and knowing text size. 
*/

class Decoder {
public:
	Decoder();
	Decoder(std::uint32_t textSize,
		    std::string* compressedTextPtr, BNode* codesTree);
	
	std::string* getTextPtr();
	
	void decode();

	~Decoder();
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

