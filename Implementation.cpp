#pragma once
#include<iostream>
#include<iomanip>
#include "Book.h"
#include"BookCopies.h"
#include"Member.h"
#include"Librarian.h"
#include"Issuebook.h"
#include"Fine.h"
#include<string>
#include"Library.cpp"
#include"utility.cpp"
//#include"Person.h"

using namespace std;

    //set color function
    void setcolor(int textcolor)
    {
    cout<<"\033["<<textcolor<<"m";
    }

    //Reset color function
   void resetcolor()
    {
    setcolor(0);
    }

void BookMenu();
void MemberMenu();
void LibrarianMenu();
void TransactionMenu();
void FineMenu();

BookCollection collection;
MemberCollection Collectionn;
LibrarianCollection LiCollection;
BookCopies_Collection Copy;
IssueBook_collection issue;
FineCollection finee;
Library lib;



//**Main menu Function**
void Main_menu() 
{ 
    int choice;
    do
    {
     {
     setcolor(35);
    cout<<setw(70)<<"+-----------------------------------------+"<<endl;
    cout<<setw(70)<<"|      LIBRARY MANAGEMENT SYSTEM         |"<<endl;
    cout<<setw(70)<<"+-----------------------------------------+"<<endl;
    cout<<setw(34)<<"+---------------------------+"<<setw(56)<<"+---------------------------+"<<endl;
    cout<<setw(34)<<"|   1. Book Managment       |"<<setw(56)<<"|   2. Member Managment     |"<<endl;
    cout<<setw(34)<<"+---------------------------+"<<setw(56)<<"+---------------------------+"<<endl;
    cout<<endl;
    cout<<setw(34)<<"|   3. Librarian Managment  |"<<setw(56)<<"| 4. Transaction Managment  |"<<endl;
    cout<<setw(34)<<"+---------------------------+"<<setw(56)<<"+---------------------------+"<<endl;
    cout<<endl;
    cout<<setw(34)<<"|    5.Fine Managment       |"<<setw(56)<<"|           6. Exit         |"<<endl;
    cout<<setw(34)<<"+---------------------------+"<<setw(56)<<"+---------------------------+"<<endl;
    resetcolor();
        cout<<"\nEnter Your Choice: ";
        choice=utility::GetNumberFromUser(15);
        cout<<"You Have selected "<<choice<<endl;

        switch (choice) 
        {
            case 1: 
            system("cls");
            BookMenu(); 
            system("cls");
            break;
            case 2:
            system("cls");
            MemberMenu();
            system("cls");
            break;
             case 3:
             system("cls");
            LibrarianMenu();
            system("cls");
            break;
            case 4: 
            system("cls");
            TransactionMenu();
            system("cls");
            break;
            case 5:
            system("cls");
            FineMenu();
            system("cls");
            break;
            case 6:
             cout<<"Exiting Program..."<<endl;
             LiCollection.WriteDataToFile();
             Collectionn.WriteDataToFile();
             collection.WriteDataToFile();
             finee.WriteDataToFile();
             issue.WriteDataToFile();
             Copy.WriteDataToFile();
             break;
            default: cout<<"Invalid Choice! Try again."<<endl;
        }
    }} while (choice != 6);

}

//Menu for Member 

void MemberMainMenu(int memberId)
 {
  int choice;
  do {
  setcolor(36);
  cout << "\n********** Member Dashboard **********" << endl;
  cout << "1. View All Books" << endl;
  cout << "2. Search Book by ID" << endl;
  cout << "3. View Book Copies" << endl;
  cout << "4. Return a Book" << endl;
  cout << "5. View My Transactions" << endl;
  cout << "6. View My Fines" << endl; 
  cout << "7. Logout" << endl;
  cout << "\nEnter your choice: ";
 choice = utility::GetNumberFromUser(23);
 resetcolor();
 switch (choice) 
{
case 1:
 system("cls");
 collection.DisplayBOOk();
break;
case 2: 
{
system("cls");
 int bookId;
cout << "Enter Book ID to search: ";
bookId = utility::GetNumberFromUser(10);
collection.FindBook(bookId);
break;
 }
case 3:
system("cls");
Copy.DisplayBOOks();
break;


 case 4: 
 {
system("cls");
lib.Ibooks = issue.Ibooks; 
int transId;
cout << "Enter your transaction ID to return book: ";
 transId = utility::GetNumberFromUser(11);
lib.returnBook(transId);
break;
 }

case 5:
system("cls");
issue.DisplayByMemberId(memberId);
break;

case 6:
 system("cls");
finee.DisplayByMemberId(memberId);
break;

case 7:
return;

default:
cout << "Invalid choice. Try again." << endl;
 }
    } while (choice != 7);
}

