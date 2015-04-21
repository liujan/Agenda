//
//  UserManage.cpp
//  Agenda
//
//  Created by 刘建安 on 4/20/15.
//  Copyright (c) 2015 刘建安. All rights reserved.
//

#include "UserManage.h"
#include "User.h"
#include "fstream"

bool UserManage::instanceFlag = false;
UserManage* UserManage::instance = NULL;

UserManage::UserManage(){}

UserManage::~UserManage(){
    if (instance){
        delete instance;
        instanceFlag = false;
    }
}
UserManage* UserManage::getInstance(){
    if (!instance){
        instance = new UserManage();
        instanceFlag = true;
        ifstream in("users.txt");
		if (!in.is_open()){
			return instance;
		}
        while(in){
            string name, pwd, email, phone;
			
            in >> name >> pwd >> email >> phone;
            instance->userList.push_back(User(name, pwd, email, phone));
			while (in.peek() == '\n'){
				in >> name;
			}
        }
        in.close();
    }
    return instance;
}

bool UserManage::createUser(string name,string pwd, string email, string phone){
    UserManage *manage = this->getInstance();
    list<User>::iterator it = manage->userList.begin();
    for (; it != manage->userList.end(); it++){
        if (it->getName() == name)
            return false;
    }
    manage->userList.push_back(User(name, pwd, email, phone));
    ofstream users("users.txt", ios::app);
    users << name << " " << pwd << " " << email << " " << phone << "\n";
    users.close();
    return true;
}

bool UserManage::deleteUser(User u){
    UserManage *manage = this->getInstance();
    list<User>::iterator it = manage->userList.begin();
    bool flag = false;
    ofstream users("users.txt");
    for (; it != manage->userList.end(); it ++){
        if (it->getName() == u.getName()){
            it = manage->userList.erase(it);
            flag = true;
			if (it == manage->userList.end())
				return true;
        }
        else
            users << it->getName() << " " << it->getPassword() << " " << it->getEmail() << " " << it->getPhone() << "\n";
    }
    users.close();
    return flag;
}

bool UserManage::updateUserPassword(User u, string pwd){
    UserManage *manage = this->getInstance();
    ofstream users("users.txt");
    bool flag = false;
    list<User>::iterator it = manage->userList.begin();
    for (; it != manage->userList.end(); it++){
        if (it->getName() == u.getName()){
            it->setPassword(pwd);
            flag = true;
        }
        users << it->getName() << " " << it->getPassword() << " " << it->getEmail() << " " << it->getPhone() << "\n";
    }
    users.close();
    return flag;
}

bool UserManage::updateUserEmail(User u, string email){
    UserManage *manage = this->getInstance();
    list<User>::iterator it = manage->userList.begin();
    ofstream users("users.txt");
    bool flag = false;
    for (; it != manage->userList.end(); it++){
        if (it->getName() == u.getName()){
            it->setEmail(email);
            flag = true;
        }
        users << it->getName() << " " << it->getPassword() << " " << it->getEmail() << " " << it->getPhone() << "\n";
    }
    users.close();
    return flag;
}

bool UserManage::updateUserPhone(User u, string phone){
    UserManage *manage = this->getInstance();
    ofstream users("users.txt");
    bool flag = false;
    list<User>::iterator it = manage->userList.begin();
    for (; it != manage->userList.end(); it++){
        if (it->getName() == u.getName()){
            it->setPhone(phone);
            flag = true;
        }
        users << it->getName() << " " << it->getPassword() << " " << it->getEmail() << " " << it->getPhone() << "\n";
    }
    return flag;
}

list<User> UserManage::listAllUsers(){
    UserManage *manage = this->getInstance();
    return manage->userList;
}