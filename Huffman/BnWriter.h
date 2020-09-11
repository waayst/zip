#pragma once
#include <iostream>
#include <fstream>
#include "HelpfulMethods.h"

class BnWriter {
public:
	BnWriter();
	BnWriter(std::string* charactersDfsOrderPtr,
		std::string* compressedTreePtr,
		std::uint32_t textSize,
		std::string* compressedTextPtr);

	void write(std::string filename);
	void writeEmptyFile(std::string filename);

	~BnWriter();
private:
	void writeCharacters();
	void writeDfsCode();
	void writeTextSize();
	void writeCompressedText();

	void writeString(std::string* stringPtr);
	std::ofstream* filePtr;



	std::string* charactersDfsOrderPtr;
	std::string* dfsCodePtr;
	std::uint32_t textSize;
	std::string* compressedTextPtr;
};

