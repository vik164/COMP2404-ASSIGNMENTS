#include "Room.h"

//Constructors
Room::Room(string name, int capacity, int computers, bool whiteboard){
  setName(name);
  setCapacity(capacity);
  setComputer(computers);
  setWhiteboard(whiteboard);
}

Room::Room(Room& r){
  setName(r.name);
  setCapacity(r.capacity);
  setComputer(r.computers);
  setWhiteboard(r.whiteboard);
}


//Setters
void Room::setName(string name){ this->name = name; }
void Room::setCapacity(int capacity){ this->capacity = capacity; }
void Room::setComputer(int computers){ this->computers = computers; }
void Room::setWhiteboard(bool whiteboard){ this->whiteboard = whiteboard; }


//Getters
string Room::getName(){ return name; }
int Room::getCapacity(){ return capacity; }
int Room::getComputers(){ return computers; }
bool Room::hasWhiteboard(){ return whiteboard; }


//Other functions
/*
  Function:  meetsCriteria
  Purpose:   to check if room meets the correct criteria
       in:   capacity
       in:   computers
       in:   whiteboard
   return:   true if room meets the criteria, otherwise false
*/
bool Room::meetsCriteria(int capacity, int computers, bool whiteboard){
  if((this->capacity >= capacity) && (this->computers >= computers) && (this->whiteboard >= whiteboard)){
    return true;
  }
  else{
    return false;
  }
}

/*
  Function:  lessThan
  Purpose:   compare if room1 comes before room2 alphabetically
       in:   room2
   return:   true if room1 comes before room2, otherwise false
*/
bool Room::lessThan(Room& r){
  if(this->name < r.name){
    return true;
  }
  else{
    return false;
  }
}

/*
  Function:  printRoom
  Purpose:   Prints room information
   return:   nothing
*/
void Room::printRoom(){
  cout<<"Name = " << getName() << ", Capacity = " << getCapacity() << ", Computers = " << getComputers() << ", Whiteboard = " << hasWhiteboard() <<endl;
}

//DONE
