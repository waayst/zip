#pragma once
#include <iostream>
#include <fstream>
#include <fstream>
#include "HelpfulMethods.h"

/* 
BnReader reads file in blocks, according to Compressor compressed them and BnWriter wrote them.

TextReader and BnReader will be rewritten having commom base.
*/

class BnReader {
public:
	BnReader();
	~BnReader();

	void startReading(std::string filename);
	void readBlock();
	void readTextSize();

	std::string* getBlockPtr();
	std::uint32_t getTextSize();
	bool fileIsOpened();
	bool fileIsEmpty();
private:
	std::string* blockPtr = nullptr;
	std::uint32_t textSize;
	std::ifstream* filePtr = nullptr;
	bool fileOpen = true;
	bool fileEmptiness = false;
};

