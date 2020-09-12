#include "CompressedFileReader.h"
using namespace std;

CompressedFileReader::CompressedFileReader() {}

string* CompressedFileReader::readAndGetBlockPtr() {
	readBlock();
	return getBlockPtr();
}

uint32_t CompressedFileReader::readAndGetTextSize() {
	readSize();
	return getTextSize();
}

string* CompressedFileReader::getBlockPtr() {
	return blockPtr;
}

uint32_t CompressedFileReader::getTextSize() {
	return textSize;
}

void CompressedFileReader::readBlock() {
	readSize();
	blockPtr = new string(textSize, '0');
	char* ptr = &((*blockPtr)[0]);
	filePtr->read(ptr, textSize);
}

void CompressedFileReader::readSize() {
	filePtr->read((char*)&textSize, sizeof(textSize));
}