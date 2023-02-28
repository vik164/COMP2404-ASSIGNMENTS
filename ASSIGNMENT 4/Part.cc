#include "Part.h"

//Constructors
Part::Part(const string& name){
  this->name = name;
  flighthours = 0;
}


//Destructor
Part::~Part(){}


//Getters
string Part::getName() const{ return name; }


//Other functions
/*
  Function:  addFlightHours
  Purpose:   update flighthours
   in:       hours
   out:      hours added to flighthours
*/
void Part::addFlightHours(int hours){
  flighthours += hours;
}

/*
  Function:  install
  Purpose:   update installationDate
   in:       date
   out:      new date set to installationDate
*/
void Part::install(Date& date){
  installationDate = date;
}

/*
  Function:  print_helper
  Purpose:   Prints parts information
       in:   ostream
   return:   nothing
*/
void Part::print_helper(ostream& o){
  o<<endl<<"   -----------------Part-----------------"<<endl;
  o<<"   Name:            " << name <<endl;
  o<<"   Flighthours:     " << flighthours <<endl;
  o<<"   Date Installed:  " << installationDate;
}

/*
  Function:  operator<<
  Purpose:   Prints parts information
   return:   nothing
*/
ostream& operator<<(ostream& o, Part& p){
  p.print_helper(o);
  return o;
}



//------------------------------------------------------------------------------



//Constructors
FH_Part::FH_Part(const string& name, int fh_inspect) : Part(name) {
  this->fh_inspect = fh_inspect;
}


//Destructor
FH_Part::~FH_Part(){}


//Virtual functions
/*
  Function:  inspection
  Purpose:   checks if inspection is required on part
       in:   date
  return:    true if inspection required, false otherwise
*/
bool FH_Part::inspection(Date& date) const{
  return flighthours >= fh_inspect;
}

/*
  Function:  print_helper
  Purpose:   Prints part information
       in:   ostream
   return:   nothing
*/
void FH_Part::print_helper(ostream& o){
  Part::print_helper(o);
  o<<"   Inspect Every:   " << fh_inspect << " flight hours"<<endl;
  o<<"   --------------------------------------"<<endl;
}



//------------------------------------------------------------------------------



//Constructors
IT_Part::IT_Part(const string& name, int it_inspect) : Part(name) {
  this->it_inspect = it_inspect;
}


//Destructor
IT_Part::~IT_Part(){}


//Virtual functions
/*
  Function:  inspection
  Purpose:   checks if inspection is required on part
       in:   date
  return:    true if inspection required, false otherwise
*/
bool IT_Part::inspection(Date& date) const{
  return ((date.toDays() - installationDate.toDays()) >= it_inspect);
}

/*
  Function:  print_helper
  Purpose:   Prints part information
       in:   ostream
   return:   nothing
*/
void IT_Part::print_helper(ostream& o){
  Part::print_helper(o);
  o<<"   Inspect Every:   " << it_inspect << " days installed" <<endl;
  o<<"   --------------------------------------"<<endl;
}



//------------------------------------------------------------------------------



//Constructors
FHIT_Part::FHIT_Part(const string& name, int fh_inspect, int it_inspect): Part(name), FH_Part(name, fh_inspect), IT_Part(name, it_inspect){
}


//Destructor
FHIT_Part::~FHIT_Part(){}

/*
  Function:  print_helper
  Purpose:   Prints part information
       in:   ostream
   return:   nothing
*/
void FHIT_Part::print_helper(ostream& o){
  Part::print_helper(o);
  o<<"   Inspect Every:   " << fh_inspect << " flight hours"<<endl;
  o<<"   Inspect Every:   " << it_inspect << " days installed" <<endl;
  o<<"   --------------------------------------"<<endl;
}


//Virtual functions
/*
  Function:  inspection
  Purpose:   checks if inspection is required on part
       in:   date
  return:    true if inspection required, false otherwise
*/
bool FHIT_Part::inspection(Date& date) const{
  if(FH_Part::inspection(date) == true || IT_Part::inspection(date) == true){
    return true;
  }
  return false;
}

//DONE
