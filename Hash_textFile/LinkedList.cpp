#include "LinkedList.h"



void LinkedList::clean()
{
	Node* destroyer = front_ptr;
	while (destroyer != nullptr) {
		front_ptr = front_ptr->next_ptr;
		delete destroyer;
		destroyer = front_ptr;
	}
	
	size = 0;
}

void LinkedList::copyFrom(const LinkedList & other)
{
	if (other.size != 0) {
		this->front_ptr = new Node(other.front_ptr->word);
		Node* copier = this->front_ptr;
		Node* toCopy = other.front_ptr;
		this->size = 1;
		while (toCopy->next_ptr != nullptr) {
			toCopy = toCopy->next_ptr;
			copier->next_ptr = new Node(toCopy->word);
			copier = copier->next_ptr;
			size++;
		}
	}
}

LinkedList::LinkedList(const LinkedList & other)
{
	copyFrom(other);
}

LinkedList & LinkedList::operator=(const LinkedList & other)
{
	if (this != &other) {
		clean();
		copyFrom(other);
	}
	return *this;
}

LinkedList::~LinkedList()
{
	clean();
}

void LinkedList::pushFront(const string & str)
{
	Node* temp = front_ptr;
	front_ptr = new Node(str, temp);
	size++;
}

