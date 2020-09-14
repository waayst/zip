#pragma once
#include <iostream>
#include "BNode.h"
/*
Class TreeBuilder builds codes tree from some data.

TreeBuilder gets:
1. String of characters in dfs order of Huffman codes tree.
2. String of code of dfs of Huffman codes.

Brief description of TreeBuilder work:
1. Read code of dfs order.
2. If it is 0 add up left node to current on move on it
   else set up current node as a leaf, giving it a character, 
   add up right node to least parent of current node without right node and start with it. 
 3. Go to 1.
*/

class TreeBuilder {
public:
	TreeBuilder();
	TreeBuilder                   (std::string* charactersDfsOrderPtr,
				                   std::string* dfsCodePtr);
	~TreeBuilder();

	void buildTree();

	BNode* getCodesTree();
	void setCharactersDfsOrderPtr(std::string* newCharacterDfsOrderPtr);
	void setDfsCodePtr           (std::string* newDfsCodePtr);

private:

	int leaf;
	void doStep                  (BNode* &curNode);
	char prevCode;
	char curCode;

	BNode* codesTree;
	std::string* charactersDfsOrderPtr;
	std::string* dfsCodePtr;
};