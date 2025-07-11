#include<iostream>
#include<string>
#include"IssueBook.h"
#include"Member.h"
#include<ctime>
#include<fstream>
#pragma once
using namespace std;
class FineCollection;
class fine
{  
    public:
IssueBook* TId;
  int fineAmount;
 Date date_ToPay;
 bool isPaid;
 fine();
 fine(IssueBook* id);
    fine(const fine &f);
    void calculateFine();
    void display();
    void PayFine();
    string GetString();
    void ReadString(const string& line);
    //~fine();
};

class FineCollection
{
public:
    vector<fine> fineList;
    void AddFine(fine &f);
    void Display();
    fine* GetFine(int Tid);
    void Update(int Tid);
    void RemoveFine(int Tid);
    void Find(int Tid);
     void WriteDataToFile();
     void ReadDataFromFile();
      void DisplayByMemberId(int memberId);
};
