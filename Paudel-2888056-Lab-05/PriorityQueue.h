#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "EmptyHeap.h"
#include "EmptyPriorityQueue.h"
#include "Heap.h"


template <typename T>
class PriorityQueue
{
public:
	PriorityQueue(int initialSize);
	~PriorityQueue();

	void enqueue(T newEntry);
	void dequeue() /* throw EmptyPriorityQueue */;
	bool isEmpty() const;
	T peekFront() const /* throw EmptyPriorityQueue */;

private:
	Heap<T>* theHeap;
};

#include "PriorityQueue.cpp"
#endif
