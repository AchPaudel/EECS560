#ifndef HASHARR_H
#define HASHARR_H
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Student.h"
using namespace std;


class hashArr {
public:
    hashArr();
    ~hashArr();
    bool addNewStudent(Student stud);
    bool removeStudent(string name);
    int getListSize();
    Student getStudent(int key);
    bool findStudent(string name)
private:
    LinkedList<Student> stuList;
    int listSize=0;
};

#endif
