#pragma once
#include <iostream>
#include "BNode.h"
/*
Class Decoder decodes compressed text.

Decoder gets:
1. Not compressed text size.
2. String of compressed text.
3. Huffman codes tree.

Brief description of Decoder work:
1. Read bit (Start at tree root).
2. Make a step in a tree according to bit, moving left if 0, right if 1.
3. If got in a leaf:
	1. Read leaf character
	2. Write it to text 
	3. Start with tree root 
4. go to 1.
*/

class Decoder {
public:
	Decoder();
	Decoder      (std::uint32_t textSize,
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