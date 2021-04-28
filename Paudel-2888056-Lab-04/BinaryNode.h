//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */

#ifndef BINARY_NODE
#define BINARY_NODE

template<class ItemType>
class BinaryNode
{
private:
   ItemType              item;           // Data portion
   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
   BinaryNode(const ItemType& anItem): item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {}
   BinaryNode(const ItemType& anItem,
              BinaryNode<ItemType>* leftPtr,
              BinaryNode<ItemType>* rightPtr): item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr){}

   void setItem(const ItemType& anItem){ item = anItem; }
   ItemType getItem() const { return item; }

   bool isLeaf() const {
       if (leftChildPtr == nullptr && rightChildPtr == nullptr)
            return true;
       else
            return false;
    }

   BinaryNode<ItemType>* getLeftChildPtr() const { return leftChildPtr; }
   BinaryNode<ItemType>* getRightChildPtr() const { return rightChildPtr; }

   void setLeftChildPtr(BinaryNode<ItemType>* leftPtr) { leftChildPtr = leftPtr; }
   void setRightChildPtr(BinaryNode<ItemType>* rightPtr) { rightChildPtr = rightPtr; }
}; // end BinaryNode

#endif
