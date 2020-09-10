#pragma once
#include <iostream>
#include <map>
#include <list>
#include "BNode.h"

class HuffmanProcessor {
public:
	HuffmanProcessor();
	HuffmanProcessor(std::string* textPtr);
	~HuffmanProcessor();

	void setText(std::string* newTextPtr);
	std::string* getTextPtr();
	BNode* getCodesTree();

	void process();

//private:
	using latenciesListIterator = std::list<std::pair<BNode*, int>>::iterator;

	void createLatenciesMap();
	void createLatenciesList();
	void createCodeTree();

	latenciesListIterator getMinimalLatencyIterator();
	std::pair<BNode*, int> extractMinNode();

	std::string* textPtr;
	std::map<char, int> latenciesMap;
	std::list<std::pair<BNode*, int>> latenciesList;
	BNode* codesTree;
};