//**BOOk Menu Function<submenu> ***
void BookCopyMangment_Menu();
void BookMenu() 
{
    Book b1;
    int Choice;
    do {
        setcolor(36);
        cout<<"\n********** Book Menu **********"<<endl;
        cout<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<endl;
        cout<<"2. Delete book"<<endl;
        cout<<endl;
        cout<<"3. view Book"<<endl;
        cout<<endl;
        cout<<"4. Update Book"<<endl;
        cout<<endl;
        cout<<"5. Search Book"<<endl;
        cout<<endl;
        cout<<"6. Manage BookCopies"<<endl;
        cout<<endl;
        cout<<"7. Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice: "<<endl;
         Choice=utility::GetNumberFromUser(11);
        resetcolor();
        int ID;
        switch (Choice)
         {
            case 1: 
            {
            system("cls");
            b1.addBook(collection); 
            system("cls");
            }
            break;

            case 2: 
        {
            system("cls");
            cout<<"Entre ID of Book: ";
            ID=utility::GetNumberFromUser(11);
            collection.RemoveBook(ID);
        }
             break;

            case 3:
            {
            system("cls");
            collection.DisplayBOOk();
            system("clear");
            }
             break;

            case 4:
            {
            system("cls");
            cout<<"Entre ID of Book: ";
            ID=utility::GetNumberFromUser(11);
            collection.UpdateBOOk(ID);
            }
            break;

            case 5:
            {
            system("cls"); 
            cout<<"Entre a Id to search Book: ";
            ID=utility::GetNumberFromUser(11);
            collection.FindBook(ID);
            }
            break;

            case 6:
            {
            system("cls");
            BookCopyMangment_Menu();
            system("cls");
            }
            break;

            case 7:         
            return;
            default: cout<<"Invalid Choice. Try again."<<endl;
        }
    } while (Choice != 7);
}

//BookCopy Mangment
void BookCopyMangment_Menu()
{
    BookCopies C1;
    int Choice;
    do {
        
        setcolor(37);
        cout<<"\n********** Book Menu **********"<<endl;
        cout<<endl;
        cout<<"1. Add BookItem"<<endl;
        cout<<endl;
        cout<<"2. Remove bookItem"<<endl;
        cout<<endl;
        cout<<"3. view BookItems"<<endl;
        cout<<endl;
        cout<<"4. Update BookItem"<<endl;
        cout<<endl;
        cout<<"5. Search BookItem"<<endl;
        cout<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice: "<<endl;
        Choice=utility::GetNumberFromUser(11);
        

        switch(Choice)
        {
            case 1:
            {
            system("cls");
            C1.AddCopies(Copy,collection);
            break;
            }
            case 2:
            {
                system("cls");
                string CID;
                cout<<"Entre BookCopy Id:   ";
                cin.ignore();
                getline(cin,CID);
                Copy.remove(CID);
                break;
            }

            case 3:
          {
            system("cls");
            Copy.DisplayBOOks();
            break;
           }
        
            case 4:
            {
                system("cls");
               string CID;
               cout<<"Entre BookCopy Id:   ";
               CID=utility::GetStringFromUser(30);
               Copy.Updatecopy(CID);
               break;
            }

           case 5:
           {
            system("cls");
            string Id;
            cout<<"Entre BookCopyId to search: ";
            Id=utility::GetStringFromUser(20);
            BookCopies* ptrC=Copy.GetBookCopy(Id);
            if(ptrC!=nullptr)
            {
                ptrC->Display();
            }
            else
            {
                cout<<"Not Found ,Invalid Id"<<endl;
            }
            break;
           }
            case 6:
            return;
            break;
            default:
            cout<<"Invalid Input!"<<endl;
        }

    }while(Choice!=6);
    resetcolor();
}

