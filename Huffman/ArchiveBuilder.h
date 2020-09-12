#pragma once
#include <iostream>
#include "FileToCompressReader.h"
#include "HuffmanProcessor.h"
#include "Compressor.h"
#include "CompressedDataWriter.h"

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

	void openFile();
	void read();
	void process();
	void compress();
	void write();
	void writeEmptyFile();

	FileToCompressReader* reader = nullptr;
	HuffmanProcessor* processor = nullptr;
	Compressor* compressor = nullptr;
	CompressedDataWriter* writer = nullptr;

	std::string fileToCompressName;
	std::string fileCompressedName;
};