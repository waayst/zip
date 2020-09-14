#pragma once
#include <iostream>
#include <fstream>
#include "FileReader.h"
/* 
 * Class FileToCompressReader reads content of file and saves it.
 *
 * FileToCompressReader gets filename and saves all content of file in one string.
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