//**Librarian Menu Function<submenu> ***
void LibrarianMenu() 
{
    Librarian l1;
    int Id;
    int Choice;
    do {
        setcolor(36);
        cout<<"\n********** Librarian Menu **********"<<endl;
        cout<<endl;
        cout<<"1.  Add Librarian"<<endl;
        cout<<endl;
        cout<<"2. Remove Librarian "<<endl;
        cout<<endl;
        cout<<"3. View Librarian details"<<endl;
        cout<<endl;
        cout<<"4. Update Librarian Data"<<endl;
        cout<<endl;
        cout<<"5. Search Librarian Data"<<endl;
        cout<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice: "<<endl;
        Choice=utility::GetNumberFromUser(11);
        resetcolor();
        switch (Choice)
         {
            case 1: 
            system("cls");
            l1.addLibrarian(LiCollection); 
            break;
            case 2: 
            system("cls");
            cout<<"Entre Librarian ID:  ";
            cin>>Id;
            cout<<endl;
            LiCollection.RemoveLibrarian(Id);
             break;
            case 3:
            system("cls");
            LiCollection.DisplayCOLLECTION();
             break;
            case 4:
            system("cls");
            cout<<"Entre Librarian ID:  ";
            cin>>Id;
            cout<<endl;
            LiCollection.UpdateLibrarian(Id);
            break;
            case 5: 
            system("cls");
            cout<<"Entre Librarian ID:  ";
            cin>>Id;
            cout<<endl;
            LiCollection.FindBy_Id(Id);
            break;
            case 6:
            return;
            default: cout<<"Invalid Choice. Try again."<<endl;
        }
    } while (Choice != 6);
}

//**Member Menu Function<submenu> ***
void MemberMenu() 
{
    Member m1;
    int  Id;
    int Choice;
    do {
        setcolor(36);
        cout<<"\n********** Member Menu **********"<<endl;
        cout<<endl;
        cout<<"1.  Add Member"<<endl;
        cout<<endl;
        cout<<"2. Remove Member "<<endl;
        cout<<endl;
        cout<<"3. View Member details"<<endl;
        cout<<endl;
        cout<<"4. Update Member Data"<<endl;
        cout<<endl;
        cout<<"5. Search Member Data"<<endl;
        cout<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice: "<<endl;
         Choice=utility::GetNumberFromUser(11);
        resetcolor();
        switch (Choice)
         {
            case 1:
            system("cls"); 
            m1.addMember(Collectionn);
            break;
            case 2: 
            system("cls");
            cout<<"Entre Member ID to Remove Member: ";
            Id=utility::GetNumberFromUser(11);
            cout<<endl;
            Collectionn.RemoveMember(Id);
             break;
            case 3:
            system("cls");
            Collectionn.DisplayCollection();
             break;
            case 4:
            system("cls");
            Collectionn.UpdateMember(Id);
            break;
            case 5: 
            system("cls");
            cout<<"Entre Member ID to search Member: ";
            Id=utility::GetNumberFromUser(11);
            cout<<endl;
            Collectionn.FindBy_Id(Id);
            break;
            case 6:
            return;
            default: cout<<"Invalid Choice. Try again."<<endl;
        }
    } while (Choice != 6);
} 

//Transaction Menu
void TransactionMenu()
{ 
    IssueBook t1;
        int Choice;
        do {
            setcolor(33);
            cout<<"\n********** Transaction Menu **********"<<endl;
            cout<<endl;
            cout<<"1.  Add IssueBook Data"<<endl;
            cout<<endl;
            cout<<"2. Delete Trasaction Data "<<endl;
            cout<<endl;
            cout<<"3. View  details"<<endl;
            cout<<endl;
            cout<<"4. Update Transaction Data"<<endl;
            cout<<endl;
            cout<<"5. Search Transaction"<<endl;
            cout<<endl;
            cout<<"6. Return Book"<<endl;
            cout<<endl;
            cout<<"7. Exit"<<endl;
            cout<<endl;
            cout<<"Enter Your Choice: "<<endl;
            Choice=utility::GetNumberFromUser(11);
            resetcolor();
            switch (Choice)
             {
                case 1:
                { 
                system("cls");
                t1.addIssueBook_data(issue,Copy,Collectionn,LiCollection); 
                break;
                }

                case 2: 
                {
                system("cls");
                int id;
                cout<<"Entre Transaction Id: ";
                id=utility::GetNumberFromUser(11);
                issue.RemoveTransaction(id);
                break;
                }
                
        
                case 3:
                system("cls");
                issue.Display();
                 break;
                case 4:
                {
                system("cls");
                int id;
                cout<<"Entre Transaction Id: ";
                id=utility::GetNumberFromUser(11);
                issue.Update(id);
                break;
                }
                case 5: 
                {
                  system("cls");
                  int ID;
                  cout<<"Entre Transaction Id: ";
                  ID=utility::GetNumberFromUser(11);
                  issue.Find(ID);
                  break;
                }
                case 6:
                {
                   lib.Ibooks = issue.Ibooks;
                    int ID;
                    cout<<"Entre Transaction Id: ";
                    ID=utility::GetNumberFromUser(11);
                    lib.returnBook(ID);
                    break;
                }
                case 7:
                return;
                default: cout<<"Invalid Choice. Try again."<<endl;
            }
        } while (Choice != 6);
    }  

    
