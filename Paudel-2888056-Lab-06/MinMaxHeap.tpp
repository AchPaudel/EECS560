#include <iostream>
using namespace std;

template <typename T>
MinMaxHeap<T>::MinMaxHeap(T initArr[], int length){
    heapCount = length;
    size = length;
    hArr = new T[heapCount];
    for (int i=0; i<length; i++){
        hArr[i] = initArr[i];
        cout<<hArr[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
MinMaxHeap<T>::~MinMaxHeap(){
    delete[] hArr;
}

template <typename T>
void MinMaxHeap<T>::buildHeap(){
    for(int i=(size)/2; i>=0; i--){
        cout<<"Pre TrickleDown: "<<hArr[i]<<endl;
        trickleDown(i);
        cout<<"Post TrickleDown: "<<hArr[i]<<endl;
    }
}

template <typename T>
void MinMaxHeap<T>::trickleDown(int index){
    if ((int)floor(log2(index))%2==0){
        trickleMin(index);
        printAll();
    } else {
        trickleMax(index);
        printAll();
    }
    cout<<endl;
}


template <typename T>
int MinMaxHeap<T>::isGrandchildMin(int index){
    if (index<heapCount && index>=0){
        int leftChild = 2*index+1;
        int rightChild = 2*index+2;
        int grandLLIndex = 2*leftChild+1;
        int grandLRIndex = 2*leftChild+2;
        int grandRLIndex = 2*rightChild+1;
        int grandRRIndex = 2*rightChild+2;
        int smallIndex = -1;

        if (leftChild < heapCount){
            smallIndex = leftChild;
            if(hArr[leftChild] < hArr[smallIndex])
                smallIndex = leftChild;
        }

        if (rightChild < heapCount){
            if (hArr[rightChild] < hArr[smallIndex])
            smallIndex = rightChild;
        }

        if (grandLLIndex < heapCount){
            if (hArr[grandLLIndex] < hArr[smallIndex])
                smallIndex = grandLLIndex;
        }

        if (grandLRIndex < heapCount){
            if (hArr[grandLRIndex] < hArr[smallIndex])
                smallIndex = grandLRIndex;
        }

        if (grandRLIndex < heapCount){
            if (hArr[grandRLIndex] < hArr[smallIndex])
                smallIndex = grandRLIndex;
        }

        if (grandRRIndex < heapCount){
            if (hArr[grandRRIndex] < hArr[smallIndex])
                smallIndex = grandRRIndex;
        }

        return(smallIndex);
    }
    else {
        return(-1);
    }
}




template <typename T>
void MinMaxHeap<T>::trickleMin(int index){
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int parent = floor((index-1)/2);
    int grandLLIndex = 2*leftChild+1;
    int grandLRIndex = 2*leftChild+2;
    int grandRLIndex = 2*rightChild+1;
    int grandRRIndex = 2*rightChild+2;
    int smallIndex = isGrandchildMin(index);
    int smallParent = floor((smallIndex-1)/2);

    if (smallIndex != -1){
        //Make 2 different functions for smallest child and smallest grandchild. Compare to see which is smaller/larger in the next if statement.
        if ((smallIndex == grandLLIndex) || (smallIndex == grandLRIndex) || (smallIndex== grandRLIndex) || (smallIndex == grandRRIndex)){
            cout<<"Min: Small is grandchild"<<endl;
            if(hArr[smallIndex] < hArr[index]){
                swapArr(hArr[smallIndex], hArr[index]);

            if (hArr[smallIndex] > hArr[smallParent]){
                    swapArr(hArr[smallIndex], hArr[smallParent]);
                }

                trickleMin(smallIndex);
            }
        } else if (hArr[smallIndex] < hArr[index]){
            cout<<"Min: Child Swap: "<<smallIndex<<"->"<<index<<endl;
                swapArr(hArr[smallIndex], hArr[index]);
            }
    }
}


template <typename T>
int MinMaxHeap<T>::isGrandchildMax(int index){
    if (index<heapCount && index>=0){
        int leftChild = 2*index+1;
        int rightChild = 2*index+2;
        int grandLLIndex = 2*leftChild+1;
        int grandLRIndex = 2*leftChild+2;
        int grandRLIndex = 2*rightChild+1;
        int grandRRIndex = 2*rightChild+2;
        int largeIndex = -1;

        if (leftChild < heapCount){
            largeIndex = leftChild;
            if (hArr[leftChild] > hArr[largeIndex])
                largeIndex = leftChild;
        }

        if (rightChild < heapCount){
            if (hArr[rightChild] > hArr[largeIndex])
                largeIndex = rightChild;
        }

        if (grandLLIndex < heapCount){
            if (hArr[grandLLIndex] > hArr[largeIndex])
                largeIndex = grandLLIndex;
        }

        if (grandLRIndex < heapCount){
            if (hArr[grandLRIndex] > hArr[largeIndex])
                largeIndex = grandLRIndex;
        }

        if (grandRLIndex < heapCount){
            if (hArr[grandRLIndex] > hArr[largeIndex])
                largeIndex = grandRLIndex;
        }

        if (grandRRIndex < heapCount){
            if (hArr[grandRRIndex] > hArr[largeIndex])
                largeIndex = grandRRIndex;
        }

        return(largeIndex);
    }
    else {
        return(-1);
    }
}



template <typename T>
void MinMaxHeap<T>::trickleMax(int index){
    int leftChild = 2*index+1;
    int rightChild = 2*index+2;
    int parent = floor((index-1)/2);
    int grandLLIndex = 2*leftChild+1;
    int grandLRIndex = 2*leftChild+2;
    int grandRLIndex = 2*rightChild+1;
    int grandRRIndex = 2*rightChild+2;

    int largeIndex = isGrandchildMax(index);
    int largeParent = floor((largeIndex-1)/2);

    if (largeIndex != -1){
        //Make 2 different functions for smallest child and smallest grandchild. Compare to see which is smaller/larger in the next if statement.
        if ((largeIndex == grandLLIndex) || (largeIndex == grandLRIndex) || (largeIndex == grandRLIndex) || (largeIndex == grandRRIndex)){
            cout<<"Max: Large is grandchild"<<endl;
            if(hArr[largeIndex] > hArr[index]){
                swapArr(hArr[largeIndex], hArr[index]);

                if (hArr[largeIndex] < hArr[largeParent]){
                    swapArr(hArr[largeIndex], hArr[largeParent]);
                }

                trickleMax(largeIndex);
            }
        } else if (hArr[largeIndex] > hArr[index]){
            cout<<"Max: Child Swap: "<<largeIndex<<"->"<<index<<endl;
                swapArr(hArr[largeIndex], hArr[index]);
        }
    }
}


template <typename T>
void MinMaxHeap<T>::bubbleUp(int index){
    if(index != 0){
        int parent = floor((index-1)/2);
        if (index%2==0){
            if(parent<heapCount && parent >= 0){
                if(hArr[index] > hArr[parent]){
                    swapArr(hArr[index], hArr[parent]);
                    bubbleMax(parent);
                }
                else {
                    bubbleMin(index);
                }
            }
        }
        else {
            if(parent<heapCount && parent >= 0){
                if(hArr[index] < hArr[parent]){
                    swapArr(hArr[index], hArr[parent]);
                    bubbleMin(parent);
                }
                else {
                    bubbleMax(index);
                }
            }
        }

    }
}


template <typename T>
void MinMaxHeap<T>::bubbleMax(int index){
    int parent = floor((index-1)/2);
    int grandParent = floor(parent-1)/2;
    if ((grandParent<heapCount && grandParent >= 0) && (hArr[index]>hArr[grandParent])){
        swapArr(hArr[index], hArr[grandParent]);
        bubbleMax(grandParent);
    }
}


template <typename T>
void MinMaxHeap<T>::bubbleMin(int index){
    int parent = floor((index-1)/2);
    int grandParent = floor((parent-1)/2);
    if ((grandParent<heapCount && grandParent >= 0) && (hArr[index]<hArr[grandParent])){
        swapArr(hArr[index], hArr[grandParent]);
        bubbleMin(grandParent);
    }
}


template <typename T>
void MinMaxHeap<T>::insert(T element){
    if(heapCount == size-1){
        resize();
        size = size*3;
    }

    hArr[heapCount] = element;
    heapCount++;
    bubbleUp(heapCount-1);
}

template <typename T>
void MinMaxHeap<T>::resize(){
    T *tempArr = new T[heapCount];
    for (int i=0; i<heapCount; i++){
        tempArr[i] = hArr[i];
    }

    delete[] hArr;

    T *hArr = new T[heapCount*3];
    for (int i=0; i<heapCount; i++){
        hArr[i] = tempArr[i];
    }

    delete[] tempArr;
}

template <typename T>
void MinMaxHeap<T>::removeElem(){
    swapArr(hArr[0], hArr[heapCount-1]);
    hArr[heapCount-1] = 0;
    trickleDown(0);
    heapCount--;
}

template <typename T>
void MinMaxHeap<T>::minPrint(){
    cout << endl;
    cout << hArr[0] << " " << endl;
    int nextJump = 2, tempExponent = 2;
    for (int i = 0; i < heapCount; i++)
    {
        if (i > nextJump && i <= (nextJump + pow(2, tempExponent)))
        {
            if (hArr[i] == NULL)
            {
                cout << "- ";
            }
            else
            {
                cout << hArr[i] << " ";
            }

            if (i == (nextJump + pow(2, tempExponent)))
            {
                cout << endl;
                nextJump = nextJump + pow(2, tempExponent) + pow(2, (tempExponent + 1));
                tempExponent = tempExponent + 2;
            }
        }
    }
    cout << endl;
}

template <typename T>
void MinMaxHeap<T>::maxPrint(){
    cout << endl;
    int nextJump = 0, tempExponent = 1;
    for (int i = 0; i < heapCount; i++)
    {
        if (i > nextJump && i <= (nextJump + pow(2, tempExponent)))
        {
            if (hArr[i] == NULL)
            {
                cout << "- ";
            }
            else
            {
                cout << hArr[i] << " ";
            }

            if (i == (nextJump + pow(2, tempExponent)))
            {
                cout << endl;
                nextJump = nextJump + pow(2, tempExponent) + pow(2, (tempExponent + 1));
                tempExponent = tempExponent + 2;
            }
        }
    }
    cout << endl;
}

template <typename T>
void MinMaxHeap<T>::printAll(){
    cout << endl;
    int nextLevel = 0, tempExponent = 0;
    for (int i = 0; i < heapCount; i++)
    {
        //    if (hArr[i] == NULL)
        //    {
        //    cout << "- ";
        //    }
        //    else
        //    {
        cout << hArr[i] << " ";
        //}

        if (i == nextLevel)
        {
            cout << endl;
            tempExponent++;
            nextLevel = nextLevel + pow(2, tempExponent);
        }
    }
    cout << endl;
}

template <typename T>
void MinMaxHeap<T>::swapArr(T& val1, T& val2){
    T tempVal = val1;
    val1 = val2;
    val2 = tempVal;
}
