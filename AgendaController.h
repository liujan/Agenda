//
//  AgendaController.h
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#ifndef Agenda_AgendaController_h
#define Agenda_AgendaController_h
#include "AgendaService.h"
#include "string"
#include "list"
using std::string;
using std::list;

class User;
class Meeting;

class AgendaController{
private:
    User *currentUser;
    AgendaService agendaService;
    
    bool executeOperator(string op);
    
    void userLogin();
    void userRegister();
    void userLogout();
    void deleteUser();
    void listAllUsers();
    
    void createMeeting();
    void listAllMeetings();
    void listAllSponsorMeetings();
    void listAllParticipateMeetings();
    void queryMeetingByTitle();
    void queryMeetingByTimeInterval();
    void updateMeetingParticipator();
    void updateMeetingStartDate();
    void updateMeetingEndDate();
    void deleteMeetingByTitle();
    void deleteAllMeetings();
    
    void printMeetings(list<Meeting> meetings);
    void response(string message, bool flag);
    void printMenu();
    
public:
    AgendaController();
    void getOperation();
};

#endif
