#include <iostream>
#include "UnarchiveBuilder.h"
#include "HelpfulMethods.h"
using namespace std;

UnarchiveBuilder::UnarchiveBuilder()  {}

UnarchiveBuilder::UnarchiveBuilder(
			      string fileToDecompressName,
	              string fileDecompressedName)
	             :fileToDecompressName(fileToDecompressName),
	              fileDecompressedName(fileDecompressedName)
{}

UnarchiveBuilder::~UnarchiveBuilder() {
	safeDelete(reader);
	safeDelete(treeBuilder);
	safeDelete(decoder);
	safeDelete(writer);
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
	auto charactersDfsOrderPtr = reader->readAndGetBlockPtr();
	auto dfsCodePtr = reader->readAndGetBlockPtr();
	safeDelete(treeBuilder);
	treeBuilder = new TreeBuilder(charactersDfsOrderPtr, dfsCodePtr);
	treeBuilder->buildTree();
}

void UnarchiveBuilder::decode() {
	auto textSize = reader->readAndGetTextSize();
	auto compressedTextPtr = reader->readAndGetBlockPtr();
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