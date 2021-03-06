#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
using namespace std;

//Constructor--------------
Student::Student() {
    studentID = 0;
} //constructor

//Destructor---------------
Student::~Student() {
} //destructor

//Getters------------------
int Student::getStudentID() {
    return studentID;
} //getStudentID

string Student::getStudentName() {
  return studentName;
} //getStudentName

//Setters------------------
void Student::setStudentID(int id) {
  studentID = id;
} //setStudentID

void Student::setStudentName(string name) {
  studentName = name;
} //setStudentName

//Operator Overloads-----------
bool Student::operator==(const Student& foo) const {
        if(this->studentID == foo.studentID) {
            return true;
        }
    return false;
} //==

std::istream& operator>> (istream& is, Student& student) {
    is >> student.studentID >> student.studentName;
    return is;
} //>>

std::ostream& operator<< (std::ostream &out, const Student &student) {
    out << student.studentID <<" " << student.studentName;
    return out;
} //<<
