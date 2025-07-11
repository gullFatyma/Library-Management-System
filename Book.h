#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#pragma once

using namespace std;
class BookCollection;
class Book 
{
private:
    int bookID;
public:
    string title;
    string author;
    string publisher_name;
    int totalCopies;
    int GetId();
    void SetId(int book_ID);
    Book();
    Book(int ID, string t,string pub, string a,int TCopies) ;
    Book(const Book &b);
    void addBook(BookCollection &collection);
    void displayBook();
    string GetString();
    void ReadString(string line);
  
};

class BookCollection
{ 
  private:
vector<Book>books;
 public:
  void Addbook(Book &b);
  void DisplayBOOk();
  Book* GetBook(int id);
  void UpdateBOOk(int id);
  void FindBook(int id);
  void RemoveBook(int id);
   void WriteDataToFile();
  void ReadDataFromFile();

};
