#include "FileReader.h"
#include "HelpfulMethods.h"
using namespace std;

FileReader::FileReader() {}

FileReader::~FileReader() {
	safeDelete(filePtr);
}

void FileReader::openBinaryFile(string filename) {
	safeDelete(filePtr);
	filePtr = new ifstream(filename, ios::binary | ios::in);
	isOpened = filePtr->is_open();
	if (isOpened) {
		isEmpty = (filePtr->peek() == EOF);
	}
}

bool FileReader::fileIsOpened() const {
	return isOpened;
}

bool FileReader::fileIsEmpty() const {
	return isEmpty;
}