#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
using namespace std;

class Student{
  public:
    //Constructors
    Student(string name, string number);
    Student();
    Student(Student&);

    //Setters
    void setName(string name);
    void setNumber(string number);

    //Getters
    string getName();
    string getNumber();

    //Other functions
    bool lessThan(Student& s);
    void printStudent();


  private:
    string name;
    string number;
};

#endif

//DONE
