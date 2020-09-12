#pragma once
#include <iostream>
#include "BNode.h"
/*
TreeBuilder gets characters is dfs order and dfs Code
buildes codes tree from them.
*/

class TreeBuilder {
public:
	TreeBuilder();
	TreeBuilder                   (std::string* charactersDfsOrderPtr,
				                   std::string* dfsCodePtr);
	~TreeBuilder();

	void buildTree();

	void setCharactersDfsOrderPtr(std::string* newCharacterDfsOrderPtr);
	void setDfsCodePtr           (std::string* newDfsCodePtr);
	BNode* getCodesTree();

private:

	int leaf;
	void doStep                  (BNode* &curNode);
	char prevCode;
	char curCode;

	BNode* codesTree;
	std::string* charactersDfsOrderPtr;
	std::string* dfsCodePtr;
};