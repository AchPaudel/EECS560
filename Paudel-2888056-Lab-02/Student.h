#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student{
public:
    Student(int id, string name);
    int getId();
    string getName();

private:
    int studentId;
    string studentName;
};

#endif
