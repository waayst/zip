#pragma once
/*
 * Class BNode is a binary Node used in creating huffman tree of codes.
 */

class BNode {
public:
	BNode();
	BNode            (char character);
	BNode            (BNode* left, BNode* right);
	BNode            (BNode* left, BNode* right, BNode* parent);
	~BNode();

	BNode* getLeft() const;
	BNode* getRight() const;
	BNode* getParent() const;
	char getCharacter() const;

	void setLeft     (BNode*  newLeft);
	void setRight    (BNode* newRight);
	void setParent   (BNode* newParent);
	void setCharacter(char newCharacter);
	
	bool isALeaf() const;
	
private:
	BNode* left = nullptr;
	BNode* right = nullptr;
	BNode* parent = nullptr;
	char character;
};