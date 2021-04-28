template <typename T>
PriorityQueue<T>::PriorityQueue(int initialSize){
    theHeap = new Heap<T>(initialSize);
}


template <typename T>
PriorityQueue<T>::~PriorityQueue(){
    delete theHeap;
}

template <typename T>
void PriorityQueue<T>::enqueue(T newEntry){
    theHeap->add(newEntry);
}

template <typename T>
void PriorityQueue<T>::dequeue(){
    try {
    theHeap->remove();
    }
    catch(EmptyHeap &e){
        throw EmptyPriorityQueue("Cannot remove from Queue.");
    }
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const{
    return (theHeap->isEmpty());
}

template <typename T>
T PriorityQueue<T>::peekFront() const{
    try {
    return (theHeap->peekTop());
    }
    catch (EmptyHeap &e) {
        throw EmptyPriorityQueue("Cannot peak Queue.");
    }
}
