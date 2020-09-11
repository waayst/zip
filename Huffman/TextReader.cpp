#include "TextReader.h"
using namespace std;

TextReader::TextReader() :textPtr(nullptr) {}

void TextReader::read(std::string filename) {
	ifstream file(filename, ios::binary | ios::in);
	textPtr = new string{};
	string s;
	char character;
	while (!file.eof()) {
		file.read(&character, sizeof character);
		textPtr->push_back(character);
	}
}

string* TextReader::getTextPtr() {
	return this->textPtr;
}

bool TextReader::fileIsEmpty() {
	return textPtr->empty();
}

TextReader::~TextReader() {
	safeDelete(textPtr);
}