#pragma once
#include "CompressedFileReader.h"
#include "TreeBuilder.h"
#include "Decoder.h"
#include "DecompressedWriter.h"

/*
UnarchiveBuilder unzips binary file, reading info from it
with what building a code tree and decoding the compressed text.
After that rewritting the whole text to other file.
*/

class UnarchiveBuilder{
public:
	UnarchiveBuilder();
	UnarchiveBuilder(std::string fileToDecompressName,
		             std::string fileDecompressedName);
	void unarchivate();
	~UnarchiveBuilder();

private:
	bool fileIsOpened();
	bool fileIsEmpty();

	void startReading();
	void buildTree();
	void decode();
	void write();
	void writeEmptyFile();
	CompressedFileReader* reader = nullptr;
	TreeBuilder* treeBuilder = nullptr;
	Decoder* decoder = nullptr;
	DecompressedWriter* writer = nullptr;

	std::string fileToDecompressName;
	std::string fileDecompressedName;
};