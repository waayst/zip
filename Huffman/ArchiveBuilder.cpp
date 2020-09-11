#include "ArchiveBuilder.h"
using namespace std;

ArchiveBuilder::ArchiveBuilder() {}

ArchiveBuilder::ArchiveBuilder(std::string fileToCompressName,
				std::string fileCompressedName)
			   :fileToCompressName(fileToCompressName),
				fileCompressedName(fileCompressedName) {}

void ArchiveBuilder::archivate() {
	read();
	if (!fileIsOpened()) {
		cerr << "can't open file " << fileToCompressName << endl;
		return;
	}
	if (fileIsEmpty()) {
		writeEmptyFile();
		return;
	}
	process();
	compress();
	write();
}

bool ArchiveBuilder::fileIsOpened() {
	return reader->fileIsOpened();
}

bool ArchiveBuilder::fileIsEmpty() {
	return reader->fileIsEmpty();
}

void ArchiveBuilder::read() {
	safeDelete(reader);
	reader = new TextReader();
	reader->read(fileToCompressName);
}

void ArchiveBuilder::process() {
	safeDelete(processor);
	processor = new HuffmanProcessor(reader->getTextPtr());
	processor->process();
}

void ArchiveBuilder::compress() {
	safeDelete(compressor);
	compressor = new TextCompressor(reader->getTextPtr(),
									processor->getCodesTree());
	compressor->compress();
}

void ArchiveBuilder::write() {
	safeDelete(writer);
	writer = new BnWriter(compressor->getCharactersDfsOrderPtr(),
						  compressor->getDfsCodePtr(),
						  reader->getTextPtr()->size(),
						  compressor->getCompressedTextPtr());
	writer->write(fileCompressedName);
}

void ArchiveBuilder::writeEmptyFile() {
	safeDelete(writer);
	writer = new BnWriter;
	writer->writeEmptyFile(fileCompressedName);
}

ArchiveBuilder::~ArchiveBuilder() {
	safeDelete(reader);
	safeDelete(processor);
	safeDelete(compressor);
	safeDelete(writer);
}

