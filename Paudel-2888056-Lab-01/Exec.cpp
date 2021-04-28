#include "LinkedList.h"
#include "Exec.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

Exec::Exec(istream& listStream){
    while (!listStream.eof()){
        position++;
        int temp;
        listStream >> temp;
        list.insert(position, temp);
    }
    run();
}

Exec::~Exec(){

}

void Exec::run(){
    bool exit = false;
    while (!exit){
        int choice = 0;
        cout<<endl<<"Choose one operation from the options below: \n";
        cout<<"1. IsEmpty\n2. Length\n3. Insert\n4. Delete\n5. Find\n6. FindPrev\n7. AppendList\n8. ForwardTraverse\n9. BackwardTraverse\n10. Exit\n";
        cin >> choice;
        cout<<endl;
        if (choice == 1){
            isEmpty();
        } else if (choice == 2){
            cout<<Length()<<endl;
        } else if (choice == 3){
            Insert();
        } else if (choice == 4){
            int x=0;
            cout<<"What number do you want to delete?: ";
            cin>>x;
            cout<<endl;
            Delete(x);
        } else if (choice == 5){
            int x=0;
            cout<<"What number do you want to find?: ";
            cin>>x;
            cout<<endl;
            findElem(x);
        } else if (choice == 6){
            int x=0;
            cout<<"What number do you want the previous of?: ";
            cin>>x;
            cout<<endl;
            findPrevElem(x);
        } else if (choice == 7){
            AppendList();
        } else if (choice == 8){
            ForwardTraverse();
        } else if (choice == 9){
            BackwardTraverse();
        } else if (choice == 10){
            exit = true;
        } else {
            cout << "Not an acceptable command.\n";
        }
    }
}

void Exec::isEmpty(){
    if (list.isEmpty()){
        cout << "The list is empty.\n";
    } else {
        cout << "The list is not empty.\n";
    }
}

int Exec::Length(){
    return (list.getLength());
}

void Exec::Insert(){
    int num = 0;
    cout<<"What number would you like to insert: ";
    cin>>num;
    position++;
    if (!list.find(num)) {
    try {
        list.insert(position, num);
    } catch (PrecondViolatedExcep &e){
        std::cerr<<e.what();
    }
    cout<<list.getEntry(position)<<" was inserted."<<endl;
} else {
    cout<<"Value already exists in the list."<<endl;
}
}

void Exec::Delete(int x){
    bool deleted = false;
    for (int i=1; i<=list.getLength(); i++){
        try {
            if (list.getEntry(i) == x) {
                list.remove(i);
                deleted = true;
            }
        }
        catch (PrecondViolatedExcep &e){
            std::cerr<<e.what();
        }
    }
    if (!deleted){
        cout<<"Element not in list. Nothing removed."<<endl;
    } else {
        cout<<"Removal complete."<<endl;
    }
}

void Exec::findElem(int x){
    if(list.find(x)){
        cout<<x<<" was found."<<endl;
    } else {
        cout<<x<<" was not found."<<endl;
    }
}

void Exec::findPrevElem(int x){
    try {
        cout<<list.findPrev(x)<<" is previous to "<<x<<endl;
    }
    catch (PrecondViolatedExcep &e){
        std::cerr<<e.what();
    }
}

void Exec::AppendList(){
    cout<<"What is the list to append: ";
    int num;
    std::string line;
    std::getline(cin, line);
    std::getline(cin, line);
    std::istringstream iss(line);
    while (iss >> num) {
      position++;
      list.insert(position, num);
    }
    cout<<"List appended."<<endl;
}

void Exec::ForwardTraverse(){
    for (int i=1; i<=list.getLength(); i++){
        cout<<list.getEntry(i)<<" ";
    }
}

void Exec::BackwardTraverse(){
    for (int i=0; i<list.getLength(); i++){
        cout<<list.getEntry(list.getLength()-i)<<" ";
    }
}
