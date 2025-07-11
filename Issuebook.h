#pragma once
#include<iostream>
#include<string>
#include"Date.h"
#include "Member.h"
#include "Book.h"
#include"BookCopies.h"
//#include"BookCopies.cpp"
#include "Librarian.h"
#include<fstream>

using namespace std;
class FineCollection;
class IssueBook_collection;
class IssueBook
{
private:
int IssueBookId;
 Member* borrowID;
 Librarian* issuedby;
 BookCopies Bookborrowed;   
 public:              
 Date IssueDate;
 Date Actual_Returndate;    
 Date ReturnDate;
 char isReturned;

 int getTid();
 void setIssueBookID(int TrId);  //IssueBookId

  IssueBook();
  IssueBook(int TrID ,Librarian* L, Member* bId,BookCopies Borrowed, Date Idate,Date AD,Date ReturnD,char isReturn);
  IssueBook(const IssueBook &t);
  void addIssueBook_data(IssueBook_collection &issue,BookCopies_Collection &Copy,MemberCollection &Collectionn,LibrarianCollection &LiCollection);
  void display();
  string GetString();
  void ReadString(const string& line, MemberCollection& members, LibrarianCollection& librarians, BookCopies_Collection& copies);
  ~IssueBook();
Member* getBorrower();
};

class IssueBook_collection
{
public:
vector<IssueBook>Ibooks;
void ADDbooks_details(IssueBook &I);
void Display();
IssueBook* GetIssueBook(int Id);
void Update(int Id);
void RemoveTransaction(int ID);
void Find(int id);
void CheckAnd_Generate_Fine(FineCollection &finee,MemberCollection &Collection);
void WriteDataToFile();
void ReadDataFromFile(MemberCollection& members, LibrarianCollection& librarians, BookCopies_Collection& copies);
void DisplayByMemberId(int memberId);
};