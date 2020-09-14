#include "CompressedFileReader.h"
using namespace std;

CompressedFileReader::CompressedFileReader() {}

void CompressedFileReader::read() {
	readCharactersDfsOrder();
	readDfsCode();
	readTextSize();
	readCompressedText();
}

string * CompressedFileReader::getCharactersDfsOrderPtr() const {
	return charactersDfsOrderPtr;
}

string * CompressedFileReader::getDfsCodePtr() const {
	return dfsCodePtr;
}

uint32_t CompressedFileReader::getTextSize() const {
	return textSize;
}

string * CompressedFileReader::getCompressedTextPtr() const {
	return compressedTextPtr;
}

void CompressedFileReader::readCharactersDfsOrder() {
	charactersDfsOrderPtr = readBlockAndGetDataPtr();
}

void CompressedFileReader::readDfsCode() {
	dfsCodePtr = readBlockAndGetDataPtr();
}

void CompressedFileReader::readTextSize() {
	readSize();
	textSize = getDataSize();
}

void CompressedFileReader::readCompressedText() {
	compressedTextPtr = readBlockAndGetDataPtr();
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