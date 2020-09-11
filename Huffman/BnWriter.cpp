#include "BnWriter.h"
#include "HelpfulMethods.h"
using namespace std;

BnWriter::BnWriter() {}

BnWriter::BnWriter(string* charactersDfsOrderPtr,
	      string* dfsCodePtr,
		  uint32_t textSize,
	      string* compressedTextPtr)
	     :charactersDfsOrderPtr(charactersDfsOrderPtr), 
	      dfsCodePtr(dfsCodePtr),
	      textSize(textSize),
	      compressedTextPtr(compressedTextPtr) {}

void BnWriter::write(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	writeCharacters();
	writeDfsCode();
	writeTextSize();
	writeCompressedText();
	safeDelete(filePtr);
}

void BnWriter::writeEmptyFile(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	safeDelete(filePtr);
}

void BnWriter::writeTextSize() {
	filePtr->write((char*)&textSize, sizeof(textSize));
}


void BnWriter::writeString(std::string* stringPtr) {
	uint32_t bytesAmount = stringPtr->size();
	filePtr->write((char*)&bytesAmount, sizeof(bytesAmount));
	char* ptr = &((*stringPtr)[0]);
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