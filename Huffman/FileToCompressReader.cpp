#include "FileToCompressReader.h"
#
using namespace std;

FileToCompressReader::FileToCompressReader()  {}

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

FileToCompressReader::~FileToCompressReader() {
	safeDelete(textPtr);
}