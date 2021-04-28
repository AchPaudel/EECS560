#include "Exec.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
Exec::Exec(std::istream& inFile)
{
run();
}

Exec::~Exec()
{
}




void Exec::run()
{
    bool exit = false;
    while(!exit)
    {
        int command = 0;
        cout<<"Choose one of the following commands:"<<endl;
        cout<<"1. BuildHeap\n2. Insert\n3. Concatenate\n4. DeleteMin\n5. FindMin\n6. Inorder\n7. LevelOrder\n8. Exit\n";
        std::cin>>command;

        switch(command){

          case 1: {
            buildHeap();
            cout<<endl;
            break;
          }
          case 2:
            addItem();
            cout<<endl;
            break;

          case 3:
            concatenate();
            cout<<endl;
            break;

          case 4:
            deleteMin();
            cout<<endl;
            break;

          case 5: {
            int minValue = findMin();
            cout<<endl<<"The minimum element is "<<minValue<<"."<<endl;
            break;
          }

          case 6:
            inOrderTraverse();
            cout<<endl;
            break;

          case 7:
            levelOrderTraverse();
            cout<<endl;
            break;

          case 8:
            exit = true;
            break;

          default:
            cout<<"Command not found. Try again."<<endl;
            break;
        }
    }
}

void Exec::buildHeap(){
  ifstream inFile;
  inFile.open("data.txt");
  string tempVal="0";
  int tempInt=0;
  while(!inFile.eof()){
    inFile>>tempVal;
    tempInt = stoi(tempVal);

      if(inFile.eof()){
          inFile.close();
          break;
      }

      leftTree.insert(tempInt);
  }

  cout<<"Heap built successfully.";
  cout<<"The new level order traversal is: ";
  levelOrderTraverse();
  cout<<endl;

}

void Exec::addItem(){
  int value;
  cout<<"Enter the value you want to insert:";
  cin>>value;
  cout<<endl;

  leftTree.insert(value);
  cout<<value<<" has been successfully inserted into the heap."<<endl;

  cout<<"The new level order traversal is: ";
  levelOrderTraverse();
  cout<<endl;
}

void Exec::concatenate(){
  cout<<"Enter the three elements for the heap:"<<endl;

  int val1;
  cout<<"[Element 1]: ";
  cin>>val1;


  int val2;
  cout<<"[Element 2]: ";
  cin>>val2;


  int val3;
  cout<<"[Element 3]: ";
  cin>>val3;
  cout<<endl;

  LeftistMinTree<int> toMergeTree;
  toMergeTree.insert(val1);
  toMergeTree.insert(val2);
  toMergeTree.insert(val3);

  leftTree.concat(toMergeTree);

  cout<<"The new level order traversal is: ";
  levelOrderTraverse();

}

int Exec::findMin(){

  return(leftTree.findMinimum());

}

void Exec::deleteMin(){
  int minimum = findMin();
  leftTree.deleteMinimum();

  cout<<"The minimum element "<<minimum<<" has been deleted."<<endl;
  cout<<"The new level order traversal is: ";
  levelOrderTraverse();
  cout<<endl;

}

void Exec::inOrderTraverse(){
  leftTree.inOrderPrint();
}

void Exec::levelOrderTraverse(){
  leftTree.levelOrderPrint();
}
