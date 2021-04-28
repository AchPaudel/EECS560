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
    Exec::count = 0;
    int tempKey=0;
    while(!inFile.eof()){
        inFile>>tempKey;
        if (inFile.eof()){
          break;
        }
        searchTree.add(tempKey);
    }

}

Exec::~Exec()
{
}


void visit(int& tempValue){
//  cout<<tempValue<<" ";
}





void Exec::run()
{
    bool exit = false;
    while(!exit)
    {
        int command = 0;
        cout<<"Choose one of the following commands:"<<endl;
        cout<<"1. AddItem\n2. DeleteItem\n3. FindMin\n4. FindMax\n5. DeleteMin\n6. DeleteMax\n7. InorderSuccessor\n8. LevelOrder\n9. SpiralLevelOrder\n10. LeftSideView\n11. RightSideView\n12. ExperimentalProfiling\n13. Exit\n";
        std::cin>>command;

        switch(command){

          case 1: {
            addItem();
            break;
          }
          case 2:
            deleteItem();
            break;

          case 3: {
            int minValue = findMin();
            cout<<endl<<"The min key is: "<<minValue<<endl;
            break;
          }

          case 4: {
            int maxValue = findMax();
            cout<<endl<<"The max key is: "<<maxValue<<endl;
            break;
          }

          case 5:
            deleteMin();
            break;

          case 6:
            deleteMax();
            break;

          case 7: {
            int successor=0;
            cout<<"Provide the element to find successor: "<<endl;
            cin>>successor;
            inorderSuccessor(successor);
            break;
          }
          case 8:
            levelOrder();
            break;

          case 9:
            spiralLevelOrder();
            break;

          case 10:
            leftSideView();
            break;

          case 11:
            rightSideView();
            break;

          case 12: {
            experimentalProfiling(0.1);
            experimentalProfiling(0.2);
            experimentalProfiling(0.3);
            experimentalProfiling(0.4);
            experimentalProfiling(0.5);
            break;
            }
          case 13:
            exit = true;
            break;

          default:
            cout<<"Command not found. Try again."<<endl;
            break;
        }
    }
}

void Exec::addItem(){
  int key=0;
  cout<<"What is the key you would like to insert into the BST: "<<endl;
  cin>>key;

  searchTree.add(key);
  count++;

}


void Exec::deleteItem(){
  int key=0;
  cout<<"What is the key you would like to delete from the BST: "<<endl;
  cin>>key;

  searchTree.remove(key);
  count--;
}


int Exec::findMin(){
  searchTree.inorderTraverse(visit);
  int minKey = searchTree.findMinValue();

  return(minKey);
}


int Exec::findMax(){
  searchTree.inorderTraverse(visit);
  int maxKey = searchTree.findMaxValue();

  return(maxKey);
}


void Exec::deleteMin(){
  int minKey = findMin();
  searchTree.remove(minKey);
  cout<<endl;
  cout<<"Minimum value "<<minKey<<" has been deleted."<<endl;
  count--;

}


void Exec::deleteMax(){
  int maxKey = findMax();
  searchTree.remove(maxKey);
  cout<<endl;
  cout<<"Maximum value "<<maxKey<<" has been deleted."<<endl;
  count--;

}


void Exec::inorderSuccessor(int entry){
  int value = searchTree.inorderSuccessor(entry);
  cout<<endl;
  cout<<"Successor is: "<<value<<endl;

}


void Exec::levelOrder(){
  searchTree.levelOrderTraverse(visit, false);
  cout<<endl<<endl;

}


void Exec::spiralLevelOrder(){
  searchTree.levelOrderTraverse(visit, true);
  cout<<endl<<endl;

}


void Exec::leftSideView(){
  searchTree.leftSideView(visit);
  cout<<endl<<endl;

}


void Exec::rightSideView(){
  searchTree.rightSideView(visit);
  cout<<endl<<endl;

}


void Exec::experimentalProfiling(double mValue){
  int num;
  int inputSize = floor(100003*mValue);
  srand(ETIME);
  clock_t t;

  //Build BST
  t = clock();

  for (int i=0; i<inputSize; i++){
      num = rand() % 500000 + 1;
      expAddItem(num);
  }

  t = clock() - t;
  cout<<"Add item time (Size:"<<inputSize<<") was: "<<((double)t/CLOCKS_PER_SEC)<<endl<<endl;
  //FindMin Value

  t = clock();
  int min = searchTree.findMinValue();
  cout<<"Min value: "<<min<<endl;
  t = clock() - t;
  cout<<"Find min time (Size:"<<inputSize<<") was: "<<((double)t/CLOCKS_PER_SEC)<<endl<<endl;


  //FindMax Value
  t = clock();
  int max = searchTree.findMaxValue();
  cout<<"Max value: "<<max<<endl;
  t = clock() - t;
  cout<<"Find Max time (Size:"<<inputSize<<") was: "<<((double)t/CLOCKS_PER_SEC)<<endl<<endl;


  t = clock();
  deleteMin();
  t = clock() - t;
  cout<<"Delete min time (Size:"<<inputSize<<") was: "<<((float)t/CLOCKS_PER_SEC)<<endl<<endl;

  t = clock();
  deleteMax();
  t = clock() - t;
  cout<<"Delete max time (Size:"<<inputSize<<") was: "<<((float)t/CLOCKS_PER_SEC)<<endl<<endl;

}



void Exec::expAddItem(int key){
  searchTree.add(key);
  count++;
}
