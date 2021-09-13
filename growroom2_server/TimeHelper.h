#include <Arduino.h>
#include "Pin.h"
#ifndef H_Pin
#define H_Pin

long midnight;


class TimeHelper {
  private:
    int day=1;
    int month=1;
    int year=1;
  public:
    TimeHelper(int hour, int minute){
     setNow(hour, minute);
    }
    void setNow(int hour, int minute) {
        midNight = millis() - _HOUR * hour - _MINUTE * minute;
    }
    void setYearMonthDay(int year, int month, int day) {
      this->year = year;
      this->month = month;
      this->day = day;
    }
    int getYear() {
       return year;
    }
    int getMonth() {
       return month;
    }
    int getDay() {
       return day;
    }
    int getHour() {
        return (getNow() / _HOUR)%24;
    }
    int getMinute() {
        return (getNow() / _MINUTE)%60;
    }

    void updateDay() {
      
      if(month == 2 && day == 28) {
        if(year%4 != 0) {
          month++;
          day = 1;
        }
      } else if (month == 2 && day == 29) {
        if(year%4 == 0) {
          month++;
          day = 1;
        }
      } else if (day == 30) {
        if(month == 2 ||month == 4 ||month == 6 ||month == 9 ||month == 11)   {
          month++;
          day = 1;
        }
      } else if (day == 31) {
        if(month == 1 ||month == 3 ||month == 5 ||month == 7 ||month == 8||month == 10||month == 12)   {
          month++;
          day = 1;
        }  
      }
      if(month == 13) {
        month =1;
        year++;
      }
    }

    // milli second from mid night
    long getNow() {
      return millis() - midNight ;
    }
    const long _SECOND = 1000;
    const long _MINUTE = 60 * _SECOND;
    const long _HOUR = 60 * _MINUTE;
    const long _DAY = 24 * _HOUR;
    
    long midNight = 0;
};



#endif
