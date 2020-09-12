#include <iostream>
#include <fstream>
#include "HelpfulMethods.h"
#pragma once

/*
TextWriter writes the whole buffer(textPtr) to binary file
*/

class DecompressedWriter {
public:
	DecompressedWriter();
	DecompressedWriter(std::string* textPtr);

	void write(std::string filename);
	void writeEmptyFile(std::string filename);

	~DecompressedWriter();
private:
	std::string* textPtr = nullptr;
};
