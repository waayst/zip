#include "ArchiveBuilder.h"
#include "HelpfulMethods.h"
using namespace std;

ArchiveBuilder::ArchiveBuilder() {}

ArchiveBuilder::ArchiveBuilder(std::string fileToCompressName,
				std::string fileCompressedName)
			   :fileToCompressName(fileToCompressName),
				fileCompressedName(fileCompressedName) {}


ArchiveBuilder::~ArchiveBuilder() {
	safeDelete(reader);
	safeDelete(processor);
	safeDelete(compressor);
	safeDelete(writer);
}

void ArchiveBuilder::archivate(
				     string newFileToCompressName,
	                 string newFileCompressedName) {
	setFileToCompressName(newFileToCompressName);
	setFileCompressedName(newFileCompressedName);
	archivate();
}

void ArchiveBuilder::archivate() {
	openFile();
	if (fileIsOpened()) {
		if (fileIsEmpty()) {
			writeEmptyFile();
		} else {
			read();
			process();
			compress();
			write();
		}
	} 
}

void ArchiveBuilder::setFileToCompressName(string newFileToCompressName) {
	fileToCompressName = newFileToCompressName;
}

void ArchiveBuilder::setFileCompressedName(string newFileCompressedName) {
	fileCompressedName = newFileCompressedName;
}

string ArchiveBuilder::getFileToCompressName() const {
	return fileToCompressName;
}

string ArchiveBuilder::getFileCompressedName() const {
	return fileCompressedName;
}


void ArchiveBuilder::openFile() {
	safeDelete(reader);
	reader = new FileToCompressReader;
	reader->openBinaryFile(fileToCompressName);
}

bool ArchiveBuilder::fileIsOpened() {
	return reader->fileIsOpened();
}

bool ArchiveBuilder::fileIsEmpty() {
	return reader->fileIsEmpty();
}

void ArchiveBuilder::read() {
	reader->read(fileToCompressName);
}

void ArchiveBuilder::process() {
	safeDelete(processor);
	processor = new HuffmanProcessor(reader->getTextPtr());
	processor->process();
}

void ArchiveBuilder::compress() {
	safeDelete(compressor);
	compressor = new Compressor(
		reader->getTextPtr(),
		processor->getCodesTree());
	compressor->compress();
}

void ArchiveBuilder::write() {
	safeDelete(writer);
	writer = new CompressedDataWriter(
		compressor->getCharactersDfsOrderPtr(),
		compressor->getDfsCodePtr(),
		reader->getTextPtr()->size(),
		compressor->getCompressedTextPtr());
	writer->openBinaryFile(fileCompressedName);
	if (writer->fileIsOpened()) {
		writer->write();
	} else {
		std::cerr << "can't open file to write";
	}
}

void ArchiveBuilder::writeEmptyFile() {
	safeDelete(writer);
	writer = new CompressedDataWriter;
	writer->openBinaryFile(fileCompressedName);
	if (writer->fileIsOpened()) {
		writer->writeEmptyFile();
	} else {
		std::cerr << "can't open file to write";
	}
}