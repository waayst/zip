#pragma once
#include <iostream>
#include <fstream>
#include "HelpfulMethods.h"

/*
BnWriter writes characters in dfs of codes tree order,
dfs code and compressed text in binary file.
*/

class CompressedDataWriter {
public:
	CompressedDataWriter();
	CompressedDataWriter  (std::string* charactersDfsOrderPtr,
					   std::string* compressedTreePtr,
					   std::uint32_t textSize,
					   std::string* compressedTextPtr);

	void write	       (std::string filename);
	void writeEmptyFile(std::string filename);

	~CompressedDataWriter();
private:
	void writeCharacters();
	void writeDfsCode();
	void writeTextSize();
	void writeCompressedText();

	void writeString   (std::string* stringPtr);
	std::ofstream* filePtr = nullptr;

	std::string* charactersDfsOrderPtr = nullptr;
	std::string* dfsCodePtr = nullptr;
	std::uint32_t textSize;
	std::string* compressedTextPtr = nullptr;
};

