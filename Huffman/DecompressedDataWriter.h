#include <iostream>
#include <fstream>
#include "FileWriter.h"
#include "HelpfulMethods.h"
#pragma once
/*
DecompressedDataWriter writes whole decompressed data to file in one go.
*/

class DecompressedDataWriter : public FileWriter {
public:
	DecompressedDataWriter();
	DecompressedDataWriter(std::string* textPtr);
	~DecompressedDataWriter();

	void write();

private:
	std::string* textPtr = nullptr;
};
