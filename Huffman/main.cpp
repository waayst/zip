#include <iostream>
#include <fstream>
#include "ArchiveBuilder.h"
#include "BnReader.h"
#include "TreeBuilder.h"
#include "Decoder.h"

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
	auto smth1 = reader.getBlockPtr();
	cout << *smth1 << endl;

	reader.readBlock();
	auto smth2 = reader.getBlockPtr();
	std::cout << *smth2;
	cout << endl << endl << endl << endl;

	TreeBuilder treeb(smth1, smth2);
	treeb.createTree();

	reader.readTextSize();
	auto sz = reader.getTextSize();
	reader.readBlock();
	auto smth3 = reader.getBlockPtr();
	Decoder decoder(sz, smth3, treeb.getCodesTree());
	cout << endl;
	decoder.decode();
	std::cout << endl << *decoder.getTextPtr();
}

