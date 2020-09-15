#include "FileWorker.h"
#include "HelpfulMethods.h"
using namespace std;

FileWorker::FileWorker() {}

FileWorker::FileWorker(string fileToReadName, string fileToSaveName)
	       :fileToReadName(fileToReadName), fileToSaveName(fileToSaveName) {}

FileWorker::~FileWorker(){
	safeDelete(reader);
	safeDelete(writer);
}

void FileWorker::execute(string newFileToReadName,
	                     string newFileToSaveName) {
	setFileToReadName(newFileToReadName);
	setFileToSaveName(newFileToSaveName);
	execute();
}

void FileWorker::execute() {
	openFile();
	if (!reader->fileIsOpened()) {
		cerr << "file can't be opened" << endl;
		return;
	}
	if (reader->fileIsEmpty()) {
		writeEmptyFile();
		return;
	}
	read();
	workWithReadData();
	write();
}

string FileWorker::getFileToReadName() const {
	return fileToReadName;
}

string FileWorker::getFileToSaveName() const {
	return fileToSaveName;
}

void FileWorker::setFileToReadName(string newFileToReadName) {
	fileToReadName = newFileToReadName;
}

void FileWorker::setFileToSaveName(string newFileToSaveName) {
	fileToSaveName = newFileToSaveName;
}

void FileWorker::read() {
	reader->read();
}

void FileWorker::writeEmptyFile() {
	safeDelete(writer);
	writer = new FileWriter;
	writer->openBinaryFile(fileToSaveName);
	if (writer->fileIsOpened()) {
		writer->writeEmptyFile();
	}
	else {
		std::cerr << "can't open file to write";
	}
}
