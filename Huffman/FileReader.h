#pragma once
#include <iostream>
#include <fstream>
/*
 * Class FileReader is a base class of CompressedFileReader and FileToCompressReader
 */

class FileReader {
public:
	FileReader();
	~FileReader();

	void openBinaryFile(std::string filename);

	bool fileIsOpened() const;
	bool fileIsEmpty() const;

protected:
	std::ifstream* filePtr = nullptr;
	bool isOpened;
	bool isEmpty;
};