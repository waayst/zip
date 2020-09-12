#pragma once
#include "CompressedFileReader.h"
#include "TreeBuilder.h"
#include "Decoder.h"
#include "DecompressedDataWriter.h"
/*
UnarchiveBuilder gets filename to unzip and filename to save result to.
*/

class UnarchiveBuilder{
public:
	UnarchiveBuilder();
	UnarchiveBuilder(std::string fileToDecompressName,
		             std::string fileDecompressedName);
	void unarchivate();
	~UnarchiveBuilder();

private:
	void openFile();
	void buildTree();
	void decode();
	void write();
	void writeEmptyFile();


	std::string fileToDecompressName;
	std::string fileDecompressedName;

	CompressedFileReader* reader = nullptr;
	TreeBuilder* treeBuilder = nullptr;
	Decoder* decoder = nullptr;
	DecompressedDataWriter* writer = nullptr;
};