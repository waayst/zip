#pragma once
#include <iostream>
#include "BNode.h"

/*
TreeBuilder buildes codes tree from
characters is dfs order and dfs Code.
*/
class TreeBuilder {
public:
	TreeBuilder();
	TreeBuilder(std::string* charactersDfsOrderPtr,
				std::string* dfsCodePtr);

	void setCharactersDfsOrderPtr(std::string* newCharacterDfsOrderPtr);
	void setDfsCodePtr(std::string* newDfsCodePtr);

	void buildTree();
	BNode* getCodesTree();
	~TreeBuilder();

private:

	int leaf;
	void doStep(BNode* &curNode);
	char prevCode;
	char curCode;

	BNode* codesTree;
	std::string* charactersDfsOrderPtr;
	std::string* dfsCodePtr;
};

