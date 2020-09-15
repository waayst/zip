#include "BNode.h"
#include "HelpfulMethods.h"

BNode::BNode() {}

BNode::BNode(char character): character(character) {}

BNode::BNode(BNode* left, BNode* right)
	  :left(left), right(right) {}

BNode::BNode(BNode* left, BNode* right,
	         BNode* parent)
	  :left(left), right(right), parent(parent) {}

BNode::~BNode() {
	safeDelete(left);
	safeDelete(right);
}

BNode* BNode::getLeft() const {
	return left;
}

BNode* BNode::getRight() const {
	return right;
}

BNode* BNode::getParent() const {
	return parent;
}

char BNode::getCharacter() const {
	return character;
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

void BNode::setCharacter(char newCharacter) {
	character = newCharacter;
}

bool BNode::isALeaf() const {
	return (left == nullptr && right == nullptr);
}