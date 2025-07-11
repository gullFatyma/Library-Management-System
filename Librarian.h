#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Person.h"
#include"utility.cpp"
using namespace std;

class LibrarianCollection;
class Librarian:public Person
 {
private:
//vector<Librarian>lib;
    int librarianId;
public:
    string role;
    int getId();
     
    void setId(int lib_ID) ;

    Librarian() ;
   
    Librarian(int id, string Name,string Email, string Contact, string Role) ;
    Librarian(const Librarian& l);
    //~Librarian();
    void addLibrarian(LibrarianCollection &Li);
    void DisplayL();
   userType getuserType();
    string GetString();
    void ReadString(string line);
   
 };

//collection
class LibrarianCollection:public userCollection
{
  public:
  vector<Librarian>LibrarianCol;
  void AddData(Librarian &lib);
  void DisplayCOLLECTION();
  void FindBy_Id(int Id);
  Librarian* GetLibrarian(int Id);
  void UpdateLibrarian(int Id);
  void RemoveLibrarian(int Id);
  void registerUser() ; 
  void PostRegistrationMenu();
  bool loginUser() ;
  void WriteDataToFile();
  void ReadDataFromFile();

};
    
