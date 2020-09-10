#include "BnWriter.h"

using namespace std;

BnWriter::BnWriter(): filePtr(nullptr),
charactersDfsOrderPtr(nullptr),
dfsCodePtr(nullptr),
compressedTextPtr(nullptr) {}

BnWriter::BnWriter(std::string* charactersDfsOrderPtr,
	std::string* dfsCodePtr,
	std::string* compressedTextPtr) :
	filePtr(nullptr),
	charactersDfsOrderPtr(charactersDfsOrderPtr),
	dfsCodePtr(dfsCodePtr),
	compressedTextPtr(compressedTextPtr) {}

void BnWriter::write(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	writeCharacters();
	writeDfsCode();
	writeCompressedText();
	safeDelete(filePtr);
}

void BnWriter::writeEmptyFile(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	safeDelete(filePtr);
}

void BnWriter::writeString(std::string* stringPtr) {
	uint32_t bytesAmount = stringPtr->size();
	filePtr->write((char*)&bytesAmount, sizeof(bytesAmount));
	char* ptr = &((*charactersDfsOrderPtr)[0]);
	filePtr->write(ptr, bytesAmount);
}

void BnWriter::writeCharacters() {
	writeString(charactersDfsOrderPtr);
}

void BnWriter::writeDfsCode() {
	writeString(dfsCodePtr);
}

void BnWriter::writeCompressedText() {
	writeString(compressedTextPtr);
}

BnWriter::~BnWriter() {
	safeDelete(filePtr);
}