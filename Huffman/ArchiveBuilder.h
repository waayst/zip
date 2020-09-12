#pragma once
#include <iostream>
#include "FileToCompressReader.h"
#include "HuffmanProcessor.h"
#include "Compressor.h"
#include "CompressedDataWriter.h"
/*
ArchieveBuilder gets filename to compress.
Reads it, than processes Huffman algorithm, than compresses text.
After that writes auxillary information and compressed text to another file.
*/

class ArchiveBuilder {
public:
	ArchiveBuilder();
	ArchiveBuilder(std::string fileToCompressName,
				   std::string fileCompressedName);

	void archivate();
	
	~ArchiveBuilder();

private:
	void openFile();
	void read();
	void process();
	void compress();
	void write();
	void writeEmptyFile();

	std::string fileToCompressName;
	std::string fileCompressedName;

	FileToCompressReader* reader = nullptr;
	HuffmanProcessor* processor = nullptr;
	Compressor* compressor = nullptr;
	CompressedDataWriter* writer = nullptr;
};