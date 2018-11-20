#ifndef _SORTING_H_
#define _SORTING_H_

#include "Student.h"
#include <vector>

using namespace std;

void couting_sort_byGrade(vector<Student>& vec) {
	int arr[7] = { 0, };
	for (int i = 0; i < vec.size(); i++) {
		arr[vec[i].grade]++;
	}
	for (int i = 2; i < 7; i++) {
		arr[i] += arr[i - 1];
	}

	vector<Student> newVec = vec;
	for (int i = 0; i < vec.size(); i++) {
		newVec[--arr[vec[i].grade]] = vec[i];

	}

	vec = newVec;
}

void heapify(vector<Student>& vec, size_t size, size_t index) {
	size_t largest = index;
	size_t left = index * 2;
	size_t right = index * 2 + 1;
	if (left < size && vec[left].name.compare(vec[largest].name) > 0) {
		largest = left;
	}
	if (right < size && vec[right].name.compare(vec[largest].name) > 0) {
		largest = right;
	}
	
	if (largest != index) {
		swap(vec[index], vec[largest]);
		heapify(vec, size, largest);
	}
}

void heapSort_byName(vector<Student>& vec) {
	for (int i = (vec.size() - 1) / 2; i > 0; i--) {
		heapify(vec, vec.size(), i);
	}
	for (int i = vec.size() - 1; i > 0; i--) {
		swap(vec[1], vec[i]);
		heapify(vec, vec.size() - (vec.size() - i), 1);
	}
}


#endif
