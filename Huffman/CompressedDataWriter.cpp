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

CompressedDataWriter::~CompressedDataWriter() {}

void CompressedDataWriter::write() {
	writeCharacters();
	writeDfsCode();
	writeTextSize();
	writeCompressedText();
	filePtr->close();
}

void CompressedDataWriter::writeCharacters() {
	writeBlock(charactersDfsOrderPtr);
}

void CompressedDataWriter::writeDfsCode() {
	writeBlock(dfsCodePtr);
}

void CompressedDataWriter::writeTextSize() {
	writeSize(textSize);
}

void CompressedDataWriter::writeCompressedText() {
	writeBlock(compressedTextPtr);
}

void CompressedDataWriter::writeBlock(std::string* stringPtr) {
	writeSize(stringPtr->size());
	writeString(stringPtr);
}

void CompressedDataWriter::writeSize(uint32_t size) {
	filePtr->write((char*)&size, sizeof(size));
}