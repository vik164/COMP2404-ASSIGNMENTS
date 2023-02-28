#include "Subscriber.h"

//Constructors
Subscriber::Subscriber(const string& name, const string& creditcard){
  setName(name);
  setCreditcard(creditcard);
}


//Setters
void Subscriber::setName(string name){ this->name = name; }
void Subscriber::setCreditcard(string creditcard){ this->creditcard = creditcard; }


//Getters
string Subscriber::getName(){ return name; }
string Subscriber::getCreditcard(){return creditcard; }


//Other functions
/*
  Function:  matches
  Purpose:   checks if name1 matches with name2
       in:   name2
   return:   true if names matches, otherwise false
*/
bool Subscriber::matches(const string& name){
  if(this->name == name){
    return true;
  }
  else{
    return false;
  }
}

/*
  Function:  print
  Purpose:   Prints subscriber information
   return:   nothing
*/
void Subscriber::print(){
  cout<<endl<<"------------Subscriber------------"<<endl;
  cout<<"     Name:       " << getName() <<endl;
  cout<<"     Creditcard: " << getCreditcard() <<endl;
  cout<<"----------------------------------"<<endl;
}

//DONE
