#include <iostream>
#include "ArchiveBuilder.h"
#include "UnarchiveBuilder.h"

int main() {
	using namespace std;

	string fileToCompress = "TestToCompress.txt";
	string fileCompressed = "TestCompressed.bn";
	string fileDecompressed = "TestDecompressed.bn";
	ArchiveBuilder archiver(fileToCompress, fileCompressed);
	archiver.archivate();
	UnarchiveBuilder unarchiver(fileCompressed, fileDecompressed);
	unarchiver.unarchivate();
}

