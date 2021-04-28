#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap // a max Heap
{
public:
	Heap(int initialSize);
	Heap(const Heap<T>& heap); // The copy constructor
	~Heap();

	void add(T& newItem);
	bool isEmpty() const;
	void remove() /* throw EmptyHeap */;
	T peekTop() const /* throw EmptyHeap */;
private:
	T *heapItems;
	int sizeOfArray;
	int numItemsInHeap=0;
	int leftChildPos(int pos);
	int rightChildPos(int pos);
	int Parent(int pos);
	void heapUp(int pos);
	void heapDown(int pos);
	void resize();
};

#include "Heap.cpp"
#endif
