#include<iostream>
#include<string>
#include<fstream>
#pragma once

using namespace std;

enum class userType
{
 LIBRARIAN,MEMBER
};

class Person
{
private:
  string contact;
    public:
    string email;
    string name;

    void setContact(string con);
    string getContact();
    Person();
     Person(string name,string email, string con);
    Person(const Person &P);
    virtual userType getuserType()=0;  
    
};

class userCollection
{
    public:
        virtual void registerUser() = 0;
        virtual bool loginUser() = 0;
        virtual ~userCollection() {}
        virtual void WriteDataToFile()=0;
        virtual void ReadDataFromFile()=0;
};