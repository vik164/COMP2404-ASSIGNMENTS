#include "Library.h"

//Constructors
Library::Library(){
  Student_Array = new Student*[MAX_ARR];
  Res_Array = new Reservation*[MAX_ARR];
  S_Num_Elements = 0;
  Room_Num_Elements = 0;
  Res_Num_Elements = 0;
}


//Destructor
Library::~Library(){
  for(int i=0; i<Room_Num_Elements; ++i){
    delete Room_Array[i];
  }
  for(int j=0; j<S_Num_Elements; ++j){
    delete Student_Array[j];
  }
  for(int x=0; x<Res_Num_Elements; ++x){
    delete Res_Array[x];
  }

  //delete [] Room_Array;
  delete [] Student_Array;
  delete [] Res_Array;
}


//Other functions
/*
  Function:  addStudent
  Purpose:   add student to array in sorted order
   in:       student name
   in:       student number
   out:      student is added to array
   return:   true for student added, otherwise false
*/
bool Library::addStudent(const string& name, const string& number){
  Student* s;
  if(S_Num_Elements >= MAX_ARR){
    return false;
  }
  if(S_Num_Elements == 0){
    Student_Array[S_Num_Elements] = new Student(name, number);
    S_Num_Elements++;
    return true;
  }

  s = new Student(name, number);
  for(int i=0;i<S_Num_Elements;++i){
    if(s->lessThan(*Student_Array[i]) == true){
      for(int j=S_Num_Elements;j>i; --j){
        Student_Array[j] = Student_Array[j-1];
      }
      Student_Array[i] = s;
      S_Num_Elements++;
      return true;
    }
  }

  Student_Array[S_Num_Elements] = s;
  S_Num_Elements++;
  return true;
}

/*
  Function:  addRoom
  Purpose:   add room to array in sorted order
   in:       room name
   in:       room capacity
   in:       room computers
   in:       room whiteboard
   out:      room is added to array
   return:   true for room added, otherwise false
*/
bool Library::addRoom(string name, int capacity, int computers, bool whiteboard){
  Room* r;
  if(Room_Num_Elements >= MAX_ARR){
    return false;
  }
  if(Room_Num_Elements == 0){
    Room_Array[Room_Num_Elements] = new Room(name, capacity, computers, whiteboard);
    Room_Num_Elements++;
    return true;
  }

  r = new Room(name, capacity, computers, whiteboard);
  for(int i=0;i<Room_Num_Elements;++i){
    if(r->lessThan(*Room_Array[i]) == true){
      for(int j=Room_Num_Elements;j>i; --j){
        Room_Array[j] = Room_Array[j-1];
      }
      Room_Array[i] = r;
      Room_Num_Elements++;
      return true;
    }
  }
  Room_Array[Room_Num_Elements] = r;
  Room_Num_Elements++;
  return true;
}

/*
  Function:  getStudent
  Purpose:   find student in Library
   in:       student name
   in:       student
   out:      return student if found
   return:   true for student found, otherwise false
*/
bool Library::getStudent(const string& name, Student** student){
  for(int i=0; i<S_Num_Elements; ++i){
    if(Student_Array[i]->getName() == name){
      *student = Student_Array[i];
      return true;
    }
  }
  return false;
}

/*
  Function:  getRoom
  Purpose:   find room in Library
   in:       room name
   in:       room
   out:      return room if found
   return:   true for room found, otherwise false
*/
bool Library::getRoom(const string& roomName, Room** room){
  for(int i=0; i<Room_Num_Elements; ++i){
    if(Room_Array[i]->getName() == roomName){
      *room = Room_Array[i];
      return true;
    }
  }
  return false;
}

/*
  Function:  isFree
  Purpose:   check if wanted room is free
   in:       room wanted
   in:       date wanted
   return:   true if room is available on that date, otherwise false
*/
bool Library::isFree(const string& room, Date& date){
  Room *r;
  if(getRoom(room, &r) == false){
    return false;
  }
  for(int i=0;i<Res_Num_Elements; ++i){
    if(Res_Array[i]->overlaps(room, date)){
      return false;
    }
  }
  return true;
}

/*
  Function:  makeReservation
  Purpose:   make reservation and add to array
   in:       student
   in:       room
   in:       date
   return:   true if reservation is made and added to array, otherwise false
*/
bool Library::makeReservation(const string& student, const string& room, Date& date){
  Student *s;
  Room *r;
  if((getRoom(room, &r) == false) || (getStudent(student, &s) == false)){
    return false;
  }

  if((Res_Num_Elements >= MAX_ARR) || (isFree(room, date) == false)){
      return false;
  }
  Res_Array[Res_Num_Elements] = new Reservation(s, r, date);
  Res_Num_Elements++;
  return true;
}

/*
  Function:  printReservations
  Purpose:   Prints all reservations information
   return:   nothing
*/
void Library::printReservations(){
  for(int i=0; i<Res_Num_Elements; ++i){
    Res_Array[i]->printRes();
  }
}

//DONE
