#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
using namespace std;

const int MAX_DUR = 3;

class Date {
  public:
    //Constructors
    Date(int year, int month, int day, int hour, int duration);
    Date();
    Date(Date&);

    //Setters
    void setHour(int);
    void setDuration(int);
    void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int y, int m, int d, int h, int dur);
		void setDate(Date&);

    //Getters
    int getHour();
    int getDuration();
    int getDay();
		int getMonth();
		int getYear();
		const string& getMonthName();

    //Other functions
    bool lessThan(Date& d);
    bool overlaps(Date& d);
		void print();


  private:
    int getMaxDay();
    int hour;
    int duration;
    int day;
		int month;
		int year;

    const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		const string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
};

#endif

//DONE
