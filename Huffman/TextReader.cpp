#include "TextReader.h"
#
using namespace std;

TextReader::TextReader()  {}

void TextReader::read(std::string filename) {
	ifstream file(filename, ios::binary | ios::in);
	textPtr = new string{};
	char character;
	if (!file.is_open()) {
		fileOpen = false;
		return;
	}
	if (file.peek() == EOF) {
		fileEmptiness = true;
		return;
	}

	while (!file.eof()) {
		file.read(&character, sizeof character);
		textPtr->push_back(character);
	}
}

string* TextReader::getTextPtr() {
	return this->textPtr;
}

bool TextReader::fileIsOpened() {
	return fileOpen;
}

bool TextReader::fileIsEmpty() {
	return fileEmptiness;
}

TextReader::~TextReader() {
	safeDelete(textPtr);
}