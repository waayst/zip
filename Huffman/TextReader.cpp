#include "TextReader.h"
using namespace std;

TextReader::TextReader() :textPtr(nullptr) {}

void TextReader::read(std::string filename) {
	ifstream file(filename);
	textPtr = new string{};
	string s;
	if (file.is_open()) {
		int step = 0;
		while (getline(file, s)) {
			if (step > 0) {
				*textPtr += '\n';
			}
			*textPtr += (s);
			step++;
		}
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