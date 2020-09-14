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

void UnarchiveBuilder::unarchivate(
				       string newFileToDecompressName,
	                   string newFileDecompressedName) {
	setFileToDecompressName(newFileToDecompressName);
	setFileDecompressedName(newFileDecompressedName);
	unarchivate();
}

void UnarchiveBuilder::unarchivate() {
	openFile();
	if (!reader->fileIsOpened()) {
		cerr << "file " << fileToDecompressName.c_str() << " can't be opened";
		return;
	}
	if (reader->fileIsEmpty()) {
		cerr << "file " << fileToDecompressName.c_str() << " is empty";
		writeEmptyFile();
		return;
	}
	read();
	buildTree();
	decode();
	write();
}

string UnarchiveBuilder::getFileToDecompressName() const {
	return fileToDecompressName;
}

string UnarchiveBuilder::getFileDecompressedName() const {
	return fileDecompressedName;
}

void UnarchiveBuilder::setFileToDecompressName(
	string newFileToDecompressName) {
	fileToDecompressName = newFileToDecompressName;
}

void UnarchiveBuilder::setFileDecompressedName(
	string newFileDecompressedName) {
	fileDecompressedName = newFileDecompressedName;
}

void UnarchiveBuilder::openFile() {
	safeDelete(reader);
	reader = new CompressedFileReader{};
	reader->openBinaryFile(fileToDecompressName);
}

void UnarchiveBuilder::read() {
	reader->read();
}

void UnarchiveBuilder::buildTree() {
	safeDelete(treeBuilder);
	treeBuilder = new TreeBuilder(reader->getCharactersDfsOrderPtr(),
								  reader->getDfsCodePtr());
	treeBuilder->buildTree();
}

void UnarchiveBuilder::decode() {
	safeDelete(decoder);
	decoder = new Decoder(reader->getTextSize(),
		                  reader->getCompressedTextPtr(),
		                  treeBuilder->getCodesTree());
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