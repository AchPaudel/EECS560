#include <iostream>
#include <algorithm>

template <typename T>
Heap<T>::Heap(int initialSize){
    sizeOfArray = initialSize;
    heapItems = new T[sizeOfArray];
}

template <typename T>
Heap<T>::Heap(const Heap<T>& heap){

}

template <typename T>
Heap<T>::~Heap(){
    delete[] heapItems;
}

template <typename T>
int Heap<T>::Parent(int pos){
    if (numItemsInHeap>3)
        return ((pos-1)/2);
    else
        return 1;
}


template <typename T>
int Heap<T>::leftChildPos(int parPos){
    return ((2*parPos)+1);
}

template <typename T>
int Heap<T>::rightChildPos(int parPos){
    return ((2*parPos)+2);
}



template <typename T>
void Heap<T>::heapUp(int pos){

    if (heapItems[pos] > heapItems[Parent(pos)]) {
        std::swap(heapItems[Parent(pos)], heapItems[pos]);
        heapUp(Parent(pos));
    }
}

template <typename T>
void Heap<T>::add(T& newItem){
    if(numItemsInHeap == sizeOfArray){
        resize();
    }

    numItemsInHeap++;
    heapItems[numItemsInHeap-1] = newItem;
    heapUp(numItemsInHeap-1);
}

template <typename T>
bool Heap<T>::isEmpty() const{
    if (numItemsInHeap == 0){
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void Heap<T>::resize() {
    sizeOfArray = sizeOfArray *2;
    T* tempArr = new T[sizeOfArray];
    for(int i =0; i < ((sizeOfArray)/2);i++){
        tempArr[i] = heapItems[i];
    }
    delete[] heapItems;
    heapItems = tempArr;
}

template <typename T>
void Heap<T>::remove(){
    if (numItemsInHeap == 0){
        throw EmptyHeap("Cannot remove.");
      }
      else if (numItemsInHeap==1){
        numItemsInHeap=0;
      }

      else {
        std::swap(heapItems[0], heapItems[numItemsInHeap-1]);
        numItemsInHeap--;
        heapDown(0);
      }
}

template <typename T>
T Heap<T>::peekTop() const{
    if (numItemsInHeap != 0){
        return(heapItems[0]);
    }
    else {
        throw EmptyHeap("Cannot peak.");
    }
}

template <typename T>
void Heap<T>::heapDown(int pos){
  int leftpos = leftChildPos(pos);
  int rightpos = rightChildPos(pos);

  if(leftpos>numItemsInHeap &&rightpos > numItemsInHeap){
  }

  else if (leftpos < numItemsInHeap && rightpos >= numItemsInHeap){
    if (heapItems[pos] < heapItems[leftpos]){
      std::swap(heapItems[pos],heapItems[leftpos]);
      heapDown(leftpos);
    }
  }

  else if (rightpos < numItemsInHeap){
    if (heapItems[pos] < heapItems[rightpos] || heapItems[pos] < heapItems[leftpos]){
      if(heapItems[leftpos]> heapItems[rightpos]){
        std::swap(heapItems[pos],heapItems[leftpos]);
        heapDown(leftpos);
      }
      else {
        std::swap(heapItems[pos],heapItems[rightpos]);
        heapDown(rightpos);
      }
    }
  }
}