void loginMenu() 
{
    setcolor(36);
    while (true) {
        int choice;
        cout << "-----------------LOGIN-MENU------------\n\n";
        cout << "---------------\n";
        cout << "|1. Librarian  |" << endl;
        cout << "---------------\n";
        cout << endl;
        cout << "---------------\n";
        cout << "|2. Member     |\n";
        cout << "---------------\n" << endl;
        cout << "Enter user type: ";
        choice = utility::GetNumberFromUser(5);

        int action;
        cout << "\n1. Register\n\n2. Login\n\nEnter action: ";
        action = utility::GetNumberFromUser(12);

        bool success = false;
        if (choice == 1) {
            if (action == 1) {
                LiCollection.registerUser();
                success = true;
            } else if (action == 2) {
                success = LiCollection.loginUser();
            } else {
                cout << "Invalid action!\n";
            }
        } else if (choice == 2) {
            if (action == 1) {
                Collectionn.registerUser();
                success = true;
            } else if (action == 2) {
                success = Collectionn.loginUser();
            } else {
                cout << "Invalid action!\n";
            }
        } else {
            cout << "Invalid user type!\n";
        }
        if (success) break; // Only exit loginMenu if registration or login is successful
    }
    resetcolor();
}
    
 //FineMenu   
    void FineMenu() 
{
    fine f;
    int Choice;
    do {
        setcolor(36);
        cout<<"\n********** Fine Menu **********"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"1. Delete Fine Data"<<endl;
        cout<<endl;
        cout<<"2. view Fine Data"<<endl;
        cout<<endl;
        cout<<"3. Update Fine Data"<<endl;
        cout<<endl;
        cout<<"4. Search Fine Data"<<endl;
        cout<<endl;
        cout<<"5. Check OverDues fine(daily)"<<endl;
        cout<<endl;
        cout<<"6. PayFine"<<endl;
        cout<<endl;
        cout<<"7.Exit"<<endl;
        cout<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin >> Choice;
        resetcolor();
        switch (Choice)
         {
            
            case 1: 
        {
            system("cls");
            int id;
            cout<<"Entre Id to move:  ";
            id=utility::GetNumberFromUser(11);
            finee.RemoveFine(id);
             finee.WriteDataToFile();
            break;

        }
            case 2:
            {
            system("cls");
          finee.Display();
            break;
            }
            case 3:
            {
                system("cls");
                int id;
                cout<<"Entre Id to move:  ";
                id=utility::GetNumberFromUser(20);
              finee.Update(id);
               finee.WriteDataToFile();
            break;
            }
            case 4: 
            {
                system("cls");
                int id;
                cout<<"Entre Id to move:  ";
                id=utility::GetNumberFromUser(20);
                 finee.GetFine(id);
                  finee.WriteDataToFile();
                 break;
            }
            
            break;
            case 5:
            {
                system("cls");
             lib.dailyOverdueCheck();
             finee.fineList=lib.fines;
              finee.WriteDataToFile();
            }
            break;
            case 6: 
            {
    system("cls");

    // Show list of unpaid fines
    bool hasUnpaid = false;
    cout << "Unpaid Fines:\n";
    for (auto& f : finee.fineList)
    {
        if (!f.isPaid)
        {
            f.display();
            hasUnpaid = true;
        }
    }

    if (!hasUnpaid) 
    {
        cout << "There are no unpaid fines.\n";
        break;
    }
    int tid;
    cout << "\nEnter Transaction ID to pay fine: ";
     tid=utility::GetNumberFromUser(20);

    fine* f = finee.GetFine(tid);
    if (f)
    {
        f->PayFine();
        finee.WriteDataToFile();
    }
    else
        cout << "No fine found for this Transaction ID.\n";
    
    break;

            }            
            case 7:
            finee.WriteDataToFile();
            return;
            default: cout<<"Invalid Choice. Try again."<<endl;
        }
    } while (Choice != 7);
}

