#include <iostream>
#include <fstream>
#include "HelpfulMethods.h"
#pragma once
class TextWriter {
public:
	TextWriter();
	TextWriter(std::string* textPtr);

	void write(std::string filename);
	void writeEmptyFile(std::string filename);

	~TextWriter();
private:
	std::string* textPtr;
};
