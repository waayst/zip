#include "CompressedFileReader.h"
using namespace std;

CompressedFileReader::CompressedFileReader() {}

string* CompressedFileReader::getBlockPtr() {
	return blockPtr;
}

void CompressedFileReader::readBlock() {
	uint32_t bytesAmount;
	filePtr->read((char*)&bytesAmount, sizeof(bytesAmount));
	blockPtr = new string(bytesAmount, '0');
	char* ptr = &((*blockPtr)[0]);
	filePtr->read(ptr, bytesAmount);
}

void CompressedFileReader::readTextSize() {
	filePtr->read((char*)&textSize, sizeof(textSize));
}

uint32_t CompressedFileReader::getTextSize() {
	return textSize;
}
