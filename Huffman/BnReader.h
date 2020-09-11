#pragma once
#include <iostream>
#include <fstream>
#include <fstream>
#include "HelpfulMethods.h"

class BnReader {
public:
	BnReader();
	~BnReader();

	void startReading(std::string filename);
	void readBlock();
	void readTextSize();

	std::string* getBlockPtr();
	std::uint32_t getTextSize();
	bool fileIsEmpty();
private:
	std::string* blockPtr;
	std::uint32_t textSize;
	std::ifstream* filePtr;
	bool fileEmptiness;
};

