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
	if (!reader->fileIsOpened()) {
		cerr << "file " << fileToCompressName.c_str() << " can't be opened";
		return;
	}
	if (reader->fileIsEmpty()) {
		cerr << "file " << fileToCompressName.c_str() << " is empty";
		writeEmptyFile();
		return;
	}
    read();
	process();
    compress();
	write();
}

string ArchiveBuilder::getFileToCompressName() const {
	return fileToCompressName;
}

string ArchiveBuilder::getFileCompressedName() const {
	return fileCompressedName;
}

void ArchiveBuilder::setFileToCompressName(string newFileToCompressName) {
	fileToCompressName = newFileToCompressName;
}

void ArchiveBuilder::setFileCompressedName(string newFileCompressedName) {
	fileCompressedName = newFileCompressedName;
}
void ArchiveBuilder::openFile() {
	safeDelete(reader);
	reader = new FileToCompressReader{};
	reader->openBinaryFile(fileToCompressName);
}

void ArchiveBuilder::read() {
	reader->read();
}

void ArchiveBuilder::process() {
	safeDelete(processor);
	processor = new HuffmanProcessor(reader->getReadData());
	processor->process();
}

void ArchiveBuilder::compress() {
	safeDelete(compressor);
	compressor = new Compressor(
		reader->getReadData(),
		processor->getCodesTree());
	compressor->compress();
}

void ArchiveBuilder::write() {
	safeDelete(writer);
	writer = new CompressedDataWriter(
		compressor->getCharactersDfsOrderPtr(),
		compressor->getDfsCodePtr(),
		compressor->getTextSize(),
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