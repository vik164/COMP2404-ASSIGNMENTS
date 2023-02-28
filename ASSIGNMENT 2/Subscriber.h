#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include<iostream>
#include<string>
using namespace std;

class Subscriber {
  public:
    //Constructor
    Subscriber(const string& name, const string& creditcard);

    //Setters
    void setName(string name);
    void setCreditcard(string creditcard);

    //Getters
    string getName();
    string getCreditcard();

    //Other functions
    bool matches(const string& name);
    void print();


  private:
    string name;
    string creditcard;
};

#endif

//DONE
