#include <iostream>
#include "ArchiveBuilder.h"
#include "UnarchiveBuilder.h"

int main() {
	using namespace std;

	string fileToCompress = "TestToCompress.txt";
	string fileCompressed = "TestCompressed.bn";
	string fileDecompressed = "TestDecompressed.bn";
	ArchiveBuilder archiver(fileToCompress, fileCompressed);
	archiver.execute();
	UnarchiveBuilder unarchiver(fileCompressed, fileDecompressed);
	unarchiver.execute();
	std::cout << "done";
}