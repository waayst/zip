#include "BNode.h"
#include "BnReader.h"
#include "TreeBuilder.h"
#include "Decoder.h"
#include "TextWriter.h"

class UnarchiveBuilder{
public:
	UnarchiveBuilder();
	UnarchiveBuilder(std::string fileToDecompressName,
		std::string fileDecompressedName);
	void unarchivate();
	~UnarchiveBuilder();

private:
	bool fileIsEmpty();
	void startReading();
	void buildTree();
	void decode();
	void write();
	void writeEmptyFile();
	BnReader* reader;
	TreeBuilder* treeBuilder;
	Decoder* decoder;
	TextWriter* writer;

	std::string fileToDecompressName;
	std::string fileDecompressedName;
};