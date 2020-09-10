#pragma once
#pragma once
#include <iostream>
#include "TextReader.h"
#include "HuffmanProcessor.h"
#include "TextCompressor.h"
#include "BnWriter.h"

class ArchiveBuilder {
public:
	ArchiveBuilder();
	ArchiveBuilder(std::string fileToCompressName,
				   std::string fileCompressedName);
	void archivate();
	~ArchiveBuilder();

private:
	void read();
	void process();
	void compress();
	void write();
	void writeEmptyFile();

	TextReader* reader;
	HuffmanProcessor* processor;
	TextCompressor* compressor;
	BnWriter* writer;

	std::string fileToCompressName;
	std::string fileCompressedName;
};