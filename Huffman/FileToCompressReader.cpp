#include "FileToCompressReader.h"
#include "HelpfulMethods.h"
#include <iostream>
using namespace std;

FileToCompressReader::FileToCompressReader()  {}

FileToCompressReader::~FileToCompressReader() {
	safeDelete(fileToCompressDataPtr);
}

void FileToCompressReader::read() {
	auto textPtr = new string{};
	char character;
	filePtr->read(&character, sizeof character);
	while (!filePtr->eof()) {
		textPtr->push_back(character);
		filePtr->read(&character, sizeof character);
	}
	fileToCompressDataPtr = new FileToCompressData(textPtr);
}

FileData * FileToCompressReader::getReadData() const {
	return fileToCompressDataPtr;
}

FileToCompressData::FileToCompressData() {}

FileToCompressData::FileToCompressData(string* textPtr)
				   :textPtr(textPtr) {}

FileToCompressData::~FileToCompressData() {
	safeDelete(textPtr);
}

string * FileToCompressData::getTextPtr() const {
	return textPtr;
}

void FileToCompressData::setTextPtr(string* newTextPtr) {
	textPtr = newTextPtr;
}