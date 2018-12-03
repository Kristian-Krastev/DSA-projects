#include "Hash.h"
#include <regex>

void Table::read_from_file(const string& file_name)
{
	ifstream ifs(file_name);
	size_t numOfWords = 0;
	string str;
	std::regex reg("[a-z|A-Z]+");
	while (!ifs.eof()) {

		ifs >> str;
		if (std::regex_match(str, reg)) {

			numOfWords++;
		}
	}
	ifs.clear();
	ifs.seekg(0, std::ios::beg);
	vec = vector<LinkedList>(numOfWords);

	std::hash<string> str_hash;

	while (!ifs.eof()) {

		ifs >> str;
		if (!std::regex_match(str, reg)) {
			continue;
		}
		size_t index = str_hash(str) % vec.size();
		if (vec[index].getSize() == 0) {
			vec[index].pushFront(str);
			continue;
		}
		if (vec[index].getName() == str) {
			vec[index].pushFront(str);
			continue;
		}
		for (int i = index; i < vec.size(); i++) {
			if (vec[i].getSize() == 0) {
				vec[i].pushFront(str);
				break;
			}
			if (vec[i].getName() == str) {
				vec[i].pushFront(str);
				break;
			}
			if (i == vec.size() - 1) {
				i = 0;
			}
		}

	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].getSize() == 0)
			continue;

		cout << '\"' << vec[i].getName() << '\"' << " is used " << vec[i].getSize() << " times\n";
	}
}

Table::Table(const string& file_name)
{
	read_from_file(file_name);
}

