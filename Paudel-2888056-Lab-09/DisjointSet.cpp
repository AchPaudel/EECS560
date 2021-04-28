#include <iostream>
using namespace std;
em
template<typename ItemType>
DisjointSet<ItemType>::DisjointSet(){
    rankArr = new int[size];
//    cout<<"BREAKPOINT #2"<<endl;
}

template<typename ItemType>
DisjointSet<ItemType>::~DisjointSet(){
    for (int i=0; i<size; i++){
        delete distArr[i];
    }
    delete[] distArr;

    delete[] rankArr;
}

template<typename ItemType>
void DisjointSet<ItemType>::makeSet(ItemType initArr[]){
    for (int i=0; i < size; i++) {
        distArr[i] = new Node<ItemType>(initArr[i]);
        rankArr[i] = 0;
    }

}

template<typename ItemType>
Node<ItemType>* DisjointSet<ItemType>::findRep(Node<ItemType>* disjSet){
  if(disjSet->getParent() == disjSet){
    return(disjSet);
}
  else {
    return(findRep(disjSet->getParent()));
  }
}

template<typename ItemType>
bool DisjointSet<ItemType>::isInSet(int index){
    for (int i=0; i < size; i++){
        if (distArr[index] == distArr[i]){
            return(true);
        }
    }
    return false;
}

template<typename ItemType>
int DisjointSet<ItemType>::findReturn(int index){
    if (isInSet(index)){
    int indexOfRep = getIndex(findRep(distArr[index]));
    return(indexOfRep);
    }
    else
    return(-1);
}

template<typename ItemType>
void DisjointSet<ItemType>::unionByRankHelper(int index1, int index2){
    unionByRank(distArr[index1], distArr[index2]);
}


template<typename ItemType>
void DisjointSet<ItemType>::unionByRank(Node<ItemType>* elem1, Node<ItemType>* elem2){
    Node<ItemType>* rep1 = findRep(elem1);
    Node<ItemType>* rep2 = findRep(elem2);
    int index1 = getIndex(rep1);
    int index2 = getIndex(rep2);

    if ( rep1 == rep2 ){
      return;
    }

    if (rankArr[index1] < rankArr[index2]){
        rep1->setParent(rep2);
    }

    else if (rankArr[index1] > rankArr[index2]){
          rep2->setParent(rep1);
        }

    else {
        rep1->setParent(rep2);
        rankArr[index2] = rankArr[index2] + 1;
    }
}

template<typename ItemType>
int DisjointSet<ItemType>::getIndex(Node<ItemType>* indexOf){
    for(int i=0; i < size; i++){
        if (distArr[i] == indexOf){
            return(i);
        }
    }
    return(-1);
}


template<typename ItemType>
void DisjointSet<ItemType>::printDPath(int index){
  int parentIndex = getIndex(distArr[index]->getParent());
  if (distArr[index]->getParent() != distArr[parentIndex]) {
    cout<<"Element "<<index;
    cout<<"->";
    printDPath(parentIndex);
}
 else {
cout<<" -> Rep Element: "<<parentIndex+1<<"."<<endl;
}
}

template<typename ItemType>
Node<ItemType>* DisjointSet<ItemType>::pathComp(Node<ItemType>* disjSet){
    if(disjSet->getParent() == disjSet){
      return(disjSet);
  }

    else {
        Node<ItemType>* tempRep = findRep(disjSet->getParent());
        disjSet->setParent(tempRep);
      return(tempRep);
    }
}


template<typename ItemType>
int DisjointSet<ItemType>::pathHelper(int index){
    int repIndex = getIndex(pathComp(distArr[index]));
    return (repIndex);
}
