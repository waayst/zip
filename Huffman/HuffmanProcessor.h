#pragma once
#include <iostream>
#include <map>
#include <list>
#include "BNode.h"
/*
 * Class HuffmanProcessor processed huffman algorithm at giving text.
 *
 * HuffmanProcessor gets text to work with.
 *
 * Brief description of HuffmanProcessor work:
 * 1. Creates map of character and its latency in next.
 * 2. Builde a tree by steps:
 * 2.1 Find two nodes with minimal latencies(at first step, all nodes are characters with their latencies)
 * 2.2 Substitute them with parent with summary latency. 
 */

class HuffmanProcessor {
public:
	HuffmanProcessor();
	HuffmanProcessor(std::string* textPtr);
	~HuffmanProcessor();

	void process();

	std::string* getTextPtr();
	BNode* getCodesTree();
	void setText    (std::string* newTextPtr);

private:
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

