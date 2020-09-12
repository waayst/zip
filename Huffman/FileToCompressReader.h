#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "FileReader.h"
#include "HelpfulMethods.h"

/* 
TextReader - class reads whole file in one go to textPtr,
'text' are those bytes all together.

TextReader and BnReader will be rewritten having common base.
*/

class FileToCompressReader : public FileReader {
public:
	FileToCompressReader();

	void read(std::string filename);
	~FileToCompressReader();

	std::string* getTextPtr();

private:
	std::string* textPtr = nullptr;
};

