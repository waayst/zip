#pragma once
#include <iostream>
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
 * Maybe should be refactored, having common superclass with UnarchiveBuilder.
 */

class ArchiveBuilder {
public:
	ArchiveBuilder();
	ArchiveBuilder            (std::string fileToCompressName,
				               std::string fileCompressedName);
	~ArchiveBuilder();

	void archivate            (std::string newFileToCompressName,
						       std::string newFileCompressedName);
	void archivate();
	
	std::string getFileToCompressName() const;
	std::string getFileCompressedName() const;
	void setFileToCompressName(std::string newFileToCompressName);
	void setFileCompressedName(std::string newFileCompressedName);

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