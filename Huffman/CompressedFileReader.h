#pragma once
#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "HelpfulMethods.h"
/* 
 * Class CompressedFileReader reads binary file, which content represents some compressed data.
 * 
 * CompressedFileReader gets filename.
 *
 * Strings are read by "blocks", "block" is a unsigned 32-bit size of string and
 * string itself afterwards.
 * Not compressed text size is just an unsigned 32-bit int.
 * 
 * Brief description of CompressedFileReader work:
 * 1. Read block for characters in dfs order.
 * 2. Read block for dfs of Huffman codes.
 * 3. Read size of not compressed text.
 * 4. Read block for compressed text.
 */

class CompressedFileData; 

class CompressedFileReader : public FileReader {
public:
	CompressedFileReader();
	~CompressedFileReader();

	void read() override;

	FileData* getReadData() const override;

private:
	void readCharactersDfsOrder();
	void readDfsCode();
	void readTextSize();
	void readCompressedText();

	std::string* readBlockAndGetDataPtr();
	std::string* getDataPtr() const;
	std::uint32_t getDataSize() const;
	void readBlock();
	void readSize();

	CompressedFileData* compressedFileDataPtr = nullptr;
	std::uint32_t dataSize;
	std::string* dataPtr = nullptr;
};

class CompressedFileData : public FileData {
public:
	CompressedFileData();
	std::string* getCharactersDfsOrderPtr() const;
	std::string* getDfsCodePtr() const;
	std::uint32_t getTextSize() const;
	std::string* getCompressedTextPtr() const;
	void setCharactersDfsOrderPtr(std::string* newCharactersDfsOrderPtr);
	void setDfsCodePtr(std::string* newDfsCodePtr);
	void setTextSize(uint32_t newTextSize);
	void setCompressedTextPtr(std::string* newCompressedTextPtr);

private:
	std::string* charactersDfsOrderPtr = nullptr;
	std::string* dfsCodePtr = nullptr;
	std::uint32_t textSize;
	std::string* compressedTextPtr = nullptr;
};