#ifndef AIRLINE_H
#define AIRLINE_H
#include<iostream>
#include<string>
#include "Aircraft.h"
#include "Array.h"
using namespace std;

class Airline {
  public:
    //Constructors
    Airline(const string& name);

    //Destructor
    ~Airline();

    //Other functions
    void addAircraft(const string& type, const string& reg);
    void addPart(const string& part, int fh_inspect, int it_inspect);
    void takeFlight(const string& reg, int hours);
    void printAircraft();
    void printParts();
    void inspectionReport(const string& reg, Date& d);
    bool install(const string& reg, const string& name, Date& d);

  private:
    //Getters
    Part* getPart(const string& name);
    Aircraft* getAircraft(const string& reg);

    string name;
    Array<Part*> parts;
    Array<Aircraft*> aircrafts;
};

#endif

//DONE
