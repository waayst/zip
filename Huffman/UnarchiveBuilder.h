#pragma once
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

class UnarchiveBuilder{
public:
	UnarchiveBuilder();
	UnarchiveBuilder             (std::string fileToDecompressName,
		                          std::string fileDecompressedName);
	~UnarchiveBuilder();

	void unarchivate            (std::string newFileToDecompressName,
		                         std::string newFileDecompressedName);
	void unarchivate();

	std::string getFileToDecompressName() const;
	std::string getFileDecompressedName() const;
	void setFileToDecompressName(std::string newFileToDecompressName);
	void setFileDecompressedName(std::string newFileDecompressedName);

private:
	void openFile();
	void read();
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