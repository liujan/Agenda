//
//  AgendaService.cpp
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#include "AgendaService.h"
#include "UserManage.h"
#include "MeetingManage.h"
#include "Date.h"
#include "Meeting.h"
#include "User.h"
#include "fstream"

AgendaService::AgendaService(){
    userManage = UserManage::getInstance();
    meetingManage = MeetingManage::getInstance();
	

}

User* AgendaService::userLogin(string userName, string password){
    list<User> users = userManage->listAllUsers();
    list<User>::iterator it = users.begin();
    for (; it != users.end(); it++){
        if (it->getName() == userName && it->getPassword() == password){
			User *user = new User(it->getName(), it->getPassword(), it->getEmail(), it->getEmail());
			return user;
        }
    }
    return NULL;
}

bool AgendaService::userRegister(string userName, string password, string email, string phone){
    return userManage->createUser(userName, password, email, phone);
}

bool AgendaService::deleteUser(User user){
    return userManage->deleteUser(user);
}

list<User> AgendaService::listAllUsers(){
    return userManage->listAllUsers();
}

bool AgendaService::createMeeting(string sponsor, string title, string participator, Date startDate, Date endDate){
    return meetingManage->addMeeting(sponsor, participator, startDate, endDate, title);
}

bool AgendaService::updateMeetingEndDate(string title, Date newEndDate){
    return meetingManage->updateMeetingEndDate(title, newEndDate);
}

bool AgendaService::updateMeetingParticipator(string title, string newParticipator){
    return meetingManage->updateMeetingParticipator(title, newParticipator);
}

bool AgendaService::updateMeetingStartDate(string title, Date newStartDate){
    return meetingManage->updateMeetingStartDate(title, newStartDate);
}

bool AgendaService::deleteMeeting(string sponsor, string title){
    return meetingManage->deleteMeeting(sponsor, title);
}

bool AgendaService::deleteAllMeetings(string sponsor){
    return meetingManage->deleteAllMeetings(sponsor);
}

Meeting* AgendaService::meetingQuery(string title){
    return meetingManage->queryMeetingByTitle(title);
}

list<Meeting> AgendaService::meetingQuery(string sponsor, Date startDate, Date endDate){
    return meetingManage->queryMeetingsByTime(sponsor, startDate, endDate);
}

