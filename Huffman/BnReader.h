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

	std::string* getBlockPtr();
	bool fileIsEmpty();
private:
	std::string* blockPtr;
	std::ifstream* filePtr;
	bool fileEmptiness;
};

