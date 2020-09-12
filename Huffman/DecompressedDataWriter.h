#include <iostream>
#include <fstream>
#include "FileWriter.h"
#include "HelpfulMethods.h"
#pragma once

/*
TextWriter writes the whole buffer(textPtr) to binary file
*/

class DecompressedDataWriter : public FileWriter {
public:
	DecompressedDataWriter();
	DecompressedDataWriter(std::string* textPtr);

	void write();

	~DecompressedDataWriter();
private:
	std::string* textPtr = nullptr;
};
