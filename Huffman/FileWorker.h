#pragma once
#include "FileReader.h"
#include "FileWriter.h"
/*
 *Class FileWorker is a base class for classes ArchiveBuilder and UnarchiveBuilder. 
 */
class FileWorker {
public:
	FileWorker();
	FileWorker           (std::string fileToReadName,
		                  std::string fileToSaveName);
	~FileWorker();

	void execute         (std::string newFileToReadName,
		                  std::string newFileToSaveName);
	void execute();
	
	std::string getFileToReadName() const;
	std::string getFileToSaveName() const;
	void setFileToReadName(std::string newFileToReadName);
	void setFileToSaveName(std::string newFileToSaveName);

protected:
	virtual void openFile() = 0;
	void read();
	virtual void workWithReadData() = 0;
	virtual void write() = 0;
	void writeEmptyFile();

	std::string fileToReadName;
	std::string fileToSaveName;
	FileReader* reader = nullptr;
	FileWriter* writer = nullptr;
};