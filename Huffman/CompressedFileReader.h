#pragma once
#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "HelpfulMethods.h"

/* 
BnReader reads file in blocks, according to Compressor compressed them and BnWriter wrote them.

TextReader and BnReader will be rewritten having commom base.
*/

class CompressedFileReader : public FileReader {
public:
	CompressedFileReader();

	void readBlock();
	void readTextSize();

	std::string* getBlockPtr();
	std::uint32_t getTextSize();

private:
	std::string* blockPtr = nullptr;
	std::uint32_t textSize;
};

