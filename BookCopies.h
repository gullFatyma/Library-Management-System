#pragma once
#include<iostream>
#include"Book.h"
#include"Book.cpp"
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class BookCopies_Collection;
class BookCopies
{
    public:
   string CopyID;
   string Location;
   char availablityStatus;
   Book* book;
   BookCopies();
   BookCopies(string copyId,string Loc, char Status,Book* bOok);
   BookCopies(const BookCopies &bb);
   void AddCopies(BookCopies_Collection &Copy,BookCollection &collection);
   void Display(); 
   string GetString();
};

class BookCopies_Collection
{
    public:
vector<BookCopies>copyCol;
void AddBookCopies(BookCopies &B);
void DisplayBOOks();
BookCopies* GetBookCopy(string Id);
void Updatecopy(string Id);
void FindBYID(string idd);
void remove(string Id);
void WriteDataToFile();
void ReadDataFromFile(BookCollection &books);
};
