#include "CompressedFileReader.h"
using namespace std;

CompressedFileReader::CompressedFileReader() {}

string* CompressedFileReader::getBlockPtr() {
	return blockPtr;
}


bool CompressedFileReader::fileIsOpened() {
	return isOpened;
}

void CompressedFileReader::startReading(std::string filename) {
	safeDelete(filePtr);
	filePtr = new ifstream(filename, ios::binary | ios::in);
	if (!filePtr->is_open()) {
		isOpened = false;
		return;
	} else if (filePtr->peek() != EOF) {
		isEmpty = false;
		return;
	}
}

bool CompressedFileReader::fileIsEmpty() {
	return isEmpty;
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

CompressedFileReader::~CompressedFileReader() {
	safeDelete(filePtr);
}