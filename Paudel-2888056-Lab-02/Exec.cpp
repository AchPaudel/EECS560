#include "LinkedList.h"
#include "Student.h"
#include "Exec.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Exec::Exec(istream& studentStream){
    for (int i=0; i<arrSize; i++){
        hArrayObj[i] = new hashArr();
    }

    while (!listStream.eof()){
        string name = "";
        string id = "";
        studentStream >> id;
        studentStream >> name;
        id = parseID(id);
        Student student(id,name);
        addStudent(student);
        stuSize++;
    }


    run();
}

Exec::~Exec(){

}

void Exec::run(){
    bool exit = false;
    while (!exit){
        int choice = 0;
        cout<<"Choose one operation from the options below: \n";
        cout<<"1. Add Student\n2. Remove Student\n3. Print Student List\n4. Find Student\n5. Exit\n";
        cin >> choice;
        if (choice == 1){
            string input ="";
            int parsedID=0;
            string input =0;
            string name="";
            cout<<"Enter the record to be inserted: "<<endl;
            cin>>input;
            id = parseID(input);
            name = input.substring(6, input.length());
            Student newStudent(id, name);
            addStudent(newStudent);
        } else if (choice == 2){
            removeStudent();
        } else if (choice == 3){
            printList();
        } else if (choice == 4){
            string givenName ="";
            cout<<"What is the students name?:";
            cin>>givenName;
            findStudent(givenName);
        } else {
            cout << "Not an acceptable command.\n";
        }
    }
}


int Exec::hashFunction(string name, int modSize){
    int asciiVal = 0;
    for (int i=0; i<name.length(); i++){
        asciiVal = asciiVal + name.at(i);
    }
    return (asciiVal%modSize);
}

void Exec::addStudent(Student student){
    if (stuSize > arrSize){
        resizeArr(hArrayObj);
    }
    //Get index of array aka the "key";
    int key = hashFunction(student.getName(), bucketSize);
    if (referArr[key].addNewStudent(student)){
        cout<<"Successfully added new student."<<endl;
        stuSize++;
    } else {
        cout<<"Could not add student."<<endl;
    }
}


void Exec::removeStudent(string name){
    int key = hashFunction(name, bucketSize);
    if (referArr[key].removeStudent(name)){
        cout<<"Student removed."<<endl;
        stuSize--;
    }
    else {
        cout<<"Could not remove student."<<endl;
    }
}


void Exec::printList(){
    for (int i=0; i<stuSize; i++){
        cout<<i<<": ";
        if (referArr[i].getListSize() > 1){
        for (int j=0; j<referArr[i].getListSize(); j++){
            cout << "-> ";
            cout<<referArr[i].getStudent(j).getId()<<" ";
            cout<<referArr[i].getStudent(j).getName()<<" ";
        }
        cout<<endl;
    } else {
        cout<<" ->"<<referArr[i].getStudent(i).getId()<<" ";
        cout<<referArr[i].getStudent(i).getName()<<" ";
        cout<<endl;
    }
    }
}

void Exec::findStudent(string name) {
    bool found = false;
    for (int i=0; i<stuSize; i++){
        if (referArr[i].findStudent(name)){
            cout<<"Student found at index "<<i<<"."<<endl;
            found = true;
        }
    }
    if (!found){
        cout << "Student not found."<<endl;
    }
}

int Exec::parseID(string id){
    string tempid = tempid.subtring(0, 4);
    return(stoi(tempid));
}


void Exec::resizeArr(hashArr& referArr){
    //Double hashArray size if it has running out of space
    arrSize = arrSize*2;

    //Store current data in tempArr and delete hArrayObj
    hashArr *tempArr = new hashArr[arrSize];
    for (int i=0; i < stuSize; i++){
        tempArr[i] = referArray[i];
    }
    delete[] referArr;


    //Reinitialize new hArrayObj and populate with previous data
    //Delete tempArr as it populates
    hashArr *referArray = new hashArr[arrSize];
    for (int i=0; i<stuSize; i++){
        referArr[i] = tempArr[i];
    }
    delete[] tempArr;
}
