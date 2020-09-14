#pragma once
#include <iostream>
#include <fstream>
#include "FileWriter.h"
/*
Class CompressedDataWriter writes data in special order
with auxillary information to binary file.

CompressedDataWriter gets:
1. String of characters in dfs order of Huffman codes tree. 
2. String of code of dfs of Huffman codes. 
3. Size of not compressed text.
4. Compressed text.   

String are written by "blocks", "block" is a unsigned 32-bit size of string and 
string itself afterwards.
Size is just an unsigned 32-bit int.

Brief description of CompressedDataWriter work:
1. Write block for characters in dfs order.
2. Write block for dfs of Huffman codes.
3. Write size of not compressed text.
4. Write block for compressed text.
*/

class CompressedDataWriter: public FileWriter {
public:
	CompressedDataWriter();
	CompressedDataWriter(std::string* charactersDfsOrderPtr,
					     std::string* dfsCodePtr,
					     std::uint32_t textSize,
					     std::string* compressedTextPtr);
	~CompressedDataWriter();

	void write();
private:

	void writeCharacters();
	void writeDfsCode();
	void writeTextSize();
	void writeCompressedText();

	void writeBlock     (std::string* stringPtr);
	void writeSize      (uint32_t size);

	std::string* charactersDfsOrderPtr = nullptr;
	std::string* dfsCodePtr = nullptr;
	std::uint32_t textSize;
	std::string* compressedTextPtr = nullptr;
};

