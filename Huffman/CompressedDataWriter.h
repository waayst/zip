#pragma once
#include <iostream>
#include <fstream>
#include "FileWriter.h"
/*
CompressedDataWriter gets codes tree characters in dfs order,
dfs code of tree, not compressed text size, compressed text,
and writes them in that order to file.
Also writes size of string before each string.
*/

class CompressedDataWriter: public FileWriter {
public:
	CompressedDataWriter();
	CompressedDataWriter(std::string* charactersDfsOrderPtr,
					     std::string* dfsCodePtr,
					     std::uint32_t textSize,
					     std::string* compressedTextPtr);
	~CompressedDataWriter();

	void write	         ();

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

