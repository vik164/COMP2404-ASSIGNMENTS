#include "Store.h"

//Constructor
Store::Store(const string& name){
  this->name = name;
  products = new List();
}


//Destructor
Store::~Store(){
  delete products;
}


//other
/*
  Function:  findAvailableSLoc
  Purpose:   find first available position in array
   in:       StoreLocation pointee
   out:      return StoreLocation if found
*/
void Store::findAvailableSLoc(StoreLocation** sloc){
  for(int i=0; i<SLOCS; ++i){
    if(store_array[i].isAvailable()){
      *sloc = &store_array[i];
      return;
    }
  }
  *sloc = NULL;
}

/*
  Function:  findAvailableWHLoc
  Purpose:   find first available position in array
   in:       WHLocation pointee
   out:      return WHLocation if found
*/
void Store::findAvailableWHLoc(WHLocation** wloc){
  for(int i=0; i<WHLOCS; ++i){
    if(wh_array[i].isAvailable()){
      *wloc = &wh_array[i];
      return;
    }
  }
  *wloc =  NULL;
}

/*
  Function:  printStoreStock
  Purpose:   Prints storelocation information
   return:   nothing
*/
void Store::printStoreStock() const{
  for(int i=0; i<SLOCS; ++i){
    if(store_array[i].getProduct() == "Empty"){
      break;
    }
    cout<<endl<<endl<<"------------Store Location------------"<<endl;
    cout<<"     Name:     "<< name <<endl;
    store_array[i].print();
  }
}

/*
  Function:  printWareHouseStock
  Purpose:   Prints WHlocation information
   return:   nothing
*/
void Store::printWareHouseStock() const{
  for(int i=0; i<WHLOCS; ++i){
    // if(wh_array[i].getProduct() == "Empty"){
    //   break;
    // }
    if(wh_array[i].getQuantity() != 0){
      cout<<endl<<endl<<"--------------WHLocation--------------"<<endl;
      cout<<"     Name:     "<< name <<endl;
      wh_array[i].print();
    }
  }
}

/*
  Function:  printProducts
  Purpose:   Prints product information
   return:   nothing
*/
void Store::printProducts() const{
  products->print();
}

/*
  Function:  findProduct
  Purpose:   find product in list
   in:       product name
   in:       product pointee
   out:      return product if found
*/
void Store::findProduct(const string& name, Product** prod){
  products->findProduct(name, prod);
}

//these are done for you
void Store::receiveProduct(const string& pname, int quantity){
    Product* prod = NULL;
    cout<<"Receiving..."<<endl;
    products->findProduct(pname, &prod);
    if (prod==NULL){
        cout<<"Making new product"<<endl;
        StoreLocation* sloc;
        findAvailableSLoc(&sloc);
        prod = new Product(pname, sloc);
        products->add(prod);

    }


    WHLocation* bloc;
    while(quantity > 0){
        findAvailableWHLoc(&bloc);
        if (quantity > bloc->getCapacity()){
            bloc->add(pname, bloc->getCapacity());
            prod->addWHLocation(bloc);
            quantity -= bloc->getCapacity();
        }else{
            bloc->add(pname, quantity);
            prod->addWHLocation(bloc);
            quantity = 0;
        }
    }

    cout<<"stocking store location..."<<endl;
    prod->stockStoreLocation();

}

void Store::fillOrder(const string& product, int& quantity){
    Product* prod;
    findProduct(product, &prod);
    if (prod == NULL){
        return;
    }
    prod->fillOrder(quantity);
}


void Store::print(){
    cout<<"Store: "<<name<<endl;
}

//DONE
