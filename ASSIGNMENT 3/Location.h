#ifndef LOCATION_H
#define LOCATION_H
#include<iostream>
#include<string>
using namespace std;

class Location {
  public:
    //Constructors
    Location(char code, int num);

    //Getters
    string getId() const;
    string getProduct() const;
    int getQuantity() const;

    //Other functions
    bool isEmpty() const;
    bool isAvailable() const;
    void print() const;

    //Virtual functions
    virtual int getCapacity() = 0;
    virtual bool add(const string& prod, int amount) = 0;
    virtual bool remove(int quantity) = 0;


  protected:
    string id;
    string product;
    int quantity;
    static const string NONE;

};

#endif

//DONE
