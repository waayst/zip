#pragma once
#include <iostream>
#include <fstream>
#include "FileReader.h"
/* 
 * Class FileToCompressReader reads content of file and saves it.
 *
 * FileToCompressReader gets filename and saves all content of file in one string.
 */
class FileToCompressData;

class FileToCompressReader : public FileReader {
public:
	FileToCompressReader();
	~FileToCompressReader();

	void read() override;
	FileData* getReadData() const override;

private:
	FileToCompressData* fileToCompressDataPtr;
};

class FileToCompressData : public FileData {
public:
	FileToCompressData();
	FileToCompressData(std::string* textPtr);
	~FileToCompressData();
	std::string* getTextPtr() const;
	void setTextPtr(std::string* newTextPtr);
private:
	std::string* textPtr = nullptr;
};
