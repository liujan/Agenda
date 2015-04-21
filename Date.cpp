//
//  Date.cpp
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#include "Date.h"

Date::Date(){ }
Date::Date(int y, int m, int d, int h, int mm){
    this->set(y, m, d, h, mm);
}

void Date::set(int y, int m, int d, int h, int mm){
    this->year = y;
    this->month = m;
    this->day = d;
    this->hour = h;
    this->minute = mm;
}
int Date::getYear(){
    return this->year;
}

void Date::setYear(int y){
    this->year = y;
}

int Date::getMonth(){
    return this->month;
}

void Date::setMonth(int m){
    this->month = m;
}

int Date::getDay(){
    return this->day;
}

void Date::setDay(int d){
    this->day = d;
}

int Date::getHour(){
    return this->hour;
}

void Date::setHour(int h){
    this->hour = h;
}

int Date::getMinute(){
    return this->minute;
}

void Date::setMinute(int mm){
    this->minute = mm;
}

bool Date::isValid(Date date){
    int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    m[1] += isLeap(date.year);
    if (date.year > 9999 || date.year < 1000)
        return false;
    if (date.month < 1 || date.month > 12)
        return false;
    if (date.day < 1 || date.day > m[date.month - 1])
        return false;
    if (date.hour < 0 || date.hour > 24)
        return false;
    if (date.minute < 0 || date.minute > 59)
        return false;
    return true;
    
}

int Date::isLeap(int y){
    if (y % 400 == 0)
        return 1;
    if (y %4 == 0 && y % 100 == 0)
        return 1;
    return 0;
}

bool Date::operator<(const Date &other) const{
    if (this->year < other.year)
        return true;
    if (this->month < other.month)
        return true;
    if (this->day < other.day)
        return true;
    if (this->hour < other.hour)
        return true;
    if (this->minute < other.minute)
        return true;
    return false;
}

bool Date::operator<=(const Date &other) const{
    if (*this < other || *this == other)
        return  true;
    else
        return false;
}

bool Date::operator==(const Date &other) const{
    if (this->year != other.year)
        return false;
    if (this->month != other.month)
        return false;
    if (this->day != other.day)
        return false;
    if (this->hour != other.hour)
        return false;
    if (this->minute != other.minute)
        return false;
    return true;
}

bool Date::operator>(const Date &other) const{
    if (!((*this) < other) && !((*this) == other))
        return true;
    else
        return false;
}

bool Date::operator>=(const Date &other) const{
    if (*this > other || *this == other)
        return true;
    else
        return false;
}

Date& Date::operator=(const Date &other) {
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
    this->hour = other.hour;
    this->minute = other.minute;
    return *this;
}

Date Date::stringToDate(string s){
    int y = 0, m = 0, d = 0, h = 0, mm = 0;
    sscanf_s(s.c_str(), "%d-%d-%d/%d:%d", y, m, d, h, mm);
    return Date(y, m, d, h, mm);
}

string Date::dateToString(Date d){
    char ch[30];
    sscanf_s(ch, "%04d-%02d-%02d/%02d:%02d", d.year, d.month, d.day, d.hour, d.minute);
    return string(ch);
}
