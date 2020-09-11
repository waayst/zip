#pragma once
#include <iostream>
#include "TextReader.h"
#include "HuffmanProcessor.h"
#include "TextCompressor.h"
#include "BnWriter.h"

/*
ArchieveBuilder - class that zips some file(fileToCompressName),
reading it, than processing Huffman algorithm, than compressing text.
After that writing auxillary information and compressed text to another file.
*/

class ArchiveBuilder {
public:
	ArchiveBuilder();
	ArchiveBuilder(std::string fileToCompressName,
				   std::string fileCompressedName);

	void archivate();
	
	~ArchiveBuilder();

private:
	bool fileIsOpened();
	bool fileIsEmpty();

	void read();
	void process();
	void compress();
	void write();
	void writeEmptyFile();

	TextReader* reader = nullptr;
	HuffmanProcessor* processor = nullptr;
	TextCompressor* compressor = nullptr;
	BnWriter* writer = nullptr;

	std::string fileToCompressName;
	std::string fileCompressedName;
};