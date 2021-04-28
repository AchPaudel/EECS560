#ifndef EXEC_H
#define EXEC_H
#include "LeftistMinTree.h"

class Exec
{
public:
    Exec(std::istream& inFile);
    ~Exec();
    void concatenate();
    void buildHeap();
    void run();
    void addItem();
    void deleteItem();
    int findMin();
    void deleteMin();
    void inOrderTraverse();
    void levelOrderTraverse();


private:
    LeftistMinTree<int> leftTree;
    int count = 0;

};

#endif
