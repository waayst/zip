#include "UnarchiveBuilder.h"
#include <iostream>
using namespace std;

UnarchiveBuilder::UnarchiveBuilder()  {}

UnarchiveBuilder::UnarchiveBuilder(
			      string fileToDecompressName,
	              string fileDecompressedName)
	             :fileToDecompressName(fileToDecompressName),
	              fileDecompressedName(fileDecompressedName)
{}

bool UnarchiveBuilder::fileIsOpened() {
	return reader->fileIsOpened();
}

bool UnarchiveBuilder::fileIsEmpty() {
	return reader->fileIsEmpty();
}

void UnarchiveBuilder::unarchivate() {
	openFile();
	if (reader->fileIsOpened()) {
		if (reader->fileIsEmpty()) {
			writeEmptyFile();
		} else {
			buildTree();
			decode();
			write();
		}
	}
}

void UnarchiveBuilder::openFile() {
	safeDelete(reader);
	reader = new CompressedFileReader();
	reader->openBinaryFile(fileToDecompressName);
}

void UnarchiveBuilder::buildTree() {
	reader->readBlock();
	auto charactersDfsOrderPtr = reader->getBlockPtr();
	reader->readBlock();
	auto dfsCodePtr = reader->getBlockPtr();
	safeDelete(treeBuilder);
	treeBuilder = new TreeBuilder(charactersDfsOrderPtr, dfsCodePtr);
	treeBuilder->buildTree();
}

void UnarchiveBuilder::decode() {
	reader->readTextSize();
	auto textSize = reader->getTextSize();
	reader->readBlock();
	auto compressedTextPtr = reader->getBlockPtr();
	auto codesTree = treeBuilder->getCodesTree();
	safeDelete(decoder);
	decoder = new Decoder(textSize, compressedTextPtr, codesTree);
	decoder->decode();
}

void UnarchiveBuilder::write() {
	safeDelete(writer);
	writer = new DecompressedDataWriter(decoder->getTextPtr());
	writer->openBinaryFile(fileDecompressedName);
	if (writer->fileIsOpened()) {
		writer->write();
	} else {
		std::cerr << "can't open file to write";
	}
}

void UnarchiveBuilder::writeEmptyFile() {
	safeDelete(writer);
	writer = new DecompressedDataWriter;
	writer->openBinaryFile(fileDecompressedName);
	if (writer->fileIsOpened()) {
		writer->writeEmptyFile();
	} else {
		std::cerr << "can't open file to write";
	}
}

UnarchiveBuilder::~UnarchiveBuilder() {
	safeDelete(reader);
	safeDelete(treeBuilder);
	safeDelete(decoder);
	safeDelete(writer);
}
				
