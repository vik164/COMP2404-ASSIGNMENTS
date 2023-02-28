#include "Product.h"

//Constructor
Product::Product(const string& name, StoreLocation* sloc){
	this->name = name;
	storeLocation = sloc;
	whLocations = new Queue();
}


//Destructor
Product::~Product(){
	delete whLocations;
}


//getters and setters
const string& Product::getName(){ return name; }
StoreLocation* Product::getStoreLocation() const{ return storeLocation; }
void Product::setStoreLocation(StoreLocation* storeLocation){ this->storeLocation = storeLocation; }

/*
  Function:  addWHLocation
  Purpose:   add WHLocation to queue
   in:       WHLocation
   out:      new WHLocation is added to queue
*/
void Product::addWHLocation(WHLocation* w){
	whLocations->addLast(w);
}

/* We take as much as we can from the storeLocation.
   The input-output parameter quantity returns
   the amount left to fill in the order.

   For example, we want 20 units, so quantity = 20 is
   the input. There are 15 units in stock. We subtract
   all 15 from the location and set quantity = 5
   as output.
*/
void Product::getFromStoreLocation(int& quantity){
	if (quantity > storeLocation->getQuantity()){
		quantity -= storeLocation->getQuantity();
		storeLocation->remove(storeLocation->getQuantity());
	}else{
		storeLocation->remove(quantity);
		quantity = 0;
	}

}

/*
   We try to fill the order with whatever is in
   the warehouse locations.
   The input-output parameter "quantity" returns
   the amount left to fill in the order.

   For example, we want 20 units, so quantity = 20 is
   the input. There are 15 units in stock. We subtract
   all 15 from the location and set quantity = 5
   as output.
*/
void Product::getFromWHLocations(int& quantity){
	WHLocation* loc;
	while(quantity>0){
		//there are no more warehouse locations storing
		//this product - so break
		if (whLocations->isEmpty())break;

		//otherwise get the first whlocation
		whLocations->peekFirst(&loc);

		//if we empty the location, remove from the queue
		if (quantity > loc->getQuantity()){
			quantity -= loc->getQuantity();
			loc->remove(loc->getQuantity());
			whLocations->popFirst(&loc);
		}else{
			// we are not emptying the location,
			// but we have finished filling the order
			loc->remove(quantity);
			quantity = 0;
		}
	}
}

/*
	Attempt to fill the order with "quantity" of stock
	using both StoreLocations and WHLocations.
*/
void Product::fillOrder(int& quantity){
	while (quantity > 0 && !storeLocation->isEmpty()){
		if (quantity < storeLocation->getQuantity()){
			storeLocation->remove(quantity);
			quantity = 0;
		}else{
			quantity -= storeLocation->getQuantity();
			storeLocation->remove(storeLocation->getQuantity());
			stockStoreLocation();
		}
	}

}

/*
	Fill up the StoreLocation using stock
	from the WHLocations.
*/
void Product::stockStoreLocation(){
	int q = storeLocation->getFreeSpace();
	int toAdd = q;
	getFromWHLocations(q);
	toAdd -= q;
	storeLocation->add(name, toAdd);
}

void Product::print(){
	cout << "Product:   "<<name<<endl;
}

//DONE
