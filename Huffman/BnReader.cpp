#include "BnReader.h"
using namespace std;

BnReader::BnReader(): blockPtr(nullptr),
					  filePtr(nullptr),
					  fileEmptiness(true) {}

string* BnReader::getBlockPtr() {
	return blockPtr;
}

void BnReader::startReading(std::string filename) {
	safeDelete(filePtr);
	filePtr = new ifstream(filename, ios::binary | ios::in);
	if (filePtr->peek() != EOF) {
		fileEmptiness = false;
	}
}

bool BnReader::fileIsEmpty() {
	return fileEmptiness;
}

void BnReader::readBlock() {
	uint32_t bytesAmount;
	filePtr->read((char*)&bytesAmount, sizeof(bytesAmount));
	blockPtr = new string(bytesAmount, '0');
	char* ptr = &((*blockPtr)[0]);
	filePtr->read(ptr, bytesAmount);
}

void BnReader::readTextSize() {
	filePtr->read((char*)&textSize, sizeof(textSize));
}

uint32_t BnReader::getTextSize() {
	return textSize;
}

BnReader::~BnReader() {
	safeDelete(filePtr);
}