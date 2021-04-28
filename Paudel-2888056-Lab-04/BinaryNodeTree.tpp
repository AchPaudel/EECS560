#include <iostream>
//#include "BinaryNodeTree.h"
//using namespace std;


template<typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(){
    rootPtr = nullptr;
}

template<typename ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree(){
    destroyTree(rootPtr);
}

template<typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::newTree(const BinaryNode<ItemType>* cTree) const{
    BinaryNode<ItemType>* newPtr = nullptr;
    if (cTree != nullptr){
        newPtr = new BinaryNode<ItemType>(cTree->getItem());
        newPtr->setLeftChildPtr(newTree(cTree->getLeftChildPtr()));
        newPtr->setRightChildPtr(newTree(cTree->getRightChildPtr()));
    }

    return newPtr;
}


template<typename ItemType>
void BinaryNodeTree<ItemType>::add(const ItemType& newData){
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
    rootPtr = inOrderAdd(rootPtr,newNodePtr);
}


template<typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::inOrderAdd(BinaryNode<ItemType>* subPtr, BinaryNode<ItemType>* newNodePtr){
    if(subPtr == nullptr){
        return newNodePtr;
    }

    else if(newNodePtr->getItem() < subPtr->getItem()) {
        BinaryNode<ItemType>* tempPtr = inOrderAdd(subPtr ->getLeftChildPtr(), newNodePtr);
        subPtr->setLeftChildPtr(tempPtr);
    }

    else {
        BinaryNode<ItemType>* tempPtr = inOrderAdd(subPtr ->getRightChildPtr(), newNodePtr);
        subPtr->setRightChildPtr(tempPtr);
    }

    return subPtr;

}


template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const int& value) const{
    BinaryNode<ItemType>* foundPtr = findNode(rootPtr, value);

    int foundItemNum = foundPtr->getItem();

    if (!contains(foundItemNum)){
        throw NotFoundException("No item found for given value.");
    }
    else
        return (foundPtr->getItem());
}


template<typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* subPtr, int value) const{
    if (subPtr == nullptr)
        return nullptr;
    else if(subPtr->getItem() == value)
        return subPtr;
    else if(subPtr->getItem() > value)
        return findNode(subPtr->getLeftChildPtr(), value);
    else
        return findNode(subPtr->getRightChildPtr(), value);
}



template<typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const{
    if(subTreePtr == NULL)
       return 0;
   else
       return (1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr()));
}



template<typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const{
    if (rootPtr == nullptr)
        return true;
    else
        return false;
}


template<typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const{
    return (getNumberOfNodesHelper(rootPtr));
}

template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {
    return rootPtr->getItem();
}


template<typename ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData) {
    rootPtr->setItem(newData);
}


template<typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const int& value) {
    bool success = false;
    rootPtr = removeValue(rootPtr, value, success);

    if (success == false){
        throw NotFoundException("Could not remove value");
    }
    else
        return success;
}

template<typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const int& target, bool& success){
    if (subTreePtr == nullptr){
        success = false;
        return nullptr;
    }

    else if (subTreePtr->getItem() == target){
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }

    else if(subTreePtr->getItem() > target){
        BinaryNode<ItemType>* temp = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(temp);
        return subTreePtr;
    }
    else {
        BinaryNode<ItemType>* temp = removeValue(subTreePtr->getRightChildPtr(), target, success);
        subTreePtr->setRightChildPtr(temp);
        return subTreePtr;
    }
}


