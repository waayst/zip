#include "BNode.h"

BNode::BNode() {}

BNode::BNode(char character): character(character) {}

BNode::BNode(BNode* left, BNode* right):
	left(left), right(right) {}

BNode::BNode(BNode* left, BNode* right, BNode* parent) :
	left(left), right(right), parent(parent) {}

BNode* BNode::getLeft() {
	return left;
}

BNode* BNode::getRight() {
	return right;
}

BNode* BNode::getParent() {
	return parent;
}

void BNode::setLeft(BNode* newLeft) {
	left = newLeft;
}

void BNode::setRight(BNode* newRight) {
	right = newRight;
}

void BNode::setParent(BNode* newParent) {
	parent = newParent;
}

bool BNode::isALeaf() {
	return (left == nullptr && right == nullptr);
}

char BNode::getCharacter() {
	return character;
}

void BNode::setCharacter(char newCharacter) {
	character = newCharacter;
}
BNode::~BNode() {
	safeDelete(left);
	safeDelete(right);
}