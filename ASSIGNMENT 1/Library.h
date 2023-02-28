#ifndef LIBRARY_H
#define LIBRARY_H
#include<iostream>
#include<string>
#include "Student.h"
#include "Room.h"
#include "Reservation.h"
using namespace std;

#define MAX_ARR 200

class Library{
  public:
    //Constructors
    Library();

    //Destructor
    ~Library();

    //Other functions
    bool addStudent(const string& name, const string& number);
    bool addRoom(string name, int capacity = 1, int computers = 0, bool whiteboard = false);
    bool getStudent(const string& name, Student** student);
    bool getRoom(const string& roomName, Room** room);
    bool isFree(const string& room, Date&);
    bool makeReservation(const string& student, const string& room, Date&);
    void printReservations();


  private:
     Student** Student_Array;
     Room* Room_Array[MAX_ARR];
     Reservation** Res_Array;
     int S_Num_Elements;
     int Room_Num_Elements;
     int Res_Num_Elements;
};

#endif

//DONE
