#include "TreeBuilder.h"
using namespace std;

TreeBuilder::TreeBuilder() : codesTree(nullptr),
				charactersDfsOrderPtr(nullptr),
				dfsCodePtr(nullptr) {}

TreeBuilder::TreeBuilder(string* charactersDfsOrderPtr,
						 string* dfsCodePtr) :
				codesTree(nullptr),
				charactersDfsOrderPtr(charactersDfsOrderPtr),
				dfsCodePtr(dfsCodePtr) {}

void TreeBuilder::setCharactersDfsOrderPtr(std::string* newCharactersDfsOrderPtr) {
	charactersDfsOrderPtr = newCharactersDfsOrderPtr;
}

void TreeBuilder::setDfsCodePtr(std::string* newDfsCodePtr) {
	dfsCodePtr = newDfsCodePtr;
}

BNode* TreeBuilder::getCodesTree() {
	return codesTree;
}

TreeBuilder::~TreeBuilder() {
	safeDelete(codesTree);
}

 void TreeBuilder::doStep(BNode* &curNode) {
	auto& charactersRef = *charactersDfsOrderPtr;

	if (curCode == '0') {
		curNode->setLeft(new BNode());
		auto newCurNode = curNode->getLeft();
		newCurNode->setParent(curNode);
		curNode = newCurNode;
	} else {
		curNode->setCharacter(charactersRef[leaf++]);
		auto parent = curNode->getParent();
		while (parent->getRight() != nullptr) {
			curNode = curNode->getParent();
			parent = curNode->getParent();
		}
		parent->setRight(new BNode);
		curNode = parent->getRight();
		curNode->setParent(parent);
	}
	prevCode = curCode;
}

 static void dfsTree(BNode* node) { //debug
	 if (node->getLeft() != nullptr) {
		 //cout << '0';
		 dfsTree(node->getLeft());
	 }
	 if (node->getRight() != nullptr) {
		 //cout << '1';
		 dfsTree(node->getRight());
	 }
 }

void TreeBuilder::buildTree() {
	auto& dfsRef = *dfsCodePtr;
	auto& charactersRef = *charactersDfsOrderPtr;
	leaf = 0;
	prevCode = '2';
	curCode = '2';
	codesTree = new BNode();
	BNode* curNode = codesTree;
	for (auto i = 0; i < dfsRef.size(); ++i) {
		curCode = dfsRef[i];
		doStep(curNode);
	}
	curNode->setCharacter(charactersRef[leaf]);
	//dfsTree(codesTree);
}

