#ifndef BINARY_NODE
#define BINARY_NODE

template<class ItemType>
class BinaryNode
{
private:
   ItemType              item;           // Data portion
   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child
   int distance;

public:
   BinaryNode(const ItemType& anItem): item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr), distance(0) {}
   BinaryNode(const ItemType& anItem,
              BinaryNode<ItemType>* leftPtr,
              BinaryNode<ItemType>* rightPtr,
              int aDistance): item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr), distance(aDistance){}

   void setItem(const ItemType& anItem){ item = anItem; }
   ItemType getItem() const { return item; }

   bool isLeaf() const {
       if (leftChildPtr == nullptr && rightChildPtr == nullptr)
            return true;
       else
            return false;
    }

   int getDistance() const { return distance; }
   void setDistance(int dist) { distance = dist; }

   BinaryNode<ItemType>* getLeftChildPtr() const { return leftChildPtr; }
   BinaryNode<ItemType>* getRightChildPtr() const { return rightChildPtr; }

   void setLeftChildPtr(BinaryNode<ItemType>* leftPtr) { leftChildPtr = leftPtr; }
   void setRightChildPtr(BinaryNode<ItemType>* rightPtr) { rightChildPtr = rightPtr; }
}; // end BinaryNode

#endif
