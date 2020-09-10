#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "HelpfulMethods.h"

class TextReader {
public:
	TextReader();

	void read(std::string filename);
	~TextReader();

	std::string* getTextPtr();
	bool fileIsEmpty();
private:
	std::string* textPtr;
};

