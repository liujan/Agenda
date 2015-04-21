#ifndef USER_H
#define USER_H
#include "string"
#include "list"
using namespace std;

class Meeting;

class User{
private:
    string name;
    string password;
    string email;
    string phone;
public:
    User(string _name, string pwd, string _email, string _phone);
    string getName();
    void setName(string _name);
    
    string getPassword();
    void setPassword(string pwd);
    
    string getEmail();
    void setEmail(string _email);
    
    string getPhone();
    void setPhone(string _phone);
    
    list<Meeting> getAllMeetings();
    list<Meeting> getAllSponsorMeetings();
    list<Meeting> getAllParticipateMeetings();
    
};

#endif
