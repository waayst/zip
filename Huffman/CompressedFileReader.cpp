#include "CompressedFileReader.h"
using namespace std;

CompressedFileReader::CompressedFileReader() {}

CompressedFileReader::~CompressedFileReader() {
	safeDelete(compressedFileDataPtr);
}

void CompressedFileReader::read() {
	compressedFileDataPtr = new CompressedFileData{};
	readCharactersDfsOrder();
	readDfsCode();
	readTextSize();
	readCompressedText();
}

FileData * CompressedFileReader::getReadData() const {
	return compressedFileDataPtr;
}

void CompressedFileReader::readCharactersDfsOrder() {
	compressedFileDataPtr->setCharactersDfsOrderPtr(readBlockAndGetArrayPtr());
}

void CompressedFileReader::readDfsCode() {
	compressedFileDataPtr->setDfsCodePtr(readBlockAndGetArrayPtr());
}

void CompressedFileReader::readTextSize() {
	readSize();
	compressedFileDataPtr->setTextSize(getTextSize());
}

void CompressedFileReader::readCompressedText() {
	compressedFileDataPtr->setCompressedTextPtr(readBlockAndGetArrayPtr());
}

string* CompressedFileReader::readBlockAndGetArrayPtr() {
	readBlock();
	return getArrayPtr();
}

string* CompressedFileReader::getArrayPtr() const {
	return arrayPtr;
}

uint32_t CompressedFileReader::getTextSize() const {
	return arraySize;
}

void CompressedFileReader::readBlock() {
	readSize();
	arrayPtr = new string(arraySize, '0');
	char* ptr = &((*arrayPtr)[0]);
	filePtr->read(ptr, arraySize);
}

void CompressedFileReader::readSize() {
	filePtr->read((char*)&arraySize, sizeof(arraySize));
}

CompressedFileData::CompressedFileData() {}

string * CompressedFileData::getCharactersDfsOrderPtr() const {
	return charactersDfsOrderPtr;
}

string * CompressedFileData::getDfsCodePtr() const {
	return dfsCodePtr;
}

uint32_t CompressedFileData::getTextSize() const {
	return textSize;
}

string * CompressedFileData::getCompressedTextPtr() const {
	return compressedTextPtr;
}

void CompressedFileData::setCharactersDfsOrderPtr(string * newCharactersDfsOrderPtr) {
	charactersDfsOrderPtr = newCharactersDfsOrderPtr;
}

void CompressedFileData::setDfsCodePtr(string * newDfsCodePtr) {
	dfsCodePtr = newDfsCodePtr;
}

void CompressedFileData::setTextSize(uint32_t newTextSize) {
	textSize = newTextSize;
}

void CompressedFileData::setCompressedTextPtr(string * newCompressedTextPtr) {
	compressedTextPtr = newCompressedTextPtr;
}
