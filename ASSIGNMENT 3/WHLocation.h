#ifndef WHLOCATION_H
#define WHLOCATION_H
#include<iostream>
#include<string>
#include "defs.h"
#include "Location.h"
using namespace std;

class WHLocation : public Location {
  public:
    //Constructors
    WHLocation();

    //Virtual functions
    virtual int getCapacity();
    virtual bool add(const string& prod, int amount);
    virtual bool remove(int amount);


  private:
    static const char code;
    static const int capacity;
    static int nextId;

};

#endif

//DONE
