#include "Student.h"

//Constructors
Student::Student(string name, string number){
  setName(name);
  setNumber(number);
}

Student::Student(){
  setName("Vikrant");
  setNumber("101010101");
}

Student::Student(Student& s){
  setName(s.name);
  setNumber(s.number);
}


//Setters
void Student::setName(string name){ this->name = name; }
void Student::setNumber(string number){ this->number = number; }


//Getters
string Student::getName(){ return name; }
string Student::getNumber(){return number; }


//Other functions
/*
  Function:  lessThan
  Purpose:   compare if student1 comes before student2 alphabetically
       in:   student2
   return:   true if student1 comes before student2, otherwise false
*/
bool Student::lessThan(Student& s){
  if(this->number < s.number){
    return true;
  }
  else{
    return false;
  }
}

/*
  Function:  printStudent
  Purpose:   Prints student information
   return:   nothing
*/
void Student::printStudent(){
  cout<<"Name = " << getName() << ", Number = " << getNumber() <<endl;
}

//DONE
