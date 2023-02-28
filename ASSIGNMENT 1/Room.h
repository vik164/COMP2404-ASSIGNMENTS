#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include<string>
using namespace std;

class Room{
  public:
    //Constructors
    Room(string name, int capacity, int computers, bool whiteboard);
    Room(Room&);

    //Setters
    void setName(string name);
    void setCapacity(int capacity);
    void setComputer(int computers);
    void setWhiteboard(bool whiteboard);

    //Getters
    string getName();
    int getCapacity();
    int getComputers();
    bool hasWhiteboard();

    //Other functions
    bool meetsCriteria(int capacity, int computers, bool whiteboard);
    bool lessThan(Room& r);
    void printRoom();


  private:
    string name;
    int capacity;
    int computers;
    bool whiteboard;
};

#endif

//DONE
