#include "User.h"
#include "string"
#include "list"
#include "Meeting.h"
#include "MeetingManage.h"
using namespace std;

User::User(string _name, string pwd, string _email, string _phone){
	this->name = _name;
	this->password = pwd;
	this->email = _email;
	this->phone = _phone;
}

string User::getName(){
	return this->name;
}

void User::setName(string _name){
	this->name = _name;
}

string User::getPassword(){
	return this->password;
}

void User::setPassword(string pwd){
	this->password = pwd;
}

string User::getEmail(){
	return this->email;
}

void User::setEmail(string _email){
	this->email = _email;
}

string User::getPhone(){
	return this->phone;
}

void User::setPhone(string _phone){
	this->phone = _phone;
}

list<Meeting> User::getAllMeetings(){
    MeetingManage * manage = MeetingManage::getInstance();
    return manage->listAllMeetings(this->name);
}

list<Meeting> User::getAllSponsorMeetings(){
    MeetingManage *manage = MeetingManage::getInstance();
    return manage->listAllSponsorMeetings(this->name);
}

list<Meeting> User::getAllParticipateMeetings(){
    MeetingManage *manage = MeetingManage::getInstance();
    return manage->listAllParticipatorMeetings(this->name);
}