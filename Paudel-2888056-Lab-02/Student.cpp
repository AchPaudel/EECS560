#include "Student.h"
#include <string>
using namespace std;

Student::Student(int id, string name){
    studentId = id;
    studentName = name;
}

int Student::getId(){
    return studentId;
}

string Student::getName(){
    return studentName;
}


}
