#include "ArchiveBuilder.h"

ArchiveBuilder::ArchiveBuilder(): reader(nullptr),
				processor(nullptr), compressor(nullptr),
				writer(nullptr)
{}

ArchiveBuilder::ArchiveBuilder(std::string fileToCompressName,
	std::string fileCompressedName) : fileToCompressName(fileToCompressName),
	fileCompressedName(fileCompressedName),
	reader(nullptr), processor(nullptr),
	compressor(nullptr), writer(nullptr)
{}

void ArchiveBuilder::archivate() {
	read();
	if (reader->fileIsEmpty()) {
		writeEmptyFile();
		return;
	}
	process();
	compress();
	write();
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
	compressor = new TextCompressor(processor->getTextPtr(),
									processor->getCodesTree());
	compressor->compress();
}

void ArchiveBuilder::write() {
	safeDelete(writer);
	writer = new BnWriter  (compressor->getCharactersDfsOrderPtr(),
							compressor->getDfsCodePtr(),
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

