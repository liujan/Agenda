#ifndef MEETING_H
#define MEETING_H
#include "string"
#include "Date.h"
using namespace std;


class Meeting{
private:
    string sponsor;
    string participator;
    Date startDate;
    Date endDate;
    string title;
public:
    Meeting();
    Meeting(string s, string p, Date start, Date end, string t);
    string getSponsor();
    void setSponsor(string s);
    string getParticipator();
    void setParticipator(string p);
    Date getStartDate();
    void setStartDate(Date start);
    Date getEndDate();
    void setEndDate(Date end);
    string getTitle();
    void setTitle(string t);
};



#endif
