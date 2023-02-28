#include "Reservation.h"

//Constructors
Reservation::Reservation(Student* student, Room* room, Date& date){
  this->student = student;
  this->room = room;
  this->date.setDate(date);
}


//Getters
Student* Reservation::getStudent(){ return student; }
Room* Reservation::getRoom(){ return room; }
Date Reservation::getDate(){ return date; }


//Other functions
/*
  Function:  lessThan
  Purpose:   compare if reservation1 comes before reservation2
       in:   reservation2
   return:   true if reservation1 comes before reservation2, otherwise false
*/
bool Reservation::lessThan(Reservation& res){
  return this->date.lessThan(res.date);
}

/*
  Function:  overlaps
  Purpose:   checks if reservation overlaps with another reservation
       in:   room wanted for reservation
       in:   date wanted for reservation
   return:   true if room matched and date does overlap, otherwise false
*/
bool Reservation::overlaps(const string& r, Date& d){
  if((this->room->getName() == r) && this->date.overlaps(d) == true){
    return true;
  }
  else{
    return false;
  }
}

/*
  Function:  printRes
  Purpose:   Prints reservation information
   return:   nothing
*/
void Reservation::printRes(){
  cout<< "Reservation Info: "<<endl;
  cout<<"    ";
  date.print();
  cout<<"    ";
  student->printStudent();
  cout<<"    ";
  room->printRoom();
  cout<<endl;
}

//DONE
