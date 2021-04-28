#ifndef EXEC_H
#define EXEC_H
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Exec {
public:
    Exec(istream& listStream);
    ~Exec();
    void run();
    void isEmpty();
    int Length();
    void Insert();
    void Delete(int x);
    void findElem(int x);
    void findPrevElem(int x);
    void AppendList();
    void ForwardTraverse();
    void BackwardTraverse();

private:
    int position = 0;
    LinkedList<int> list;
};

#endif
