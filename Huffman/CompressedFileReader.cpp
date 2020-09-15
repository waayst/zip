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

FileData * CompressedFileReader::getReadData() {
	return compressedFileDataPtr;
}

void CompressedFileReader::readCharactersDfsOrder() {
	compressedFileDataPtr->setCharactersDfsOrderPtr(readBlockAndGetDataPtr());
}

void CompressedFileReader::readDfsCode() {
	compressedFileDataPtr->setDfsCodePtr(readBlockAndGetDataPtr());
}

void CompressedFileReader::readTextSize() {
	readSize();
	compressedFileDataPtr->setTextSize(getDataSize());
}

void CompressedFileReader::readCompressedText() {
	compressedFileDataPtr->setCompressedTextPtr(readBlockAndGetDataPtr());
}

string* CompressedFileReader::readBlockAndGetDataPtr() {
	readBlock();
	return getDataPtr();
}

string* CompressedFileReader::getDataPtr() const {
	return dataPtr;
}

uint32_t CompressedFileReader::getDataSize() const {
	return dataSize;
}

void CompressedFileReader::readBlock() {
	readSize();
	dataPtr = new string(dataSize, '0');
	char* ptr = &((*dataPtr)[0]);
	filePtr->read(ptr, dataSize);
}

void CompressedFileReader::readSize() {
	filePtr->read((char*)&dataSize, sizeof(dataSize));
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
