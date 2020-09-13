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

Maybe should be refactored, having common superclass with UnarchiveBuilder.
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
	
	void setFileToCompressName(std::string newFileToCompressName);
	void setFileCompressedName(std::string newFileCompressedName);
	std::string getFileToCompressName() const;
	std::string getFileCompressedName() const;

private:
	void openFile();
	bool fileIsOpened();
	bool fileIsEmpty();
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