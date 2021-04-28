#include "Exec.h"
#include "EmptyPriorityQueue.h"
#include <iostream>
#include <fstream>
using namespace std;

Exec::Exec(){
    cout<<"Hello";
}

Exec::~Exec(){
    delete pQueue;
}

void Exec::run(istream& inFile){
    inFile>>size;
    pQueue = new PriorityQueue<Requests>(size);
    string tempCommand, firstName, lastName;
    int priority;
    while(!inFile.eof()){
        inFile>>tempCommand;

        if(tempCommand == "request"){
            inFile>>firstName>>lastName>>priority;
            Requests request(firstName,lastName,priority);
            pQueue->enqueue(request);
        }

        else if(tempCommand == "fix"){
            try{
                pQueue->dequeue();
            }
            catch (EmptyPriorityQueue &e){
                std::cerr<<e.what();
            }
        }
        else if(tempCommand == "status"){
            showStatus(*pQueue);
        }

        else {
            cout<<"Error: Invalid Command."<<endl;
        }
    }
}

void Exec::showStatus(PriorityQueue<Requests> pQue){
    while (pQueue->isEmpty() != true){
        try {
            pQue.peekFront().printRequest();
            pQue.dequeue();
        }
        catch (EmptyPriorityQueue &e){
            std::cerr<<e.what();
        }

    }
}
