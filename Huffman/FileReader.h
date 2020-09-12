#pragma once
#include <iostream>
#include <fstream>
#include "HelpfulMethods.h"

class FileReader {
public:
	FileReader();
	void openBinaryFile(std::string filename);
	bool fileIsOpened() const;
	bool fileIsEmpty() const;

protected:
	std::ifstream* filePtr = nullptr;
	bool isOpened = true;
	bool isEmpty = false;
	~FileReader();
};

