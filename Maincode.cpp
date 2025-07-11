#include<iostream>
#include<string>
#include<iomanip>
#include"Implementation.cpp"
#include "Book.cpp"
#include"person.cpp"
#include"BookCopies.cpp"
#include"Member.cpp"
#include"Librarian.cpp"
#include"Issuebook.cpp"
#include"Fine.cpp"
#include<string>
#include"Library.cpp"

using namespace std;

void setcolor(int textcolor);
void resetcolor();
void BookMenu();
void MemberMenu();
void LibrarianMenu();
void TransactionMenu();
void FineMenu();
void loginMenu();
void Main_menu();


int main()
 { 
    LiCollection.ReadDataFromFile();
    Collectionn.ReadDataFromFile();
    collection.ReadDataFromFile();
    issue.ReadDataFromFile(Collectionn,LiCollection, Copy);
    Copy.ReadDataFromFile(collection);
    finee.ReadDataFromFile();
    loginMenu();
    system("cls");
    return 0;

}

