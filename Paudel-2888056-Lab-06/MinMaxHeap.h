#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H
#include <math.h>

template <typename T>
class MinMaxHeap
{
public:
	MinMaxHeap(T initArr[], int length);
	~MinMaxHeap();
	void insert(T element);
	void trickleDown(int index);
	int isGrandchildMin(int index);
	int isGrandchildMax(int index);
	void buildHeap();
	void trickleMin(int index);
	void trickleMax(int index);
	void bubbleUp(int index);
	void bubbleMax(int index);
	void bubbleMin(int index);
	void resize();
	void removeElem();
	void minPrint();
	void maxPrint();
	void printAll();
	void swapArr(T& val1, T& val2);

private:
	T *hArr;
	int heapCount=0;
	int size=0;
};

#include "MinMaxHeap.tpp"
#endif
