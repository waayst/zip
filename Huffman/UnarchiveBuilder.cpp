#include <iostream>
#include "UnarchiveBuilder.h"
#include "HelpfulMethods.h"
using namespace std;

UnarchiveBuilder::UnarchiveBuilder()  {}

UnarchiveBuilder::UnarchiveBuilder(
			      string fileToDecompressName,
	              string fileDecompressedName)
	             :FileWorker(fileToDecompressName, fileDecompressedName)
{}

UnarchiveBuilder::~UnarchiveBuilder() {
	safeDelete(treeBuilder);
	safeDelete(decoder);
}

void UnarchiveBuilder::openFile() {
	safeDelete(reader);
	reader = new CompressedFileReader{};
	reader->openBinaryFile(fileToReadName);
}

void UnarchiveBuilder::workWithReadData() {
	buildTree();
	decode();
}

void UnarchiveBuilder::buildTree() {
	safeDelete(treeBuilder);
	treeBuilder = new TreeBuilder(reader->getReadData());
	treeBuilder->buildTree();
}

void UnarchiveBuilder::decode() {
	safeDelete(decoder);
	decoder = new Decoder(reader->getReadData(),
		                  treeBuilder->getCodesTree());
	decoder->decode();
}

void UnarchiveBuilder::write() {
	safeDelete(writer);
	writer = new DecompressedDataWriter(decoder->getTextPtr());
	writer->openBinaryFile(fileToSaveName);
	if (writer->fileIsOpened()) {
		writer->write();
	} else {
		std::cerr << "can't open file to write";
	}
}