//
//  AgendaController.cpp
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#include "AgendaController.h"
#include "iostream"
#include "AgendaService.h"
#include "User.h"
#include "Date.h"
#include "string"
#include "Meeting.h"
#include "fstream"
using std::string;
using std::cin;
using std::cout;
using std::endl;

AgendaController::AgendaController(){

    this->currentUser = NULL;
	
}
void AgendaController::userLogin(){
    string name, pwd;
    cout << "Login" << endl;
    cout << "Please input your username and password : ";
    cin >> name >> pwd;
    currentUser = agendaService.userLogin(name, pwd);
    this->response("log in", currentUser != NULL);
    if (currentUser != NULL){
        this->printMenu();
    }
}

void AgendaController::userRegister(){
    string name, pwd, email, phone;
    cout << "Register" << endl;
    cout << "Please input your username, password, email, phone : ";
    cin >> name >> pwd >> email >> phone;
    bool flag = agendaService.userRegister(name, pwd, email, phone);
    
    this->response("register", flag);
}

void AgendaController::userLogout(){
    currentUser = NULL;
    this->response("log out", true);
}

void AgendaController::deleteUser(){
	bool flag = agendaService.deleteUser(*currentUser);

    if (flag)
        currentUser = NULL;
    this->response("delete user", flag);
}

void AgendaController::listAllUsers(){
    cout << "list all users" << endl;
    printf("%-8s%-16s%-11s\n", "name", "email", "phone");
    list<User> userList = agendaService.listAllUsers();
    list<User>::iterator it = userList.begin();
    
    for (; it != userList.end(); it++){
        printf("%-8s%-16s%-11s\n", it->getName().c_str(), it->getEmail().c_str(), it->getPhone().c_str());
    }
    cout << endl;
}

void AgendaController::createMeeting(){
    cout << "creating meeting" << endl;
    cout << "input title, participator, start time(yyyy-mm-dd/hh:mm), end time(yyyy-mm-dd/hh:mm) : ";
    string participator, starttime, endtime, title;
    cin >> title >> participator >> starttime >> endtime;
    Date starDate = Date::stringToDate(starttime);
    Date endDate = Date::stringToDate(endtime);
    
    agendaService.createMeeting(currentUser->getName(), title, participator, starDate, endDate);
}

void AgendaController::listAllMeetings(){
    cout << "list all meetings : " << endl;
    list<Meeting> meetings = currentUser->getAllMeetings();
    
    printMeetings(meetings);
}

void AgendaController::listAllSponsorMeetings(){
    cout << "list all sponsor meetings : " << endl;
    list<Meeting> meetings = currentUser->getAllSponsorMeetings();
    
    printMeetings(meetings);
}

void AgendaController::listAllParticipateMeetings(){
    cout << "list all participate meetings : " << endl;
    list<Meeting> meetings = currentUser->getAllParticipateMeetings();
    
    printMeetings(meetings);
}

void AgendaController::queryMeetingByTitle(){
    cout << "query meeting by title" << endl;
    cout << "please input the title : " << endl;
    string title;
    cin >> title;
    
    Meeting *meeting = agendaService.meetingQuery(title);
    printf("%-16s%-16s%-25s%-25s\n", "sponsor", "participator", "start time", "end time");
    printf("%-16s", meeting->getSponsor().c_str());
    printf("%-16s", meeting->getParticipator().c_str());
    printf("%-25s", Date::dateToString(meeting->getStartDate()).c_str());
    printf("%-25s\n", Date::dateToString(meeting->getEndDate()).c_str());
}

void AgendaController::queryMeetingByTimeInterval(){
    string startdate, enddate;
    cout << "query meeting by time interval" << endl;
    cout << "please input start time[yyyy-mm-dd/hh:mm] : ";
    cin >> startdate;
    cout << "please intput end time[yyyy-mm-dd/hh:mm] : ";
    cin >> enddate;
    
    list<Meeting> meetings = agendaService.meetingQuery(currentUser->getName(), Date::stringToDate(startdate), Date::stringToDate(enddate));
    
    printMeetings(meetings);
}

void AgendaController::updateMeetingParticipator(){
    cout << "update meeting participator" << endl;
    string participator;
    string title;
    cout << "input the meeting title : ";
    cin >> title;
    cout << "input the new participator : ";
    cin >> participator;
    bool flag = agendaService.updateMeetingParticipator(title, participator);
    
    this->response("update meeting particiaptr", flag);
}

void AgendaController::updateMeetingStartDate(){
    cout << "update meeting start date" << endl;
    string title, startdate;
    cout << "input the meeting title : ";
    cin >> title;
    cout << "input the new start date[yyyy-mm-dd/hh:mm] : ";
    cin >> startdate;
    
    bool flag = agendaService.updateMeetingStartDate(title, Date::stringToDate(startdate));
    this->response("update meeting start date", flag);
}

