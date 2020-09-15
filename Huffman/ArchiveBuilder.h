#pragma once
#include <iostream>
#include "FileWorker.h"
#include "FileToCompressReader.h"
#include "HuffmanProcessor.h"
#include "Compressor.h"
#include "CompressedDataWriter.h"
/*
 * Class ArchieveBuilder archivates file, saving result to another file. 
 * ArchieveBuilder gets: 
 * 1. Name of file to compress.
 * 2. Name of file to save to.
 *
 * Brief description of ArchieveBuilder work:
 * 1. Read content of file to compress.
 * 2. Process Huffman algorithm.
 * 3. Compress text.
 * 4. Write auxillary information and compressed text to another file.
 *
 */

class ArchiveBuilder : public FileWorker {
public:
	ArchiveBuilder();
	ArchiveBuilder(std::string fileToCompressName,
				   std::string fileCompressedName);
	~ArchiveBuilder();
private:
	void openFile() override;
	void workWithReadData() override;
	void process();
	void compress();
	virtual void write() override;

	HuffmanProcessor* processor = nullptr;
	Compressor* compressor = nullptr;
};