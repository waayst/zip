#pragma once
#include "HelpfulMethods.h"

/*
BNode is a binary Node used in creating huffman tree of codes.
*/

class BNode {
public:
	BNode();
	BNode(char character);
	BNode(BNode* left, BNode* right);
	BNode(BNode* left, BNode* right, BNode* parent);
	
	BNode* getLeft();
	BNode* getRight();
	BNode* getParent();
	char getCharacter();

	void setLeft(BNode*  newLeft);
	void setRight(BNode* newRight);
	void setParent(BNode* newParent);
	void setCharacter(char newCharacter);
	
	bool isALeaf();
	
	~BNode();

private:
	char character;
	BNode* left = nullptr;
	BNode* right = nullptr;
	BNode* parent = nullptr;
};

