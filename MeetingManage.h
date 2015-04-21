//
//  MeetingManage.h
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#ifndef Agenda_MeetingManage_h
#define Agenda_MeetingManage_h
#include "list"
#include "string"
#include "Date.h"
using std::list;
using std::string;

class Meeting;

class MeetingManage{
private:
    static bool instanceFlag;
    static MeetingManage *instance;
    list<Meeting> meetingList;
    
    MeetingManage();
public:
    static MeetingManage *getInstance();
    ~MeetingManage();
    
    bool addMeeting(string sponsor, string participator, Date startDate, Date endDate, string title);
    bool deleteMeeting(string userName, string title);
    bool deleteAllMeetings(string userName);
    
    bool updateMeetingParticipator(string title, string newParticipator);
    bool updateMeetingStartDate(string title, Date newStartDate);
    bool updateMeetingEndDate(string title, Date newEndDate);
    
    Meeting *queryMeetingByTitle(string title);
    list<Meeting> queryMeetingsByTime(string userName, Date startDate, Date endDate);
    list<Meeting> listAllMeetings(string sponsor);
    list<Meeting> listAllSponsorMeetings(string sponsor);
    list<Meeting> listAllParticipatorMeetings(string participator);
};

#endif
