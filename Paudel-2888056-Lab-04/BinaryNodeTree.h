#ifndef BINARY_NODE_TREE
#define BINARY_NODE_TREE

#include "BinaryNode.h"
#include "NotFoundException.h"
#include <iostream>

template<class ItemType>
class BinaryNodeTree //:public BinaryTreeInterface<ItemType>
{

private:
   BinaryNode<ItemType>* rootPtr;

protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Helper methods for public methods.
   //------------------------------------------------------------
   int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const int& target, bool& success);
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodeToDeletePtr);
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodeToDeletePtr, ItemType& inorderSuccessor);
   bool isLeaf(BinaryNode<ItemType>* nodeToDeletePtr);
   void destroyTree(BinaryNode<ItemType>* subTreePtr);
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, int value) const;
   void inorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const;
   void preorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const;
   void postorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const;
   void levelOrderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr, int level, bool ltr);
   BinaryNode<ItemType>* inOrderAdd(BinaryNode<ItemType>* subPtr, BinaryNode<ItemType>* newNodePtr);
   BinaryNode<ItemType>* newTree(const BinaryNode<ItemType>* cTree) const;
   void leftSideViewHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr, int level, int* maxL);
   ItemType inorderSuccessorHelper(BinaryNode<ItemType>* subTreePtr, int value) const;
   void rightSideViewHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr, int level, int* maxL);
   //BinaryNode<ItemType>* getLeftmostNodeHelper(BinaryNode<ItemType>* nodeToGetPtr, ItemType& inorderSuccessor);

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinaryNodeTree(); // creates an empty BST
   //BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
   ~BinaryNodeTree();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getNumberOfNodes() const;
   void add(const ItemType& newEntry);
   bool remove(const int& value); //throw(NotFoundException);
   ItemType getEntry(const int& value) const; //throw(NotFoundException);
   bool contains(const int& value) const;
   ItemType getRootData() const;
   void setRootData(const ItemType& newData);
   void clear();
   //ItemType getLeftmostNode();
   int getHeight(BinaryNode<ItemType>* subTreePtr) const;
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void levelOrderTraverse(void visit(ItemType&), bool spiral);
   void preorderTraverse(void visit(ItemType&)) const;
   void inorderTraverse(void visit(ItemType&)) const;
   void postorderTraverse(void visit(ItemType&)) const;
   void leftSideView(void visit(ItemType&));
   void rightSideView(void visit(ItemType&));
   ItemType findMinValue();
   ItemType findMaxValue();
  ItemType inorderSuccessor(int entry);

   //------------------------------------------------------------
};
 // end BinaryNodeTree
#include "BinaryNodeTree.tpp"
#endif
