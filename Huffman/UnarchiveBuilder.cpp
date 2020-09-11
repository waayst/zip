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
	startReading();
	if (!fileIsOpened()) {
		std::cout << "no such file to decompress";
		return;
	}
	if (fileIsEmpty()) {
		writeEmptyFile();
		return;
	}
	buildTree();
	decode();
	write();
}

void UnarchiveBuilder::startReading() {
	safeDelete(reader);
	reader = new BnReader();
	reader->startReading(fileToDecompressName);
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
	writer = new TextWriter(decoder->getTextPtr());
	writer->write(fileDecompressedName);
}

void UnarchiveBuilder::writeEmptyFile() {
	safeDelete(writer);
	writer = new TextWriter;
	writer->writeEmptyFile(fileDecompressedName);
}

UnarchiveBuilder::~UnarchiveBuilder() {
	safeDelete(reader);
	safeDelete(treeBuilder);
	safeDelete(decoder);
	safeDelete(writer);
}
				
