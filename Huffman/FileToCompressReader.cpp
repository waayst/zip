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
	while (!filePtr->eof()) {
		filePtr->read(&character, sizeof character);
		textPtr->push_back(character);
	}
	fileToCompressDataPtr = new FileToCompressData(textPtr);
}

FileData * FileToCompressReader::getReadData() {
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
