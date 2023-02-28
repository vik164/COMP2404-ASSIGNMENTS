#include "StoreLocation.h"

const char StoreLocation::code = 'A';
const int StoreLocation::capacity = SLOC_CAPACITY;
int StoreLocation::nextId = 1;

//Constructor
StoreLocation::StoreLocation() : Location(code, nextId) {
  nextId++;
}


//Other functions
void StoreLocation::setProduct(const string& product){ this->product = product; }

/*
  Function:  getFreeSpace
  Purpose:   Gets the space in location
   return:   difference between capacity and quantity
*/
int StoreLocation::getFreeSpace() const{ return capacity - quantity; }


//Virtual functions
int StoreLocation::getCapacity(){ return capacity; }

/*
  Function:  add
  Purpose:   add amount of product
   in:       product name
   in:       amount
   out:      add product to the amount specified
   return:   true if added, otherwise false
*/
bool StoreLocation::add(const string& prod, int amount){
  bool check = false;
  if(product.compare(prod) == 0){
    check = true;
  }
  else if(product.compare(NONE) == 0){
    product = prod;
    check = true;
  }
  if(check == true){
    if(quantity + amount <= capacity){
      quantity = quantity + amount;
      return true;
    }
  }

  return false;
}

/*
  Function:  remove
  Purpose:   remove amount specified
   in:       amount
   out:      removal of amount specified
   return:   true if removed, otherwise false
*/
bool StoreLocation::remove(int amount){
  if(amount >= quantity || amount >= 0){
    quantity = quantity - amount;
    return true;
  }
  return false;
}

//DONE
