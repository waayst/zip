#include "BNode.h"

BNode::BNode(): left(nullptr), right(nullptr) {}

BNode::BNode(char character): character(character),
		left(nullptr), right(nullptr) {}

BNode::BNode(BNode* left, BNode* right):
	left(left), right(right) {}

BNode* BNode::getLeft() {
	return left;
}

BNode* BNode::getRight() {
	return right;
}

bool BNode::isALeaf() {
	return (left == nullptr && right == nullptr);
}

char BNode::getCharacter() {
	return character;
}

BNode::~BNode() {
	safeDelete(left);
	safeDelete(right);
}