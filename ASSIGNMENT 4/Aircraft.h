#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include<iostream>
#include<string>
#include "Part.h"
#include "Array.h"
#include "Array.h"
using namespace std;

class Aircraft {

  friend ostream& operator<<(ostream& o, Aircraft& a);

  public:
    //Constructors
    Aircraft(const string& type, const string& registration);

    //Destructor
    ~Aircraft();

    //Getters
    string getRegistration() const;

    //Other functions
    void install(Part* part, Date& d);
    void takeFlight(int hours);
    void inspectionReport(Date& d, Array<Part*>& parts);

  private:
    string type;
    string registration;
    int flighthours;
    Array<Part*> parts;
};

#endif

//DONE
