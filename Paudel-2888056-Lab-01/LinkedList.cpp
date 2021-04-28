// The copy constructor, destructor, and the methods clear and setEntry are left as exercises.
// ===================================================================

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include <cassert>
#include <iostream>
#include "PrecondViolatedExcep.h"
using namespace std;

template<class ItemType>
LinkedList<ItemType>::LinkedList(){
	headPtr = nullptr;
	itemCount = 0;
}


template<class ItemType>
LinkedList<ItemType>::LinkedList(const ItemType& aList)
{
	headPtr = aList.headPtr;
	itemCount = aList.itemCount;
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
	// throw (PrecondViolatedExcep)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }
	else
		throw PrecondViolatedExcep("Cannot insert element");
}   //end insert

template<class ItemType>
void LinkedList<ItemType>::remove(int position) // throw(PrecondViolatedExcep)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);

         // Point to node to delete
         curPtr = prevPtr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after

         prevPtr->setNext(curPtr->getNext());
      }  // end if

      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;

      itemCount--;  // Decrease count of entries
   }
	else
		throw PrecondViolatedExcep("Cannot remove item");
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while(!isEmpty()){
		remove(1);
	}
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const // throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      throw PrecondViolatedExcep("Could not get entry.");
   }  // end if
}  // end getEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );

   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();

   return curPtr;
}  // end getNodeAt

template<class ItemType>
bool LinkedList<ItemType>::find(ItemType& entry) const {
	Node<ItemType>* newNodePtr = new Node<ItemType>(entry);
	for(int i=1; i<=getLength(); i++){
		if ((getNodeAt(i)->getItem()) == (newNodePtr->getItem())){
			return(true);
		}
	}
	return(false);
}

template<class ItemType>
ItemType LinkedList<ItemType>::findPrev(ItemType& findEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	if ((isEmpty()) || (getLength()==1) || (curPtr->getItem()==findEntry)) {
		throw PrecondViolatedExcep("None.");
	} else {
		if (find(findEntry)){
			for (int i=0; i<getLength(); i++){
				if((curPtr->getNext()->getItem()) == (findEntry)){
					return (curPtr->getItem());
				} else {
					curPtr = curPtr->getNext();
				}
			}
		}
		else {
			throw PrecondViolatedExcep("Element not found.");
		}
	}
}

/*template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) // throw(PrecondViolatedExcep)
{
	bool nodeExists = (position >= 1) && (position<=itemCount);

	if(nodeExists){
		Node<ItemType>* node = getNodeAt(position);
		node->setItem(newEntry);
	}
	 else {
		throw PrecondViolatedExcep("Cannot Set Entry.");
	}
}

//  End of implementation file.


secondintoLast = m_front;

if (isEmpty())
	return isRemoved;
else if (m_size == 1)
	removeFront();
else
	{
		while (secondintoLast->getNext()->getNext() != nullptr){
			secondintoLast = secondintoLast->getNext();
		}

		lastNode = secondintoLast->getNext();
		lastNode->setNext(nullptr);
		delete lastNode;
		lastNode = nullptr;
		secondintoLast -> setNext(nullptr);
		m_size--;
		isRemoved = true;
	}
*/
