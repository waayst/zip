#include <iostream>
#include <fstream>
#include "HelpfulMethods.h"
#pragma once

/*
TextWriter writes the whole buffer(textPtr) to binary file
*/

class TextWriter {
public:
	TextWriter();
	TextWriter(std::string* textPtr);

	void write(std::string filename);
	void writeEmptyFile(std::string filename);

	~TextWriter();
private:
	std::string* textPtr = nullptr;
};
