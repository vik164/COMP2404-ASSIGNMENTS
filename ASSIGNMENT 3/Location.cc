#include "Location.h"

const string Location::NONE = "Empty";

//Constructor
Location::Location(char code, int num){
  id = code + to_string(num);
  quantity = 0;
  product = NONE;
}


//Getters
string Location::getId() const{ return id; }
string Location::getProduct() const{ return product; }
int Location::getQuantity() const{ return quantity; }


//Other functions
/*
  Function:  isEmpty
  Purpose:   Checks if quantity is 0
   return:   true if quantity is 0, otherwise false
*/
bool Location::isEmpty() const { return quantity == 0; }

/*
  Function:  isAvailable
  Purpose:   Checks if product is empty
   return:   true if product is empty, otherwise false
*/
bool Location::isAvailable() const { return product == NONE; }

/*
  Function:  print
  Purpose:   Prints location information
   return:   nothing
*/
void Location::print() const {
  cout<<"     Location: " << getId() <<endl;
  cout<<"     Product:  " << getProduct() <<endl;
  cout<<"     Quantity: " << getQuantity() <<endl;
  cout<<"--------------------------------------"<<endl;
}

//DONE
