
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Person.h"
#include"Date.h"


using namespace std; 
class MemberCollection;
class Member:public Person, Date
 {
private:
//vector<Member>mem;
    int memberID;
public:
     Date DateOf_joining;
     int getId();
     void SetId(int mem_ID) ;
    Member();
    Member(int id,Date DOJ, string Name, string Email,string contacT);
     //~Member();
     Member(const Member&m);
     void addMember(MemberCollection &Collectionn);
     void displayMember();
     string GetString();
     void ReadString(string line);
    userType getuserType();
    
    
 };  
 
 class MemberCollection:public userCollection
 {
   public:
   vector<Member>Members;
   void AddMember(Member &Mem);
   void DisplayCollection();
   void FindBy_Id(int ID);
   Member* GetMember(int Id);
   void UpdateMember(int Id);
   void RemoveMember(int Id);
   void registerUser() ;
  void PostRegistrationMenu();
   bool loginUser() ;
  void WriteDataToFile();
  void ReadDataFromFile();
 };
