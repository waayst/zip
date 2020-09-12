#include "ArchiveBuilder.h"
using namespace std;

ArchiveBuilder::ArchiveBuilder() {}

ArchiveBuilder::ArchiveBuilder(std::string fileToCompressName,
				std::string fileCompressedName)
			   :fileToCompressName(fileToCompressName),
				fileCompressedName(fileCompressedName) {}

void ArchiveBuilder::archivate() {
	openFile();
	if (reader->fileIsOpened()) {
		if (reader->fileIsEmpty()) {
			writeEmptyFile();
		} else {
			read();
			process();
			compress();
			write();
		}
	} 
}

bool ArchiveBuilder::fileIsOpened() {
	return reader->fileIsOpened();
}

bool ArchiveBuilder::fileIsEmpty() {
	return reader->fileIsEmpty();
}

void ArchiveBuilder::openFile() {
	safeDelete(reader);
	reader = new FileToCompressReader();
	reader->openBinaryFile(fileToCompressName);
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
	compressor = new Compressor(reader->getTextPtr(),
									processor->getCodesTree());
	compressor->compress();
}

void ArchiveBuilder::write() {
	safeDelete(writer);
	writer = new CompressedDataWriter(compressor->getCharactersDfsOrderPtr(),
						  compressor->getDfsCodePtr(),
						  reader->getTextPtr()->size(),
						  compressor->getCompressedTextPtr());
	writer->write(fileCompressedName);
}

void ArchiveBuilder::writeEmptyFile() {
	safeDelete(writer);
	writer = new CompressedDataWriter;
	writer->writeEmptyFile(fileCompressedName);
}

ArchiveBuilder::~ArchiveBuilder() {
	safeDelete(reader);
	safeDelete(processor);
	safeDelete(compressor);
	safeDelete(writer);
}

