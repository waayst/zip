#include "TextWriter.h"
using namespace std;

TextWriter::TextWriter():filePtr(nullptr),
			charactersDfsOrderPtr(nullptr),
            dfsCodePtr(nullptr),
			compressedTextPtr(nullptr) {}

TextWriter::TextWriter(std::string* charactersDfsOrderPtr,
	std::string* dfsCodePtr,
	std::string* compressedTextPtr) :
	filePtr(nullptr),
	charactersDfsOrderPtr(charactersDfsOrderPtr),
	dfsCodePtr(dfsCodePtr),
	compressedTextPtr(compressedTextPtr) {}

void TextWriter::write(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	writeCharacters();
	writeDfsCode();
	writeCompressedText();
	safeDelete(filePtr);
}

void TextWriter::writeEmptyFile(string filename) {
	safeDelete(filePtr);
	filePtr = new ofstream(filename, ios::binary | ios::out);
	safeDelete(filePtr);
}

void TextWriter::writeString(std::string* stringPtr) {
	uint32_t bytesAmount = stringPtr->size();
	filePtr->write((char*)&bytesAmount, sizeof(bytesAmount));
	char* ptr = &((*charactersDfsOrderPtr)[0]);
	filePtr->write(ptr, bytesAmount);
}

void TextWriter::writeCharacters() {
	writeString(charactersDfsOrderPtr);
}

void TextWriter::writeDfsCode() {
	writeString(dfsCodePtr);
}

void TextWriter::writeCompressedText() {
	writeString(compressedTextPtr);
}

TextWriter::~TextWriter() {
	safeDelete(filePtr);
}