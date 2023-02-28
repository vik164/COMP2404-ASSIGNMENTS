#include "Airline.h"

Airline::Airline(const string& name){
  this->name = name;
}


//Destructor
Airline::~Airline(){
  for(int j=0; j<parts.getSize(); ++j){
    delete parts[j];
  }
  for(int i=0; i<aircrafts.getSize(); ++i){
    delete aircrafts[i];
  }
  //delete [] parts;
  //delete [] aircrafts;
}


//Getters
Part* Airline::getPart(const string& name){
  for(int i=0; i< parts.getSize(); ++i){
    if(parts[i]->getName() == name){
      return parts[i];
    }
  }
  return NULL;
}

Aircraft* Airline::getAircraft(const string& reg){
  for(int i=0; i< aircrafts.getSize(); ++i){
    if(aircrafts[i]->getRegistration() == reg){
      return aircrafts[i];
    }
  }
  return NULL;
}


//Other functions
/*
  Function:  addAircraft
  Purpose:   add aircraft to array
   in:       aircraft type
   in:       aircraft registration
   out:      new aircraft added to array
   return:   nothing
*/
void Airline::addAircraft(const string& type, const string& reg){
  Aircraft* newAircraft = new Aircraft(type, reg);
  aircrafts.add(newAircraft);
}

/*
  Function:  addPart
  Purpose:   add part to array
   in:       part name
   in:       fh_inspect
   in:       it_inspect
   out:      new part added to array
   return:   nothing
*/
void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
  if(fh_inspect == 0){
    IT_Part* newPart = new IT_Part(part, it_inspect);
    parts.add(newPart);
  }
  else if(it_inspect == 0){
    FH_Part* newPart = new FH_Part(part, fh_inspect);
    parts.add(newPart);
  }
  else{
    FHIT_Part* newPart = new FHIT_Part(part, fh_inspect, it_inspect);
    parts.add(newPart);
  }
}

/*
  Function:  takeFlight
  Purpose:   get aircraft and make it take a flight
   in:       aircraft registration
   in:       hours
   out:      get aircraft and update flighthours
*/
void Airline::takeFlight(const string& reg, int hours){
  Aircraft* Find_Aircraft = getAircraft(reg);
  if(Find_Aircraft != NULL){
    Find_Aircraft->takeFlight(hours);
    return;
  }
  cout<<" ERROR: AIRCRAFT DOESN'T EXIST"<<endl;
}

/*
  Function:  printAircraft
  Purpose:   Prints all aircrafts information
   return:   nothing
*/
void Airline::printAircraft(){
  for(int i=0; i<aircrafts.getSize(); ++i){
    cout<<*aircrafts[i]<<endl;
  }
}

/*
  Function:  printParts
  Purpose:   Prints all parts information
   return:   nothing
*/
void Airline::printParts(){
  for(int i=0; i<parts.getSize(); ++i){
    cout<<*parts[i]<<endl;
  }
}

/*
  Function:  inspectionReport
  Purpose:   checks if inspection is required
   in:       aircraft registration
   in:       date
   out:      if inspection needed on aircraft, print all parts required for inspection
*/
void Airline::inspectionReport(const string& reg, Date& d){
  Aircraft* Find_Aircraft = getAircraft(reg);
  Array<Part*> required_parts;

  if(Find_Aircraft != NULL){
    cout<<endl<<endl<<"------------------Aircraft Inspection------------------"<< endl;
    cout<<"The following parts from "<<Find_Aircraft->getRegistration()<<" require inspection: "<<endl;
    Find_Aircraft->inspectionReport(d, required_parts);

    for(int i=0; i<required_parts.getSize(); ++i){
      cout<<*required_parts[i];
    }
    cout<<endl<<"-------------------------------------------------------"<< endl;
    return;
  }
  cout<<" ERROR: AIRCRAFT DOESN'T EXIST"<<endl;
}

/*
  Function:  install
  Purpose:   install part in aircraft
   in:       aircraft registration
   in:       part name
   in:       date
   out:      part intalled on aircraft
*/
bool Airline::install(const string& reg, const string& name, Date& d){
  Aircraft* Find_Aircraft = getAircraft(reg);
  Part* Find_Part = getPart(name);

  if(Find_Aircraft != NULL){
    if(Find_Part != NULL){
      Find_Aircraft->install(Find_Part, d);
      return true;
    }
    else{
      cout<<"ERROR: PART DOESN'T EXIST"<<endl;
    }
  }
  else{
    cout<<"ERROR: AIRCRAFT DOESN'T EXIST "<<endl;
  }
  return false;
}

//DONE
