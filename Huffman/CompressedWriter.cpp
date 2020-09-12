#include "CompressedWriter.h"
#include "HelpfulMethods.h"
using namespace std;

CompressedWriter::CompressedWriter() {}

CompressedWriter::CompressedWriter(
				  string* charactersDfsOrderPtr,
	              string* dfsCodePtr,
		          uint32_t textSize,
	              string* compressedTextPtr)
	             :charactersDfsOrderPtr(charactersDfsOrderPtr), 
	              dfsCodePtr(dfsCodePtr),
	              textSize(textSize),
	              compressedTextPtr(compressedTextPtr) {}

void CompressedWriter::write(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	writeCharacters();
	writeDfsCode();
	writeTextSize();
	writeCompressedText();
	safeDelete(filePtr);
}

void CompressedWriter::writeEmptyFile(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	safeDelete(filePtr);
}

void CompressedWriter::writeTextSize() {
	filePtr->write((char*)&textSize, sizeof(textSize));
}

void CompressedWriter::writeString(std::string* stringPtr) {
	uint32_t bytesAmount = stringPtr->size();
	filePtr->write((char*)&bytesAmount, sizeof(bytesAmount));
	char* ptr = &((*stringPtr)[0]);
	filePtr->write(ptr, bytesAmount);
}

void CompressedWriter::writeCharacters() {
	writeString(charactersDfsOrderPtr);
}

void CompressedWriter::writeDfsCode() {
	writeString(dfsCodePtr);
}

void CompressedWriter::writeCompressedText() {
	writeString(compressedTextPtr);
}

CompressedWriter::~CompressedWriter() {
	safeDelete(filePtr);
}