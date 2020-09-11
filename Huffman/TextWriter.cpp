#include "TextWriter.h"
using namespace std;

TextWriter::TextWriter() {}

TextWriter::TextWriter(string* textPtr): textPtr(textPtr) {}

TextWriter::~TextWriter() {}

void TextWriter::write(string filename) {
	ofstream file(filename,ios::binary|ios::out);
	char* ptr = &(*textPtr)[0];
	file.write(ptr, textPtr->size());
}
void TextWriter::writeEmptyFile(string filename) {
	ofstream file(filename, ios::binary | ios::out);
}