#pragma once
#include "FileWorker.h"
#include "CompressedFileReader.h"
#include "TreeBuilder.h"
#include "Decoder.h"
#include "DecompressedDataWriter.h"
/*
 * Class UnarchiveBuilder unarchivates file, saving result to another file.
 * ArchieveBuilder gets:
 * 1. Name of file to decompress.
 * 2. Name of file to save to.
 *
 * Brief description of ArchieveBuilder work:
 * 1. Read content of file to decompress.
 * 2. Build Huffman codes tree.
 * 3. Decodes text.
 * 4. Write decompressed data to another file. 
 *
 *Maybe should be refactored, having common superclass with ArchiveBuilder.
 */

class UnarchiveBuilder : public FileWorker {
public:
	UnarchiveBuilder();
	UnarchiveBuilder             (std::string fileToDecompressName,
		                          std::string fileDecompressedName);
	~UnarchiveBuilder();

private:
	void openFile() override;
	void workWithReadData();
	void buildTree();
	void decode();
	void write() override;

	TreeBuilder* treeBuilder = nullptr;
	Decoder* decoder = nullptr;
};