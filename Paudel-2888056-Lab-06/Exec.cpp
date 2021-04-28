#include "Exec.h"
#include <iostream>
#include <fstream>
using namespace std;

Exec::Exec(std::istream& inFile)
{
    while(!inFile.eof()){
        string temp="";
        inFile>>temp;
        count++;
        if (inFile.eof()){
            break;
        }
    }


    initArr = new int[count];

    ifstream inFile1;
    inFile1.open("data.txt");
    int iter=0;
    string tempVal="0";
    int tempInt=0;

    while(!inFile1.eof()){
        inFile1>>tempVal;
        tempInt = stoi(tempVal);
        //cout<<"\n"<<tempInt<<" ";
        initArr[iter] = tempInt;
        iter++;
        if(inFile1.eof()){
            inFile1.close();
            break;
        }
    }

    run();
}

Exec::~Exec(){
    delete[] initArr;
    delete heapObj;
}

void Exec::run() {
    bool exitL = false;
    bool heapBuilt = false;
    while(!exitL)
    {
        int command = 0;
        if (!heapBuilt){
            cout<<"Choose one of the following commands:"<<endl;
            cout<<"1. Build Heap\n";
            cin>>command;
            buildHeap();
            heapBuilt=true;
        }
        cout<<"Choose one of the following commands:"<<endl;
        cout<<"1. Build Heap\n2. Insert\n3. Delete\n4. MinLevelElements\n5. MaxLevelElements\n6. Exit"<<endl;
        std::cin>>command;
        switch (command){
            case 1:
            buildHeap();
            break;

            case 2:
            add();
            break;

            case 3:
            remove();
            break;

            case 4:
            minLevel();
            break;

            case 5:
            maxLevel();
            break;

            case 6:
            exitL = true;
            break;

            default:
            cout<<"Unacceptable command."<<endl;
            break;
        }
    }
}

void Exec::add(){
    int elem=0;
    cout<<"Enter element to be inserted: ";
    cin>>elem;
    heapObj->insert(elem);
    count++;
}

void Exec::remove(){
    heapObj->removeElem();
    cout<<"The root has been deleted successfully"<<endl;
    count--;
}

void Exec::minLevel(){
    heapObj->minPrint();
}

void Exec::maxLevel(){
    heapObj->maxPrint();
}

void Exec::buildHeap(){
    heapObj = new MinMaxHeap<int>(initArr, count-1);
    heapObj->buildHeap();
    heapObj->printAll();
}
