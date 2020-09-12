#include "HuffmanProcessor.h"
#include "HelpfulMethods.h"
using namespace std;

HuffmanProcessor::HuffmanProcessor():
	textPtr(nullptr), codesTree(nullptr) {}

HuffmanProcessor::HuffmanProcessor(std::string* textPtr):
    textPtr(textPtr), codesTree(nullptr) {}

BNode* HuffmanProcessor::getCodesTree() {
	return codesTree;
}

std::string* HuffmanProcessor::getTextPtr() {
	return textPtr;
}

void HuffmanProcessor::setText(string* newTextPtr) {
	textPtr = newTextPtr;
}

void HuffmanProcessor::createLatenciesMap() {
	string& textRef = *textPtr;
	for (char character : textRef) {
		auto it = latenciesMap.find(character);
		if (it == latenciesMap.end()) {
			latenciesMap.insert({ character, 1 });
		} else {
			++(it->second);
		}
	}
}

void HuffmanProcessor::createLatenciesList() {
	for (auto it = latenciesMap.begin();
		it != latenciesMap.end(); ++it) {
		latenciesList.push_back({ new BNode(it->first), it->second });
	}
}

HuffmanProcessor::latenciesListIterator HuffmanProcessor::getMinimalLatencyIterator() {
	auto minNodeIterator = latenciesList.begin();
	int minLatency = latenciesList.begin()->second;
		for (auto it = latenciesList.begin();
			it != latenciesList.end(); ++it) {
		auto curLatency = it->second;
		if (minLatency > curLatency) {
			minNodeIterator = it;
			minLatency = curLatency;
		}
	}
	return minNodeIterator;
}

pair<BNode*, int> HuffmanProcessor::extractMinNode() {
	auto it = getMinimalLatencyIterator();
	auto minNode = *it;
	latenciesList.erase(it);
	return minNode;
}

void HuffmanProcessor::createCodeTree() {
	while (latenciesList.size() > 1) {
		auto firstNode = extractMinNode();
		auto secondNode = extractMinNode();
		BNode* newParentNode = new BNode(firstNode.first, secondNode.first);
		int summaryLatency = firstNode.second + firstNode.second;
		latenciesList.push_back({newParentNode , summaryLatency});
	}
	codesTree = latenciesList.front().first;
	latenciesList = {};
}

void HuffmanProcessor::process() {
	createLatenciesMap();
	createLatenciesList();
	createCodeTree();
}

HuffmanProcessor::~HuffmanProcessor() {
	safeDelete(codesTree);
}