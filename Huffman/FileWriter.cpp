#include "FileWriter.h"
#include "HelpfulMethods.h"
using namespace std;

FileWriter::FileWriter() {}

FileWriter::~FileWriter() {
	safeDelete(filePtr);
}

void FileWriter::openBinaryFile(std::string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	isOpened = filePtr->is_open();
}

void FileWriter::writeString(std::string* stringPtr) {
	uint32_t bytesAmount = stringPtr->size();
	char* ptr = &((*stringPtr)[0]);
	filePtr->write(ptr, bytesAmount);
}

void FileWriter::writeEmptyFile() {
	filePtr->close();
}

bool FileWriter::fileIsOpened() const {
	return isOpened;
}
