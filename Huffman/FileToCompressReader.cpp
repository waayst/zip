#include "FileToCompressReader.h"
#
using namespace std;

FileToCompressReader::FileToCompressReader()  {}

void FileToCompressReader::read(std::string filename) {
	ifstream file(filename, ios::binary | ios::in);
	textPtr = new string{};
	char character;
	if (!file.is_open()) {
		isOpened = false;
		return;
	}
	if (file.peek() == EOF) {
		isEmpty = true;
		return;
	}
	while (!file.eof()) {
		file.read(&character, sizeof character);
		textPtr->push_back(character);
	}
}

string* FileToCompressReader::getTextPtr() {
	return this->textPtr;
}

bool FileToCompressReader::fileIsOpened() {
	return isOpened;
}

bool FileToCompressReader::fileIsEmpty() {
	return isEmpty;
}

FileToCompressReader::~FileToCompressReader() {
	safeDelete(textPtr);
}