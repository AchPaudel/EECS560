#ifndef LEFTIST_MIN_TREE
#define LEFTIST_MIN_TREE

#include "BinaryNode.h"
#include <iostream>

template<class ItemType>
class LeftistMinTree
{

private:
  BinaryNode<ItemType>* rootPtr;


protected:
  BinaryNode<ItemType>* concatHelper(BinaryNode<ItemType>* leftist1, BinaryNode<ItemType>* leftist2);
  void swapChild(BinaryNode<ItemType>* parent);
  void inOrderPrintHelper(BinaryNode<ItemType>* subTreePtr);
  void levelOrderPrintHelper(BinaryNode<ItemType>* subTreePtr, int level);

public:
  LeftistMinTree();
  LeftistMinTree(LeftistMinTree &rhs);
  ~LeftistMinTree();
  void destroyTree(BinaryNode<ItemType>* subTreePtr);
  int findMinimum();
  void insert(ItemType &elem);
  void deleteMinimum();
  void deleteMinimum(int &minItem);
  void makeEmpty();
  void levelOrderPrint();
  void inOrderPrint();
  int getHeight(BinaryNode<ItemType>* subTreePtr);
  BinaryNode<ItemType>* concat(LeftistMinTree &rhs);
  BinaryNode<ItemType>* concat(BinaryNode<ItemType>* leftist1, BinaryNode<ItemType>* leftist2);
 

    //------------------------------------------------------------
  };
  // end BinaryNodeTree
  #include "LeftistMinTree.tpp"
  #endif
