#ifndef STORELOCATION_H
#define STORELOCATION_H
#include<iostream>
#include<string>
#include "Location.h"
#include "defs.h"
using namespace std;

class StoreLocation : public Location {
  public:
    //Constructors
    StoreLocation();

    //Other functions
    void setProduct(const string& product);
    int getFreeSpace() const;

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
