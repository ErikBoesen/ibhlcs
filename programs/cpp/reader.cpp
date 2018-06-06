#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Reader {
public:
	Reader(const string language, int language_index);

	/*int get_ngram(vector<double> &ngram);
	int get_language_index() { return this->language_index; }*/

private:
	ifstream data_file;
	string language;
	int language_index;
	int num_languages;
};

Reader::Reader(const string language, int language_index) {
	this->language = language;
	this->language_index = language_index;
	this->data_file.open("data/languages/" + language);
}

int main() {
    vector<Reader> readers;
    readers.push_back(Reader("MSSMenulet", 44));
}
