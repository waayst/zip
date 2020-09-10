#pragma once
#include <iostream>
#include <fstream>
#include "HelpfulMethods.h"

class TextWriter {
public:
	TextWriter();
	TextWriter(std::string* charactersDfsOrderPtr,
			   std::string* compressedTreePtr,
			   std::string* compressedTextPtr);

	void write(std::string filename);
	void writeEmptyFile(std::string filename);

	~TextWriter();
private:
	void writeCharacters();
	void writeDfsCode();
	void writeCompressedText();

	void writeString(std::string* stringPtr);
	std::ofstream* filePtr;

	std::string* charactersDfsOrderPtr;
	std::string* dfsCodePtr;
	std::string* compressedTextPtr;
};

