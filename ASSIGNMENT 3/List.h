#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<string>
#include "defs.h"
#include "Product.h"
using namespace std;

class List {
  class Node {
    public:
      Product* data;
      Node*    next;
  };

  public:
    //Constructors
    List();

    //Destructor
    ~List();

    //Other functions
    void add(Product*);
    void get(const string& name, Product**);
    void remove(const string& name, Product**);
    void removeUpTo(const string& name);
    void print() const;
    bool isEmpty() const;
    void findProduct(const string& name, Product** prod) const;


  private:
    Node* head;

};

#endif

//DONE
