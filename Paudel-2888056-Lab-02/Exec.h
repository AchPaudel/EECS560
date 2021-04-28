#ifndef EXEC_H
#define EXEC_H
#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Student.h"
#include "hashArr.h"
using namespace std;

class Exec {
public:
    Exec(istream& studentStream);
    ~Exec();
    void run();
    void addStudent(Student student);
    void removeStudent(string name);
    void printStudent();
    void findStudent(string name);
    int hashFunction(string name, int modSize);
    int parseID(int id);
private:
    int stuSize = 0;
    int arrSize = 11;
    int bucketSize = 11;
    hashArr *hArrayObj = new hashArr[arrSize];
};

#endif
