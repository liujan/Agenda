//
//  AgendaService.h
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#ifndef Agenda_AgendaService_h
#define Agenda_AgendaService_h
#include "string"
#include "list"
using std::string;
using std::list;

class MeetingManage;
class UserManage;
class User;
class Date;
class Meeting;


class AgendaService{
private:
    UserManage *userManage;
    MeetingManage *meetingManage;
    
public:
    AgendaService();
    User* userLogin(string userName, string password);
    bool userRegister(string userName, string password, string email, string phone);
    bool deleteUser(User user);
    list<User> listAllUsers();
    
    bool createMeeting(string sponsor, string title, string participator, Date startDate, Date endDate);
    bool updateMeetingParticipator(string title, string newParticipator);
    bool updateMeetingStartDate(string title, Date newStartDate);
    bool updateMeetingEndDate(string title, Date newEndDate);
    bool deleteMeeting(string sponsor, string title);
    bool deleteAllMeetings(string sponsor);
    Meeting* meetingQuery(string title);
    list<Meeting> meetingQuery(string sponsor, Date startDate, Date endDate);
};

#endif
