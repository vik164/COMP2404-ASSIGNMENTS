#include "Date.h"

//Constructors
Date::Date(int y, int m, int d, int h, int dur){
	setDate(y, m, d, h, dur);
}

Date::Date(){
	setDate(1901,1,1,0,1);
}

Date::Date(Date& d){
	//setDate(d.year, d.month, d.day, d.hour, d.duration);
	setDate(d);
}


//Setters
void Date::setHour(int h){
  if(h > 23) h = 23;
  if(h < 0) h = 0;
  hour = h;
}

void Date::setDuration(int dur){
  if(dur >= MAX_DUR) dur = MAX_DUR;
  if(dur < 1) dur = 1;
  duration = dur;
}

void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setDate(int y, int m, int d, int h, int dur){
	setMonth(m);
	setDay(d);
	setYear(y);
  setHour(h);
  setDuration(dur);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}


//Getters
int Date::getHour(){ return hour; }
int Date::getDuration(){ return duration; }
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
const string& Date::getMonthName(){return months[month-1];}


//Other functions
/*
  Function:  lessThan
  Purpose:   compare if date1 comes before date2
       in:   date2
   return:   true if date1 comes before date2, otherwise false
*/
bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
      if(day == d.day){
        return hour < d.hour;
      }
      else{
        return day < d.day;
      }
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}
}

/*
  Function:  overlaps
  Purpose:   checks if date1 overlaps with date2
       in:   date2
   return:   true if dates overlap, otherwise false
*/
bool Date::overlaps(Date& d){
	if(year == d.year){
    if(month == d.month){
      if(day == d.day){
        if(hour == d.hour){
          return true;
    	  }
        else if((duration + hour > d.hour) && (d.duration + d.hour > hour)){
          return true;
        }
      }
    }
  }
  return false;
}

void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear()<< ", TIME = "<<getHour()<<":00, DURATION = "<<getDuration()<<"h"<<endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

//DONE
