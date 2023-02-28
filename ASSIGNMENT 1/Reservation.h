#ifndef RESERVATION_H
#define RESERVATION_H
#include<iostream>
#include<string>
#include "Student.h"
#include "Date.h"
#include "Room.h"
using namespace std;

class Reservation{

  public:
    //Constructors
    Reservation(Student* student, Room* room, Date& date);

    //Getters
    Student* getStudent();
    Room* getRoom();
    Date getDate();

    //Other functions
    bool lessThan(Reservation& res);
    bool overlaps(const string& r, Date& d);
    void printRes();


  private:
    Student* student;
    Room* room;
    Date date;
};

#endif

//DONE
