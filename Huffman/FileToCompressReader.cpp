#include "FileToCompressReader.h"
#include "HelpfulMethods.h"
#include <iostream>
using namespace std;

FileToCompressReader::FileToCompressReader()  {}

FileToCompressReader::~FileToCompressReader() {
	safeDelete(textPtr);
}

void FileToCompressReader::read(std::string filename) {
	textPtr = new string{};
	char character;
	while (!filePtr->eof()) {
		filePtr->read(&character, sizeof character);
		textPtr->push_back(character);
	}
}

string* FileToCompressReader::getTextPtr() {
	return this->textPtr;
}