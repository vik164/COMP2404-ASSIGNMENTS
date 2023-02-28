/*
VIKRANT KUMAR 101195442

This program allows the Carleton University Library to manage and make new room reservations.
*/

#include<iostream>
#include<string>
#include "Room.h"
#include "Date.h"
#include "Student.h"
#include "Library.h"
#include "Reservation.h"
#include "a1-global.cc"
using namespace std;

int main(){
  //TESTING DATES
  Date d1(2021,5,24,10,3);
  Date d2(2021,5,23,10,3);
  testDate(d1,d2,false);

  Date d3(2021,7,16,15,3);
  Date d4(2021,7,16,10,3);
  testDate(d3,d4,false);

  Date d5(2021,8,27,5,1);
  Date d6(2021,8,27,6,3);
  testDate(d5,d6,false);

  Date d7(2021,4,16,16,3);
  Date d8(2021,4,16,18,2);
  testDate(d7,d8,true);

  Date d9(2021,10,30,15,2);
  Date d0(2021,10,30,15,2);
  testDate(d9,d0,true);

  //TESTING LIBRARY
  Library Library;
  populate(Library);
  testReservations(Library);

  return 0;
}

//DONE
