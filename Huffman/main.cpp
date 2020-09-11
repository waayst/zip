#include <iostream>
#include <fstream>
#include "ArchiveBuilder.h"
#include "BnReader.h"
#include "TreeBuilder.h"
#include "Decoder.h"
#include "TextWriter.h"
#include "UnarchiveBuilder.h"

using namespace std;
class d {
public:
	ifstream* file;
	void sh() {
		file = new ifstream("file.bn", ios::binary | ios::in);
	}
};

int main() {
	using namespace std;

	string fileToCompress = "ab.txt";
	string fileCompressed = "ab.bn";
	string fileDecompressed = "abc.bn";
	ArchiveBuilder archiver(fileToCompress, fileCompressed);
	archiver.archivate();

	UnarchiveBuilder unarchiver(fileCompressed, fileDecompressed);
	unarchiver.unarchivate();
}

