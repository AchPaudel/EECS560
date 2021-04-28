#ifndef EXEC_H
#define EXEC_H
#include "PriorityQueue.h"
#include "Requests.h"
#include "EmptyPriorityQueue.h"
#include <iostream>
#include <fstream>

class Exec
{
public:
    Exec();
    ~Exec();
    void run(std::istream& inFile);
    void showStatus(PriorityQueue<Requests> pQue);
private:
    int size;
    PriorityQueue<Requests> *pQueue;
};

#endif
