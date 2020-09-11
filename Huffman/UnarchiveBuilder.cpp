#include "UnarchiveBuilder.h"
using namespace std;

UnarchiveBuilder::UnarchiveBuilder() :
	reader(nullptr), treeBuilder(nullptr),
	decoder(nullptr), writer(nullptr) {}

UnarchiveBuilder::UnarchiveBuilder(string fileToDecompressName,
	string fileDecompressedName)
	: fileToDecompressName(fileToDecompressName),
	fileDecompressedName(fileDecompressedName),
	reader(nullptr), treeBuilder(nullptr),
	decoder(nullptr), writer(nullptr)

{}

bool UnarchiveBuilder::fileIsEmpty() {
	return reader->fileIsEmpty();
}

void UnarchiveBuilder::unarchivate() {
	startReading();
	if (reader->fileIsEmpty()) {
		writeEmptyFile();
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
	treeBuilder->createTree();
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
				
