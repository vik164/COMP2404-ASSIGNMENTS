#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<string>
#include "defs.h"
#include "WHLocation.h"
using namespace std;

class Queue {
  class Node {
    public:
      WHLocation* data;
      Node*    next;
  };

  public:
    //Constructors
    Queue();

    //Destructor
    ~Queue();

    //Other functions
    bool isEmpty() const;
    void peekFirst(WHLocation** loc);
    void popFirst(WHLocation** loc);
    void addLast(WHLocation* loc);
    void print() const;


  private:
    Node* head;
    Node* tail;

};

#endif

//DONE
