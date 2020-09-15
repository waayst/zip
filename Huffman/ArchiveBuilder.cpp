#include "ArchiveBuilder.h"
#include "HelpfulMethods.h"
using namespace std;

ArchiveBuilder::ArchiveBuilder() {}

ArchiveBuilder::ArchiveBuilder(string fileToCompressName,
			    string fileCompressedName)
	           :FileWorker(fileToCompressName, fileCompressedName)
			    {}

ArchiveBuilder::~ArchiveBuilder() {
	safeDelete(processor);
	safeDelete(compressor);
}

void ArchiveBuilder::workWithReadData() {
	process();
	compress();
}

void ArchiveBuilder::openFile() {
	safeDelete(reader);
	reader = new FileToCompressReader{};
	reader->openBinaryFile(fileToReadName);
}

void ArchiveBuilder::process() {
	safeDelete(processor);
	processor = new HuffmanProcessor(
		reader->getReadData());
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
	writer->openBinaryFile(fileToSaveName);
	if (writer->fileIsOpened()) {
		writer->write();
	} else {
		std::cerr << "can't open file to write";
	}
}
