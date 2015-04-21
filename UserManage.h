//
//  UserManage.h
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#ifndef Agenda_UserManage_h
#define Agenda_UserManage_h
#include "list"
#include "string"
using std::string;
using std::list;

class User;

class UserManage{
private:
    static bool instanceFlag;
    static UserManage *instance;
    list<User> userList;
    
    UserManage();
    
public:
    static UserManage* getInstance();
    ~UserManage();
    
    bool createUser(string name, string pwd, string email, string phone);
    bool deleteUser(User u);
    bool updateUserPassword(User u, string pwd);
    bool updateUserEmail(User u, string email);
    bool updateUserPhone(User u, string phone);
    
    list<User> listAllUsers();
};

#endif
