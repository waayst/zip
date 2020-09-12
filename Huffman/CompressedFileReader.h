#pragma once
#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "HelpfulMethods.h"
/* 
CompressedFileReader reads compressed file by blocks
those consist of amount of bytes and bytes themselves.
*/

class CompressedFileReader : public FileReader {
public:
	CompressedFileReader();

	std::string* readAndGetBlockPtr();
	std::uint32_t readAndGetTextSize();

	std::string* getBlockPtr();
	std::uint32_t getTextSize();

private:
	void readBlock();
	void readSize();

	std::string* blockPtr = nullptr;
	std::uint32_t textSize;
};