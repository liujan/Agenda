#include "Meeting.h"


Meeting::Meeting(){ }

Meeting::Meeting(string s, string p, Date start, Date end, string t){
	this->sponsor = s;
	this->participator = p;
	this->startDate = start;
	this->endDate = end;
	this->title = t;
}

string Meeting::getSponsor(){
	return this->sponsor;
}

void Meeting::setSponsor(string s){
	this->sponsor = s;
}

string Meeting::getParticipator(){
	return this->participator;
}

void Meeting::setParticipator(string p){
	this->participator = p;
}

Date Meeting::getStartDate(){
	return this->startDate;
}

void Meeting::setStartDate(Date start){
	this->startDate = start;
}

Date Meeting::getEndDate(){
	return this->endDate;
}

void Meeting::setEndDate(Date end){
	this->endDate = end;
}

string Meeting::getTitle(){
	return this->title;
}

void Meeting::setTitle(string t){
	this->title = t;
}
