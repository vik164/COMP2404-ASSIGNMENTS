#include "Aircraft.h"

//Constructors
Aircraft::Aircraft(const string& type, const string& registration){
  this->type = type;
  this->registration = registration;
  flighthours = 0;
}


//Destructor
Aircraft::~Aircraft(){}


//Getters
string Aircraft::getRegistration() const{ return registration; }


//Other functions
/*
  Function:  install
  Purpose:   install part
   in:       part
   in:       date
   out:      part intalled and part added
*/
void Aircraft::install(Part* part, Date& d){
  part->install(d);
  parts.add(part);
}

/*
  Function:  takeFlight
  Purpose:   update flighthours
   in:       hours
   out:      updated all parts flighthours
*/
void Aircraft::takeFlight(int hours){
  for(int i=0; i<parts.getSize(); ++i){
    parts[i]->addFlightHours(hours);
  }
  flighthours += hours;
}

/*
  Function:  inspectionReport
  Purpose:   checks if inspection is required
   in:       date
   in:       output array
   out:      if inspection is required on part, add to array
*/
void Aircraft::inspectionReport(Date& d, Array<Part*>& parts_inspection){
  for(int i=0; i<parts.getSize(); ++i){
    if(parts[i]->inspection(d) == true){
      parts_inspection.add(parts[i]);
    }
  }
}

/*
  Function:  operator<<
  Purpose:   Prints aircrafts information
   return:   nothing
*/
ostream& operator<<(ostream& o, Aircraft& a){
  o<<"------------Aircraft------------"<<endl;
  o<<"     Type:         "<< a.type <<endl;
  o<<"     Registration: " << a.registration <<endl;
  o<<"     Flighthours:  " << a.flighthours <<endl;
  o<<"--------------------------------"<<endl;
  return o;
}

//DONE
