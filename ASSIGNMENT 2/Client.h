#ifndef CLIENT_H
#define CLIENT_H
#include<iostream>
#include<string>
#include "Network.h"
using namespace std;

class Client {
  public:
    //Constructors
    Client(const string& name);

    //Destructor
    ~Client();

    //Other functions
    void download(Network* net, const string& title);
    void stream (Network* net, const string& title, int Epi_Num);
    void playLocal(const string& title, int Epi_Num);
    void print();


  private:
    string name;
    PodArray* pod_Array;
};

#endif

//DONE
