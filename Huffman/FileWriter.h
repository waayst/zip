#pragma once
#include <iostream>
#include <fstream>
/*
 * Class FileWriter is a base class for CompressedDataWriter and DecompressedDataWriter
 */

class FileWriter {
public:
	FileWriter();
	~FileWriter();

	void openBinaryFile(std::string filename);
	void writeEmptyFile();

	bool fileIsOpened() const;

protected:
	void writeString(std::string* stringPtr);

	bool isOpened;
	std::ofstream* filePtr = nullptr;
};