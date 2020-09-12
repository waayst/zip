#pragma once
#include <iostream>
#include <fstream>
#include "FileReader.h"
/* 
FileToCompressReader gets filename and reads whole
file as one string in one go and saves result.
*/

class FileToCompressReader : public FileReader {
public:
	FileToCompressReader();
	~FileToCompressReader();

	void read(std::string filename);

	std::string* getTextPtr();

private:
	std::string* textPtr = nullptr;
};