void AgendaController::updateMeetingEndDate(){
    cout << "update meeting end date" << endl;
    string title, enddate;
    cout << "input the meeting title : ";
    cin >> title;
    cout << "input the new end date[yyyy-mm-dd/hh:mm] : ";
    cin >> enddate;
    
    bool flag = agendaService.updateMeetingEndDate(title, Date::stringToDate(enddate));
    this->response(title, flag);
}

void AgendaController::deleteMeetingByTitle(){
    cout << "delete meeting by title" << endl;
    string title;
    cout << "input the meeting title : ";
    cin >> title;
    
    bool flag = agendaService.deleteMeeting(currentUser->getName(), title);
    this->response("delete meeting by title", flag);
}

void AgendaController::deleteAllMeetings(){
    cout << "delete all meetings" << endl;
    
    bool flag = agendaService.deleteAllMeetings(currentUser->getName());
    this->response("delete all meetings", flag);
}

void AgendaController::printMeetings(list<Meeting> meetings){
    printf("%-16s%-16s%-25s%-25s\n", "sponsor", "participator", "start time", "end time");
    list<Meeting>::iterator it = meetings.begin();
    for (; it != meetings.end(); it++){
        printf("%-16s", it->getSponsor().c_str());
        printf("%-16s", it->getParticipator().c_str());
        printf("%-25s", Date::dateToString(it->getStartDate()).c_str());
        printf("%-25s\n", Date::dateToString(it->getEndDate()).c_str());
    }
}

void AgendaController::response(string message, bool flag){
    if (flag){
        cout << message << " successful" << endl;
    }
    else{
        cout << message << " failed" << endl;
    }
}

void AgendaController::printMenu(){
    for (int i = 0; i < 23; i++)
        cout << '-';
    cout << "Agenda ";
    for (int i = 0; i < 31; i++)
        cout << '-';
    cout << endl;
    cout << "Action : " << endl;
    if (currentUser == NULL){
        cout << "l   -  log in Agenda by user name and password" << endl;
        cout << "r   -  register an Agenda account" << endl;
        cout << "q   -  quit Agenda" << endl;
        cout << "p   -  print Menu" << endl;
    }
    else{
        cout << "o   -  log out Agenda" << endl;
        cout << "dc  -  delete Agenda acount" << endl;
        cout << "lu  -  list all Agenda users" << endl;
        cout << "cm  -  create a meeting" << endl;
        cout << "la  -  list all meetings" << endl;
        cout << "las -  list all sponsor meetings" << endl;
        cout << "lap -  list all participator meetings" << endl;
        cout << "qm  -  query meeting by title" << endl;
        cout << "qt  -  query meeting by time interval" << endl;
        cout << "up  -  update meeting participator" << endl;
        cout << "us  -  update meeting start date" << endl;
        cout << "ue  -  update meeting end date" << endl;
        cout << "dm  -  delete meeting by title" << endl;
        cout << "da  -  delete all meetings" << endl;
        cout << "p   -  print menu" << endl;
    }
}

void AgendaController::getOperation(){
    
    string op;
    while (true) {
		this->printMenu();
        cout << "Agenda";
		
        if (currentUser == NULL)
            cout << " :~$";
        else
            cout << "@" << currentUser->getName() << " :# ";
        cin >> op;
        if (!this->executeOperator(op))
            break;
    }
}

bool AgendaController::executeOperator(string op){
    if (currentUser == NULL){
        if (op == "l")
            this->userLogin();
        else if ("r" == op)
            this->userRegister();
        else if ("q" == op)
            return false;
        else if ("p" == op)
            this->printMenu();
        else
            cout << "error:command not found" << endl;
    }
    else {
        if ("o" == op)
            this->userLogout();
        else if ("dc" == op)
            this->deleteUser();
        else if ("lu" == op)
            this->listAllUsers();
        else if ("cm" == op)
            this->createMeeting();
        else if ("la" == op)
            this->listAllMeetings();
        else if ("las" == op)
            this->listAllSponsorMeetings();
        else if ("lap" == op)
            this->listAllParticipateMeetings();
        else if ("qm" == op)
            this->queryMeetingByTitle();
        else if ("qt" == op)
            this->queryMeetingByTimeInterval();
        else if ("up" == op)
            this->updateMeetingParticipator();
        else if ("us" == op)
            this->updateMeetingStartDate();
        else if ("ue" == op)
            this->updateMeetingEndDate();
        else if ("dm" == op)
            this->deleteMeetingByTitle();
        else if ("da" == op)
            this->deleteAllMeetings();
        else if ("p" == op)
            this->printMenu();
        else
            cout << "error:command not found" << endl;
    }
    return true;
}