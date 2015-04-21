//
//  MeetingManage.cpp
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#include "MeetingManage.h"
#include "Meeting.h"
#include "fstream"
#include "iostream"
using std::cout;

bool MeetingManage::instanceFlag = false;
MeetingManage* MeetingManage::instance = NULL;

MeetingManage::MeetingManage(){ }
MeetingManage::~MeetingManage(){
    if (instance){
        delete instance;
        instanceFlag = false;
    }
}

MeetingManage* MeetingManage::getInstance(){
    if (!instance){
        instance = new MeetingManage();
        instanceFlag = true;
		ifstream in("meeting.txt");
		if (!in.is_open()){
			cout << "Error: failed to open file meeting.txt at getInstance" << "\n";
			return instance;
		}
		string sponsor, participator, title, startdate, enddate;
		while (in){
			in >> sponsor >> participator >> startdate >> enddate >> title;
			instance->meetingList.push_back(Meeting(sponsor, participator, Date::stringToDate(startdate), Date::stringToDate(enddate), title));
			while (in.peek() == '\n'){
				in >> sponsor;
			}
		}
		in.close();
    }
    return instance;
}

bool MeetingManage::addMeeting(string sponsor, string participator, Date startDate, Date endDate, string title){
    if (startDate > endDate)
        return false;
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
    
    for (; it != manage->meetingList.end(); it++){
        if (it->getSponsor() == sponsor && it->getTitle() == title)
            return false;
    }
    manage->meetingList.push_back(Meeting(sponsor, participator, startDate, endDate, title));
	ofstream out("meeting.txt", ios::app);
	if (!out.is_open()){
		cout << "Error:failed to open file meeting.txt at addMeeting" << endl;
		exit(-1);
	}
	out << sponsor << " " << participator << " "
		<< Date::dateToString(startDate) << " "
		<< Date::dateToString(endDate) << " "
		<< title << "\n";
	out.close();
    return true;
}

bool MeetingManage::deleteMeeting(string sponsor, string title){
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
	ofstream out("meeting.txt");
	bool flag = false;
    for (; it != manage->meetingList.end(); it++){
        if (it->getSponsor() == sponsor && it->getTitle() == title){
            it = manage->meetingList.erase(it);
            flag =  true;
			if (it == manage->meetingList.end())
				return true;
        }
		else{
			out << it->getSponsor() << " "
				<< it->getParticipator() << " "
				<< Date::dateToString(it->getStartDate()) << " "
				<< Date::dateToString(it->getEndDate()) << " "
				<< it->getTitle() << "\n";
		}
    }
	out.close();
    return flag;
}

bool MeetingManage::deleteAllMeetings(string userName){
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
    bool flag = false;
	ofstream out("meeting.txt");
	if (!out.is_open()){
		cout << "Error:failed to open file meeting.txt at deleteAllMeetings" << "\n";
		exit(-1);
	}
    for (; it != manage->meetingList.end(); it++){
        if (it->getSponsor() == userName){
            it = manage->meetingList.erase(it);
            flag = true;
			if (it == manage->meetingList.end())
				return true;
        }
		else{
			out << it->getSponsor() << " "
				<< it->getParticipator() << " "
				<< Date::dateToString(it->getStartDate()) << " "
				<< Date::dateToString(it->getEndDate()) << " "
				<< it->getTitle() << "\n";
		}
    }
	out.close();
    return flag;
}

bool MeetingManage::updateMeetingParticipator(string title, string newParticipator){
	MeetingManage *manage = this->getInstance();
	list<Meeting>::iterator it = manage->meetingList.begin();
	ofstream out("meeting.txt");
	bool flag = false;
	if (!out.is_open()){
		cout << "Error:failed to open file meeting.txt at updateMeetingParticipator" << "\n";
		exit(-1);
	}
	for (; it != manage->meetingList.end(); it++){
		if (it->getTitle() == title){
			it->setParticipator(newParticipator);
			flag =  true;
		}

		out << it->getSponsor() << " "
			<< it->getParticipator() << " "
			<< Date::dateToString(it->getStartDate()) << " "
			<< Date::dateToString(it->getEndDate()) << " "
			<< it->getTitle() << "\n";

	}
	out.close();
	return flag;
}

bool MeetingManage::updateMeetingStartDate(string title, Date newStartDate){
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
	ofstream out("meeting.txt");
	bool flag = false;
	if (!out.is_open()){
		cout << "Error:failed to open file meeting.txt at updateMeetingStartDate" << "\n";
		exit(-1);
	}
    for (; it != manage->meetingList.end(); it++){
        if (it->getTitle() == title){
            it->setStartDate(newStartDate);
            flag =  true;
        }
		out << it->getSponsor() << " "
			<< it->getParticipator() << " "
			<< Date::dateToString(it->getStartDate()) << " "
			<< Date::dateToString(it->getEndDate()) << " "
			<< it->getTitle() << "\n";
    }
    return flag;
}

bool MeetingManage::updateMeetingEndDate(string title, Date newEndDate){
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
	ofstream out("meeting.txt");
	bool flag = false;
	if (!out.is_open()){
		cout << "Error:failed to open file meeting.txt at updateMeetingEndDate" << "\n";
		exit(-1);
	}
    for (; it != manage->meetingList.end(); it++){
        if (it->getTitle() == title){
            it->setEndDate(newEndDate);
            flag =  true;
        }
		out << it->getSponsor() << " "
			<< it->getParticipator() << " "
			<< Date::dateToString(it->getStartDate()) << " "
			<< Date::dateToString(it->getEndDate()) << " "
			<< it->getTitle() << "\n";
    }
	out.close();
    return flag;
}

Meeting * MeetingManage::queryMeetingByTitle(string title){
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
    
    for (; it != manage->meetingList.end(); it++){
        if (it->getTitle() == title){
			Meeting *meeting = new Meeting(it->getSponsor(), it->getParticipator(), it->getStartDate(), it->getEndDate(), it->getTitle());
			return meeting;
        }
    }
    return NULL;
}

list<Meeting> MeetingManage::queryMeetingsByTime(string userName, Date startDate, Date endDate){
    list<Meeting> meetings;
    if (startDate > endDate)
        return meetings;
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
    for (; it != manage->meetingList.end(); it++){
        if (it->getSponsor() == userName){
            if (it->getStartDate() >= startDate && it->getEndDate() <= endDate)
                meetings.push_back(*it);
        }
    }
    return meetings;
}

list<Meeting> MeetingManage::listAllMeetings(string userName){
    list<Meeting> meetings;
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
    
    for (; it != manage->meetingList.end(); it++){
        if (it->getSponsor() == userName || it->getParticipator() == userName)
            meetings.push_back(*it);
    }
    return meetings;
}

list<Meeting> MeetingManage::listAllSponsorMeetings(string sponsor){
    list<Meeting> meetings;
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
    
    for (; it != manage->meetingList.end(); it++){
        if (it->getSponsor() == sponsor)
            meetings.push_back(*it);
    }
    return meetings;
}

list<Meeting> MeetingManage::listAllParticipatorMeetings(string participator){
    list<Meeting> meetings;
    MeetingManage *manage = this->getInstance();
    list<Meeting>::iterator it = manage->meetingList.begin();
    
    for (; it != manage->meetingList.end(); it++){
        if (it->getParticipator() == participator)
            meetings.push_back(*it);
        }
    return meetings;
}