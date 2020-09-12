#include "CompressedDataWriter.h"
#include "HelpfulMethods.h"
using namespace std;

CompressedDataWriter::CompressedDataWriter() {}

CompressedDataWriter::CompressedDataWriter(
				  string* charactersDfsOrderPtr,
	              string* dfsCodePtr,
		          uint32_t textSize,
	              string* compressedTextPtr)
	             :charactersDfsOrderPtr(charactersDfsOrderPtr), 
	              dfsCodePtr(dfsCodePtr),
	              textSize(textSize),
	              compressedTextPtr(compressedTextPtr) {}

void CompressedDataWriter::write(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	writeCharacters();
	writeDfsCode();
	writeTextSize();
	writeCompressedText();
	safeDelete(filePtr);
}

void CompressedDataWriter::writeEmptyFile(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	safeDelete(filePtr);
}

void CompressedDataWriter::writeTextSize() {
	filePtr->write((char*)&textSize, sizeof(textSize));
}

void CompressedDataWriter::writeString(std::string* stringPtr) {
	uint32_t bytesAmount = stringPtr->size();
	filePtr->write((char*)&bytesAmount, sizeof(bytesAmount));
	char* ptr = &((*stringPtr)[0]);
	filePtr->write(ptr, bytesAmount);
}

void CompressedDataWriter::writeCharacters() {
	writeString(charactersDfsOrderPtr);
}

void CompressedDataWriter::writeDfsCode() {
	writeString(dfsCodePtr);
}

void CompressedDataWriter::writeCompressedText() {
	writeString(compressedTextPtr);
}

CompressedDataWriter::~CompressedDataWriter() {
	safeDelete(filePtr);
}