#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
using namespace std;

template<typename T>
class Tree
{
private:
	struct Node {
		T data;
		Node* left_ptr;
		Node* right_ptr;

		Node(const T& dat, Node* left = nullptr, Node* right = nullptr) :
			data(dat),
			left_ptr(left),
			right_ptr(right) {}
	};

	Node* root;
	size_t size;

private:
	void copyFrom(Node*& copier, Node* const otherNode);
	void clean(Node*&);
	void pushElem(Node*& node, const T& elem);
	void popElem(Node*& node, const T& elem);
	void print_rec(Node* node) const;
	Node*& getGreatestLeft(Node*& node);

public:
	Tree();
	Tree(const Tree& other);
	Tree& operator=(const Tree& other);
	~Tree();

public:
	void push(const T&);
	void pop(const T&);
	void print()const;
};


template<typename T>
inline void Tree<T>::copyFrom(Node*& copier, Node* const toCopy) // we start with root as a copier and other.root as toCopy
{
	if (toCopy == nullptr) {
		this->root = nullptr;
		this->size = 0;
		return;
	}
	copier = new Node(toCopy->data);
	if (toCopy->left_ptr != nullptr) {
		copyFrom(copier->left_ptr, toCopy->left_ptr);
	}
	if (toCopy->right_ptr != nullptr) {
		copyFrom(copier->right_ptr, toCopy->right_ptr);
	}


}

template<typename T>
inline void Tree<T>::clean(Node*& node)
{
	if (node == nullptr)
		return;
	if (node->left_ptr == nullptr && node->right_ptr == nullptr) {
		delete node;
		node = nullptr;
		size--;
		return;
	}
	if (node->left_ptr != nullptr) {
		clean(node->left_ptr);
	}
	if (node->right_ptr != nullptr) {
		clean(node->right_ptr);
	}

	delete node;
	node = nullptr;
	size--;
}

template<typename T>
inline void Tree<T>::pushElem(Node*& node, const T & elem)
{
	if (node == nullptr) {
		node = new Node(elem);
		size++;
		return;
	}

	if (elem <= node->data) {
		pushElem(node->left_ptr, elem);
	}
	else if (elem > node->data) {
		pushElem(node->right_ptr, elem);
	}
}

template<typename T>
inline void Tree<T>::popElem(Node *& node, const T & elem)
{
	if (node == nullptr) {
		std::cout << "This elem is not in the tree\n";
		return;
	}
	if (node->data == elem && node->left_ptr == nullptr && node->right_ptr == nullptr) {
		delete node;
		node = nullptr;
		size--;
		return;
	}

	if (node->data == elem && node->right_ptr != nullptr && node->left_ptr != nullptr) {
		node->data = getGreatestLeft(node->right_ptr)->data;
		if (getGreatestLeft(node->right_ptr)->right_ptr != nullptr) {
			Node* temp = getGreatestLeft(node->right_ptr);
			getGreatestLeft(node->right_ptr) = temp->right_ptr;
			delete temp;
			return;
		}

		Node** temp_ptr = &getGreatestLeft(node->right_ptr);
		delete *temp_ptr;
		*temp_ptr = nullptr;
		size--;
		return;

	}

	if (node->data == elem && node->right_ptr != nullptr) {
		Node* destroy = node;
		node = destroy->right_ptr;
		delete destroy;
		size--;
		return;
	}
	if (node->data == elem && node->right_ptr == nullptr && node->left_ptr != nullptr) {
		Node* destroy = node;
		node = destroy->left_ptr;
		delete destroy;
		size--;
		return;
	}

	if (elem <= node->data) {
		popElem(node->left_ptr, elem);
	}
	else if (elem > node->data) {
		popElem(node->right_ptr, elem);
	}
}

template<typename T>
inline void Tree<T>::print_rec(Node * root) const
{
	if (root == nullptr) {
		return;
	}
	print_rec(root->left_ptr);
	cout << root->data << ' ';
	print_rec(root->right_ptr);
}

template<typename T>
inline typename Tree<T>::Node*& Tree<T>::getGreatestLeft(Node *& node)
{
	if (node->left_ptr == nullptr) {
		return node;
	}

	return getGreatestLeft(node->left_ptr);
}

template<typename T>
inline Tree<T>::Tree() : root(nullptr), size(0)
{
}

template<typename T>
inline Tree<T>::Tree(const Tree & other)
{
	copyFrom(this->root, other.root);
	this->size = other.size;
}

template<typename T>
inline Tree<T>& Tree<T>::operator=(const Tree& other)
{
	if (this != &other) {

		clean(this->root);
		copyFrom(this->root, other.root);
	}
	return *this;
}

template<typename T>
inline Tree<T>::~Tree()
{
	clean(root);
}

template<typename T>
inline void Tree<T>::push(const T& newElem)
{
	pushElem(root, newElem);
}

template<typename T>
inline void Tree<T>::pop(const T & elem)
{

	popElem(this->root, elem);
}

template<typename T>
inline void Tree<T>::print() const
{
	print_rec(this->root);
	cout << endl;
}

#endif
