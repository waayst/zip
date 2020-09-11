#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "HelpfulMethods.h"

/* 
TextReader - class reads whole file in one go to textPtr,
'text' are those bytes all together.

TextReader and BnReader will be rewritten having common base.
*/

class TextReader {
public:
	TextReader();

	void read(std::string filename);
	~TextReader();

	std::string* getTextPtr();
	bool fileIsOpened();
	bool fileIsEmpty();

private:
	std::string* textPtr = nullptr;
	bool fileOpen = true;
	bool fileEmptiness = false;
};