template<typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeNode(BinaryNode<ItemType>* nodeToDeletePtr){
    //No child pointers
    if (nodeToDeletePtr->isLeaf()){
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        return nodeToDeletePtr;
    }

    //One child point
    else if ((nodeToDeletePtr->getLeftChildPtr()==nullptr && nodeToDeletePtr->getRightChildPtr()!=nullptr) || (nodeToDeletePtr->getLeftChildPtr()!=nullptr && nodeToDeletePtr->getRightChildPtr()==nullptr)){
        BinaryNode<ItemType>* connectPtr;

        if(nodeToDeletePtr->getLeftChildPtr() == nullptr)
            connectPtr = nodeToDeletePtr->getRightChildPtr();
        else
            connectPtr = nodeToDeletePtr->getLeftChildPtr();

        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        return connectPtr;

    }

    //Two children
    else {
        ItemType inorderSuccessor;
        BinaryNode<ItemType>* temp = removeLeftmostNode(nodeToDeletePtr->getRightChildPtr(), inorderSuccessor);
        nodeToDeletePtr->setRightChildPtr(temp);
        nodeToDeletePtr->setItem(inorderSuccessor);
    }

    return nodeToDeletePtr;
}


template<typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodeToDeletePtr, ItemType& inorderSuccessor){
    if(nodeToDeletePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = nodeToDeletePtr->getItem();
        return removeNode(nodeToDeletePtr);
    }

    else {
        nodeToDeletePtr->setLeftChildPtr(removeLeftmostNode(nodeToDeletePtr->getLeftChildPtr(), inorderSuccessor));
        return nodeToDeletePtr;
    }
}

