#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <string>

using std::string;
const size_t MAX_NODES = 10;

class LinkedList
{
private:
	struct Node {
		string word;
		Node* next_ptr;

		Node(const string& w, Node* next = nullptr) : word(w), next_ptr(next) {}
	};
	Node* front_ptr;
	size_t size;

private:
	void clean();
	void copyFrom(const LinkedList& other);

public:
	LinkedList() : size(0), front_ptr(nullptr) {}
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();

	void pushFront(const string& str);

	size_t getSize() const { return size; }
	const string getName()const { return front_ptr->word; }

};

#endif