#include "TextWriter.h"
using namespace std;

TextWriter::TextWriter(): textPtr(nullptr) {}

TextWriter::TextWriter(string* textPtr): textPtr(textPtr) {}

TextWriter::~TextWriter() {
	//safeDelete(textPtr);
}
void TextWriter::write(string filename) {
	ofstream file(filename,ios::binary|ios::out);
	char* ptr = &(*textPtr)[0];
	file.write(ptr, textPtr->size());
}
void TextWriter::writeEmptyFile(string filename) {
	ofstream file(filename, ios::binary | ios::out);
}