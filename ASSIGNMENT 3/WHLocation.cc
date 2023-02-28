#include "WHLocation.h"

const char WHLocation::code = 'B';
const int WHLocation::capacity = WHLOC_CAPACITY;
int WHLocation::nextId = 1;

WHLocation::WHLocation() : Location(code, nextId) {
  nextId++;
}


//Virtual functions
int WHLocation::getCapacity(){ return capacity; }

/*
  Function:  add
  Purpose:   add product if location is isAvailable
   in:       product name
   in:       amount
   out:      set product and quantity specified
   return:   true if added, otherwise false
*/
bool WHLocation::add(const string& prod, int amount){
  if(isAvailable() && (amount <= capacity)){
    product = prod;
    quantity = amount;
    return true;
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
bool WHLocation::remove(int amount){
  if(amount <= 0){
    quantity = 0;
  }
  if(amount >= quantity || amount > 0){
    quantity = getQuantity() - amount;
    if(quantity == 0){
      product = NONE;
    }
    return true;
  }
  return false;
}

//DONE
