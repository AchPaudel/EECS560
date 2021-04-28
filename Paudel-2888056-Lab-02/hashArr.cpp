#include "LinkedList.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

hashArr::hashArr(){

}

bool hashArr::addNewStudent(Student stud){
    for (int i=0; i<stuList.getLength(); i++){
        if (stuList.getEntry(i+1).getName() == stud.getName()){
            return false;
        }
    }
    stuList.insert(stud);
    listSize++;
}

bool hashArr::removeStudent(string name){
    for (int i=0; i<stuList.getLength(); i++){
        if (stuList.getEntry(i+1).getName() == name){
            stuList.remove(i+1);
            return true;
        }
    }
    return false;
}

Student hashArr::getStudent(int key){
        return (stuList.getEntry(key+1));
}

int hashArr::getListSize(){
    return listSize;
}

bool hashArr::findStudent(string name){
    bool found = false;
    for (int i=0; i<stuList.getLength(); i++){
        if (stuList.getEntry(i+1).getName == name){
            found = true;
        }
    }
    return found;
}
