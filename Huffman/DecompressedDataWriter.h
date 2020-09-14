#include <iostream>
#include <fstream>
#include "FileWriter.h"
#include "HelpfulMethods.h"
#pragma once
/*
Class DecompressedDataWriter writes decompressed data to binary file.

DecompressedDataWriter gets decompressed text and writes it as one string to file.
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
