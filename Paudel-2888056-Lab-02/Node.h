#ifndef NODE_H
#define NODE_H

template <typename T>
class Node // A node in a singly linked list
{
private:
	T item;
	Node* next; // we can only go "forward" along our chain
public:
	Node(T anItem) : item(anItem), next(nullptr) {}
	Node(T anItem, Node* nextNode) : item(anItem), next(nextNode) {}
	T getItem() const { return item; }
	Node* getNext() const { return next; }
	void setItem(T newItem) { item = newItem; }
	void setNext(Node* nextNode) { next = nextNode; }
};

#include "ListInterface.h"
#endif



