template<typename ItemType>
bool BinaryNodeTree<ItemType>::isLeaf(BinaryNode<ItemType>* nodeToDeletePtr){
    if (((nodeToDeletePtr->getLeftChildPtr())==nullptr) && ((nodeToDeletePtr->getRightChildPtr())==nullptr))
        return true;
    else
        return false;
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::clear() {

}

template<typename ItemType>
bool BinaryNodeTree<ItemType>::contains(const int& value) const{
    if (findNode(rootPtr, value))
        return true;
    else
        return false;
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const{
    preorderHelper(visit, rootPtr);
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorderHelper(visit, rootPtr);
}


template<typename ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorderHelper(visit, rootPtr);
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::levelOrderTraverse(void visit(ItemType&), bool spiral) {
    int hValue = getHeight(rootPtr);

    for (int i=1; i<hValue; i++){
      if (spiral) {
        if (i%2==0){
          levelOrderHelper(visit, rootPtr, i, false);
        } else {
          levelOrderHelper(visit, rootPtr, i, true);
        }
      }
      else {
        levelOrderHelper(visit, rootPtr, i, false);
      }
    }
}



template<typename ItemType>
int BinaryNodeTree<ItemType>::getHeight(BinaryNode<ItemType>* subTreePtr) const{
  if (subTreePtr == nullptr){
    return(-1);
  }
  else {
        int lHeight = getHeight(subTreePtr->getLeftChildPtr());
        int rHeight = getHeight(subTreePtr->getRightChildPtr());

        if(rHeight > lHeight){
          return(rHeight+1);
        } else {
          return(lHeight+1);
        }
      }
}


template<typename ItemType>
void BinaryNodeTree<ItemType>::levelOrderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr, int level, bool ltr) {
    if (subTreePtr != nullptr) {
        if (level == 1){
          ItemType anItem = subTreePtr->getItem();
          visit(anItem);
        }
        else {
          if (!ltr){
          levelOrderHelper(visit, subTreePtr->getLeftChildPtr(), level-1, ltr);
          levelOrderHelper(visit, subTreePtr->getRightChildPtr(), level-1, ltr);
        } else {
          levelOrderHelper(visit, subTreePtr->getRightChildPtr(), level-1, ltr);
          levelOrderHelper(visit, subTreePtr->getLeftChildPtr(), level-1, ltr);
        }
        }
    }
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::leftSideView(void visit(ItemType&)){
  int maxL = 0;
  leftSideViewHelper(visit, rootPtr, 1, &maxL);
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::leftSideViewHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr, int level, int* maxL){
  if (subTreePtr != nullptr){
      if (*maxL < level){
        ItemType anItem = subTreePtr->getItem();
        visit(anItem);
        *maxL = level;
      }
    leftSideViewHelper(visit, subTreePtr->getLeftChildPtr(), level+1, maxL);
    leftSideViewHelper(visit, subTreePtr->getRightChildPtr(), level+1, maxL);
  }
}


template<typename ItemType>
void BinaryNodeTree<ItemType>::rightSideView(void visit(ItemType&)){
  int maxL = 0;
  rightSideViewHelper(visit, rootPtr, 1, &maxL);
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::rightSideViewHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr, int level, int* maxL){
  if (subTreePtr != nullptr){
      if (*maxL < level){
        ItemType anItem = subTreePtr->getItem();
        visit(anItem);
        *maxL = level;
      }
    rightSideViewHelper(visit, subTreePtr->getRightChildPtr(), level+1, maxL);
    rightSideViewHelper(visit, subTreePtr->getLeftChildPtr(), level+1, maxL);
  }
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::inorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const{
    if(subTreePtr != nullptr){
    inorderHelper(visit, subTreePtr->getLeftChildPtr());

    ItemType anItem = subTreePtr->getItem();
    visit(anItem);

    inorderHelper(visit, subTreePtr->getRightChildPtr());
    }
}

template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::inorderSuccessor(int entry){
  return(inorderSuccessorHelper(rootPtr, entry));
}

template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::inorderSuccessorHelper(BinaryNode<ItemType>* subTreePtr, int value) const{
    if(subTreePtr != nullptr){
    inorderSuccessorHelper(subTreePtr->getLeftChildPtr(), value);


    if(subTreePtr->getItem() == value){
      if (subTreePtr->getRightChildPtr() != nullptr)
        return(subTreePtr->getRightChildPtr()->getItem());
      else
        return subTreePtr->getLeftChildPtr()->getItem();
    }

    inorderSuccessorHelper(subTreePtr->getRightChildPtr(), value);
    }
}



template<typename ItemType>
void BinaryNodeTree<ItemType>::postorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const{
    if(subTreePtr != nullptr){
        postorderHelper(visit, subTreePtr->getLeftChildPtr());
        postorderHelper(visit, subTreePtr->getRightChildPtr());
        ItemType anItem = subTreePtr->getItem();
        visit(anItem);
    }
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::preorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const{
    if(subTreePtr != nullptr){
        ItemType anItem = subTreePtr->getItem();
        visit(anItem);
        preorderHelper(visit, subTreePtr->getLeftChildPtr());
        preorderHelper(visit, subTreePtr->getRightChildPtr());
    }
}

template<typename ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr){
    if(subTreePtr != NULL) {
       destroyTree(subTreePtr->getLeftChildPtr());
       destroyTree(subTreePtr->getRightChildPtr());
       delete subTreePtr;
    }
}

template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::findMinValue(){
  BinaryNode<ItemType>* current = rootPtr;

  while (current->getLeftChildPtr() != nullptr){
    current = current->getLeftChildPtr();
  }

  return(current->getItem());
}


template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::findMaxValue(){
  BinaryNode<ItemType>* current = rootPtr;

  while (current->getRightChildPtr() != nullptr){
    current = current->getRightChildPtr();
  }

  return(current->getItem());
}


/*template<typename ItemType>
ItemType BinaryNodeTree<ItemType>::getLeftmostNode(){
  BinaryNode<ItemType>* leftNodePtr = getLeftmostNodeHelper(rootPtr, rootPtr->getItem());
  return (leftNodePtr->getItem());
}



template<typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::getLeftmostNodeHelper(BinaryNode<ItemType>* nodeToGetPtr, ItemType& inorderSuccessor){
    if(nodeToGetPtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = nodeToGetPtr->getItem();
        return nodeToGetPtr;
    }

    else {
        nodeToGetPtr->setLeftChildPtr(getLeftmostNodeHelper(nodeToGetPtr->getLeftChildPtr(), inorderSuccessor));
        return nodeToGetPtr;
    }
}
*/
