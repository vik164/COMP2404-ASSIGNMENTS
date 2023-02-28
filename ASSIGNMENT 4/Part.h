#ifndef PART_H
#define PART_H
#include<iostream>
#include<string>
#include "Date.h"
using namespace std;

class Part {

  friend ostream& operator<<(ostream& o, Part& p);

  public:
    //Constructors
    Part(const string& name);

    //Destructor
    virtual ~Part();

    //Getters
    string getName() const;

    //Other functions
    void addFlightHours(int hours);
    void install(Date& date);

    //Virtual functions
    virtual bool inspection(Date& date) const = 0;

  protected:
    virtual void print_helper(ostream&);

    string name;
    Date installationDate;
    int flighthours;
};


class FH_Part : virtual public Part {
  public:
    //Constructors
    FH_Part(const string& name, int fh_inspect);

    //Destructor
    virtual ~FH_Part();

    //Virtual functions
    virtual bool inspection(Date& date) const;

  protected:
    virtual void print_helper(ostream&);

    int fh_inspect;
};


class IT_Part : virtual public Part {
  public:
    //Constructors
    IT_Part(const string& name, int it_inspect);

    //Destructor
    virtual ~IT_Part();

    //Virtual functions
    virtual bool inspection(Date& date) const;

  protected:
    virtual void print_helper(ostream&);

    int it_inspect;
};


class FHIT_Part : virtual public FH_Part, virtual public IT_Part {
  public:
    //Constructors
    FHIT_Part(const string& name, int fh_inspect, int it_inspect);

    //Destructor
    virtual ~FHIT_Part();

    //Virtual functions
    virtual bool inspection(Date& date) const;

  protected:
    virtual void print_helper(ostream&);
};

#endif

//DONE
