#ifndef EXEC_H
#define EXEC_H
#include "BinaryNodeTree.h"

class Exec
{
public:
    Exec(std::istream& inFile);
    ~Exec();
    void run();
    void addItem();
    void deleteItem();
    int findMin();
    int findMax();
    void deleteMin();
    void deleteMax();
    void inorderSuccessor(int entry);
    void levelOrder();
    void spiralLevelOrder();
    void leftSideView();
    void rightSideView();
    void experimentalProfiling(double mValue);
    void addToArray(int& value);
    void expAddItem(int key);


private:
    BinaryNodeTree<int> searchTree;
    int count = 0;

};

#endif
