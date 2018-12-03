#ifndef _HASH_H_
#define _HASH_H_

#include "LinkedList.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <functional>

using std::vector;
using std::ifstream;
using std::getline;
using std::cout;
using std::cin;
using std::hash;


class Table {
private:
	vector<LinkedList> vec;

public:
	Table(const string& file_name);

	void read_from_file(const string& file_name);
};



#endif