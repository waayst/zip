#pragma once
#include <iostream>
#include <fstream>
/*
FileWriter is a base class for CompressedDataWriter and DecompressedDataWriter
*/

class FileWriter {
public:
	FileWriter();
	void openBinaryFile(std::string filename);

	void writeEmptyFile();

	~FileWriter();

	bool fileIsOpened() const;

protected:
	void writeString(std::string* stringPtr);

	bool isOpened;
	std::ofstream* filePtr = nullptr;
};