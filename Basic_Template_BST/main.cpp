#include <iostream>
#include "Tree.h"

using namespace std;


int main() {
	Tree<int> t;
	t.push(5);
	t.push(2);
	t.push(4);
	t.push(-10);
	t.push(9);
	t.push(21);

	Tree<int> temp = t;
	t.pop(4);
	t.pop(12);

	t.print();
	cout << endl;
	temp.print();

	return 0;
}
