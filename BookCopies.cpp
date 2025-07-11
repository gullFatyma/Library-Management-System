#include"BookCopies.h"
//Default Constructor
BookCopies:: BookCopies()
{
  CopyID="0000";
  Location="none";
  availablityStatus='-';
   book=nullptr;

}

// Overloaded constructor
BookCopies::BookCopies(string copyId,string Loc, char Status,Book* bOok)
{
    CopyID=copyId;
  Location=Loc;
  availablityStatus=Status;
   book=bOok;
}

//copy Constructor
 BookCopies :: BookCopies(const BookCopies &bb)
 {
    CopyID=bb.CopyID;
    Location=bb.Location;
    availablityStatus=bb.availablityStatus;
    book=bb.book;
 }

//Add Function
void BookCopies::AddCopies(BookCopies_Collection &Copy,BookCollection &collection)
{
    BookCopies B;
    cout<<"Entre Book Id this Copy relates to: ";
    int Id;
    cin>>Id;
    cin.ignore();
    Book* ptrB=collection.GetBook(Id);
    if(ptrB!=NULL)
    {
      B.book=ptrB;
    }
    else
    {
        cout<<"Book with Id "<<Id <<" not found! "<<endl;
        return;
    }

    cout<<"Entre BookCopy ID:  ";
    getline(cin,B.CopyID);

    cout<<"Entre Books'copy location:  ";
    getline(cin,B.Location);

    cout<<"Entre Availibilty status[y/n]:  ";
    cin>>B.availablityStatus;
    cin.ignore();
    Copy.AddBookCopies(B);

    cout<<"Data added successfully...."<<endl;
}

//Display function of BookCopies
void BookCopies::Display()
{
    cout<<"Book Title:          "<<book->title<<endl;
    cout<<endl;
    cout<<"Book CopyId:      "<<CopyID<<endl;
    cout<<endl;
    cout<<"BookCopy Location:    "<<Location<<endl;
    cout<<endl;
    cout<<"Is available:         "<<availablityStatus<<endl;
    cout<<endl;
    cout<<"-----------------------------------------"<<endl;
}

//Add Function Of Collection
void BookCopies_Collection::AddBookCopies(BookCopies &B)
{
    copyCol.push_back(B);
}

//Display Function Of Collection
void BookCopies_Collection::DisplayBOOks()
{
    for(BookCopies &B: copyCol)
    {
    B.Display();
    }
}

BookCopies* BookCopies_Collection::GetBookCopy(string Id)
{
    for(int i=0; i<copyCol.size();i++)
    {
        if(copyCol[i].CopyID==Id)
        {
            return &copyCol[i];
        }
    }
    return nullptr;
}

void BookCopies_Collection::Updatecopy(string Id)
{
    BookCopies* book=GetBookCopy(Id);
    if(book== NULL )
    {
        cout<<" Book not Found!"<<endl;
    }
    int choice;
    cout<<"What do you want to update ?"<<endl;
    cout<<"1. Book's Location\n";
    cout<<"2. Avalibiltiy Status\n";
    cout<<"Entre your choice: ";
    cin>>choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
       string newLocation;
       cout<<" Entre new Location: ";
       getline(cin,newLocation);
       book->Location=newLocation;
        break;
    }
    
    case 2:
    { 
       char status;
       cout<<" Entre new Availibilty Status[y/n]: ";
       cin>>status;
       book->availablityStatus=status;
        break;
    }      
       default:
       cout<<" Invalid Id"<<endl;

    }
cout<<"Data updated Successfully! "<<endl;
}

void BookCopies_Collection::FindBYID(string idd)
{
    for(int i=0;i<copyCol.size();i++)
    {
        if(copyCol[i].CopyID==idd)
        {
        copyCol[i].Display();
        return;
        }
    }
    cout<<"Book with ID "<<idd<<" Not found!"<<endl;

}

void BookCopies_Collection::remove(string id)
{
    for(int i=0;i<copyCol.size();i++)
    {
        if(copyCol[i].CopyID==id)
        {
            copyCol.erase(copyCol.begin()+ i);
            cout<<" Book removed successfully! "<<endl;
            return;
        }
    }
        cout<<" Book with Id "<<id<<" not found"<<endl;
}

//GetString 
string BookCopies::GetString()
{
    // To avoid null pointer issues
    int bookId = (book != nullptr) ? book->GetId() : -1;

    return CopyID + "," + Location + "," + availablityStatus + "," + to_string(bookId);
}

//file saving
void BookCopies_Collection::WriteDataToFile()
{
    ofstream ofs("BookCopies.csv", ios::app);  // use ios::trunc if you want to overwrite
    if (ofs.is_open())
    {
        for (BookCopies &b : copyCol)
        {
            ofs << b.GetString() << endl;
        }
        ofs.close();
    }
    else
    {
        cout << "Unable to open file for writing!" << endl;
    }
}

//Read from file
void BookCopies_Collection::ReadDataFromFile(BookCollection &books)
{
    ifstream ifs("BookCopies.csv");
    if (!ifs)
    {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    while (getline(ifs, line))
    {
        if (line.length() > 4)
        {
            istringstream ss(line);
            string copyId, location, statusStr, bookIdStr;

            getline(ss, copyId, ',');
            getline(ss, location, ',');
            getline(ss, statusStr, ',');
            getline(ss, bookIdStr, ',');

            int bookId = stoi(bookIdStr);
            Book* ptrBook = books.GetBook(bookId);

            BookCopies b(copyId, location, statusStr[0], ptrBook);
            copyCol.push_back(b);
        }
    }
    ifs.close();
}

