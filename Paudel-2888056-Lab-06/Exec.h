#ifndef EXEC_H
#define EXEC_H
#include "MinMaxHeap.h"
#include <iostream>
#include <fstream>

class Exec
{
public:
    Exec(std::istream& inFile);
    ~Exec();
    void buildHeap();
    void add();
    void run();
    void remove();
    void minLevel();
    void maxLevel();
private:
  int count=0;
  int *initArr;
  MinMaxHeap<int>* heapObj;

};

#endif
