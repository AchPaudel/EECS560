#include <iostream>
#include "BinaryNode.h"
using namespace std;

template<typename ItemType>
LeftistMinTree<ItemType>::LeftistMinTree(){
    rootPtr = nullptr;
}

template<typename ItemType>
LeftistMinTree<ItemType>::~LeftistMinTree(){
    destroyTree(rootPtr);
}

template<typename ItemType>
void LeftistMinTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr){
  if (subTreePtr != nullptr){
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    delete subTreePtr;
  }
}

template<typename ItemType>
LeftistMinTree<ItemType>::LeftistMinTree(LeftistMinTree &rhs){
    rootPtr = nullptr;
    *this = rhs;
}

template<typename ItemType>
BinaryNode<ItemType>* LeftistMinTree<ItemType>::concat(LeftistMinTree &rhs){
    if(this != &rhs){
      rootPtr = concat(rootPtr, rhs.rootPtr);
      rhs.rootPtr = nullptr;
  }
}

template<typename ItemType>
BinaryNode<ItemType>* LeftistMinTree<ItemType>::concat(BinaryNode<ItemType>* leftist1, BinaryNode<ItemType>* leftist2){
    if (leftist1 == nullptr)
      return(leftist2);

    if (leftist2 == nullptr)
      return(leftist1);

    if ((leftist1->getItem()) < (leftist2->getItem()))
      return concatHelper(leftist1, leftist2);
    else
      return concatHelper(leftist2, leftist1);
}

template<typename ItemType>
BinaryNode<ItemType>* LeftistMinTree<ItemType>::concatHelper(BinaryNode<ItemType>* leftist1, BinaryNode<ItemType>* leftist2){
  if (leftist1->getLeftChildPtr() == nullptr){
    leftist1->setLeftChildPtr(leftist2);
  }
  else {
    leftist1->setRightChildPtr(concat(leftist1->getRightChildPtr(), leftist2));
    if ((leftist1->getLeftChildPtr()->getDistance()) < (leftist1->getRightChildPtr()->getDistance())){
      swapChild(leftist1);
    }

    leftist1->setDistance(leftist1->getRightChildPtr()->getDistance()+1);
  }

  return(leftist1);
}

template<typename ItemType>
void LeftistMinTree<ItemType>::swapChild(BinaryNode<ItemType>* parent){
  BinaryNode<ItemType>* tempNode = parent->getLeftChildPtr();
  parent->setLeftChildPtr(parent->getRightChildPtr());
  parent->setRightChildPtr(tempNode);
}

template<typename ItemType>
void LeftistMinTree<ItemType>::insert(ItemType &elem){
  BinaryNode<ItemType>* elemNode = new BinaryNode<ItemType>(elem, nullptr, nullptr, 0);
  rootPtr = concat(elemNode, rootPtr);
}

template<typename ItemType>
int LeftistMinTree<ItemType>::findMinimum(){
  return(rootPtr->getItem());
}

template<typename ItemType>
void LeftistMinTree<ItemType>::deleteMinimum(){
  BinaryNode<ItemType>* tempRootPtr = rootPtr;
  rootPtr = concat(rootPtr->getLeftChildPtr(), rootPtr->getRightChildPtr());
  delete tempRootPtr;
}

template<typename ItemType>
void LeftistMinTree<ItemType>::levelOrderPrint(){
  int height = getHeight(rootPtr);
  for(int i=1; i<=height; i++){
    levelOrderPrintHelper(rootPtr, i);
  }
}

template<typename ItemType>
void LeftistMinTree<ItemType>::levelOrderPrintHelper(BinaryNode<ItemType>* subTreePtr, int level){
  if (subTreePtr == nullptr){
    return;
  }

  if (level == 1){
    std::cout<<subTreePtr->getItem()<<" ";
  }
  else if (level > 1){
    levelOrderPrintHelper(subTreePtr->getLeftChildPtr(), level-1);
    levelOrderPrintHelper(subTreePtr->getRightChildPtr(), level-1);
  }
}

template<typename ItemType>
void LeftistMinTree<ItemType>::inOrderPrint(){
  inOrderPrintHelper(rootPtr);
}

template<typename ItemType>
void LeftistMinTree<ItemType>::inOrderPrintHelper(BinaryNode<ItemType>* subTreePtr){
if (subTreePtr == nullptr){
  return;
}

inOrderPrintHelper(subTreePtr->getLeftChildPtr());
std::cout<<subTreePtr->getItem()<<" ";
inOrderPrintHelper(subTreePtr->getRightChildPtr());

}

template<typename ItemType>
int LeftistMinTree<ItemType>::getHeight(BinaryNode<ItemType>* subTreePtr){
  if (subTreePtr == nullptr){
    return(0);
  } else {
    int left = getHeight(subTreePtr->getLeftChildPtr());
    int right = getHeight(subTreePtr->getRightChildPtr());

    if (left > right)
      return(left+1);
    else
      return(right+1);
  }
}
