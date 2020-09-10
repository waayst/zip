#include <iostream>
#include <fstream>
#include "ArchiveBuilder.h"
#include "BnReader.h"

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
	ArchiveBuilder archiver(fileToCompress, fileCompressed);
	archiver.archivate();
	BnReader reader;

	reader.startReading(fileCompressed);

	reader.readBlock();

	std::cout << *(reader.getBlockPtr()) << ' ' <<  reader.getBlockPtr()->size() << endl;
}
