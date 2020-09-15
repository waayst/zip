#pragma once
#include <iostream>
#include <fstream>
/*
 * Class FileReader is a base class of CompressedFileReader and FileToCompressReader
 */
class FileData;

class FileReader {
public:
	FileReader();
	~FileReader();

	void openBinaryFile(std::string filename);

	virtual void read() = 0;

	virtual FileData* getReadData() const = 0;

	bool fileIsOpened() const;
	bool fileIsEmpty() const;

protected:
	std::ifstream* filePtr = nullptr;
	bool isOpened;
	bool isEmpty;
};

class FileData {
public:
	~FileData();

private:
};