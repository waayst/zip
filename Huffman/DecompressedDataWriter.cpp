#include "DecompressedDataWriter.h"
using namespace std;

DecompressedDataWriter::DecompressedDataWriter() {}

DecompressedDataWriter::DecompressedDataWriter(string* textPtr): textPtr(textPtr) {}

DecompressedDataWriter::~DecompressedDataWriter() {}

void DecompressedDataWriter::write() {
	writeString(textPtr);
}
