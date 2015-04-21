//
//  Date.h
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#ifndef Agenda_Date_h
#define Agenda_Date_h
#include "string"
using namespace std;

class Date{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    
public:
    Date();
    Date(int y, int m, int d, int h, int mm);
    void set(int y, int m, int d, int h, int mm);
    
    int getYear();
    void setYear(int y);
    
    int getMonth();
    void setMonth(int m);
    
    int getDay();
    void setDay(int d);
    
    int getHour();
    void setHour(int h);
    
    int getMinute();
    void setMinute(int mm);
    
    static bool isValid(Date date);
    static int isLeap(int y);
    bool operator<(const Date &other) const;
    bool operator==(const Date &other) const;
    bool operator>(const Date &other) const;
    bool operator>=(const Date &other) const;
    bool operator<=(const Date &other) const;
    Date& operator=(const Date &other);
    static Date stringToDate(string s);
    static string dateToString(Date d);
};

#endif
