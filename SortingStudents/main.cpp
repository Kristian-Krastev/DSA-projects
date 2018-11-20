#include "sorting.h"
#include <iostream>
int main() {
	vector<Student> vec;
	ifstream ifs("Students.txt");
	Student pesho;
	Student gosho;
	ifs >> gosho;
	while (!ifs.eof()) {

		ifs >> pesho;
		vec.push_back(pesho);
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << endl;
	couting_sort_byGrade(vec);
	cout << "CountingSorting by grade: \n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << endl;

	vector<Student> vec_names;
	vec_names.push_back(gosho);
	for (int i = 0; i < vec.size(); i++) {
		vec_names.push_back(vec[i]);
	}
	
	heapSort_byName(vec_names);
	cout << "HeapSorting by names: \n";
	for (int i = 1; i < vec_names.size(); i++) {
		cout << vec_names[i];
	}
	return 0;
}