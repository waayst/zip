#include "DecompressedWriter.h"
using namespace std;

DecompressedWriter::DecompressedWriter() {}

DecompressedWriter::DecompressedWriter(string* textPtr): textPtr(textPtr) {}

DecompressedWriter::~DecompressedWriter() {}

void DecompressedWriter::write(string filename) {
	ofstream file(filename,ios::binary|ios::out);
	char* ptr = &(*textPtr)[0];
	file.write(ptr, textPtr->size());
}
void DecompressedWriter::writeEmptyFile(string filename) {
	ofstream file(filename, ios::binary | ios::out);
}