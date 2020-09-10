#pragma once
#include "HelpfulMethods.h"

class BNode {
public:
	BNode();
	BNode(char symbol);
	BNode(BNode* left, BNode* right);
	BNode* getLeft();
	BNode* getRight();
	char getCharacter();
	bool isALeaf();
	~BNode();

private:
	char character;
	BNode* left;
	BNode* right;
};

