#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;

class Student {
public:
  //Constructor----------------
    Student(); 
  //Destructor-----------------
    ~Student();
  //Getters--------------------
    int getStudentID(); 
    string getStudentName();
  //Setters-------------------
    void setStudentID(int); 
    void setStudentName(string); 
  //Operator Overloads-----------
    bool operator==(const Student& stu) const;
    friend istream& operator>> (istream& is, Student& stu);
    friend std::ostream& operator<< (std::ostream &out, const Student &stu);
  //Variables-------------------
    int studentID;
    string studentName;
};

#endif
