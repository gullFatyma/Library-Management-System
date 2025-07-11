#include"Book.h"
#pragma once
//---Book Class Functions--
//Geter Function for BookId
int Book::GetId()
     { 
        return bookID; 
    }

 //Seter Function for BookId   
    void Book:: SetId(int book_ID)
     {
        if (book_ID > 0)
         {
            bookID = book_ID;
        } 
        else 
        {
            cout<<"Invalid ID"<<endl;
        }
    }

//Book default Constructor
    Book::Book() 
    {
        bookID= 0;
        title = "Empty";
        author = "Empty";
        publisher_name="No name";
        totalCopies=-7;

    }
   
    //Book parameterized constructor
    Book::Book(int ID, string t,string pub, string a,int tCopies) 
    {
        bookID = ID;
        title = t;
        author = a;
        publisher_name=pub;
        totalCopies=tCopies;
        }


    //copy constructor
    Book::Book(const Book&b)
    {
        bookID=b.bookID;
        title=b.title;
        author=b.author;
        publisher_name=b.publisher_name;
        totalCopies=b.totalCopies;
    }

    //Book destructor
    
    //Book Add_Function
     void Book::addBook(BookCollection &collection)
     { 
        Book b;
        cout<<"Entre Book Details: "<<endl;
        cout<<"Book ID:           ";
        cin>>b.bookID;
        SetId(b.bookID);
        cin.ignore();
        cout<<"Title:             ";
        getline(cin,b.title);
        cout<<"Aurthor:           ";
        getline(cin,b.author);
        cout<<"Publisher name:    ";
        getline(cin,b.publisher_name);
        cout<<"Total copies:  ";
        cin>>b.totalCopies;
        cin.ignore();
        collection.Addbook(b);
        cout<<"Data Added successfully! "<<endl;
     }

    //Book display Function
    void Book:: displayBook()
    { 
        cout<<"Book Details......\n";
        cout<<"BOOk ID          : "<<GetId()<<endl;
        cout<<"Book Title       : "<<title<<endl;
        cout<<"Book aurthor     : "<<author<<endl;
        cout<<"Publisher Name   : "<<publisher_name<<endl;
        cout<<"Total copies     : "<<totalCopies<<endl;
        cout<<"-----------------------------------------"<<endl;

    }
  void BookCollection::Addbook( Book &b)
  {
     books.push_back(b);
  }

void BookCollection::DisplayBOOk()
{
    cout<<"Total Books "<<books.size()<<endl;
    for(Book &b: books)
    {
     b.displayBook();
    }
}

Book* BookCollection::GetBook(int id)
{
   for(int i=0;i<books.size();i++)
   {
    if(books[i].GetId()==id)
    {
        return &books[i];
    }
   }
   return NULL;
}

void BookCollection::UpdateBOOk(int id)
{
    Book* book=GetBook(id);
    if(book== NULL )
    {
        cout<<" Book not Found!"<<endl;
    }
    int choice;
    cout<<"What do you want to update ?"<<endl;
    cout<<"1. Title\n";
    cout<<"2. Aurthor\n";
    cout<<"3. Publisher\n";
    cout<<"4. Avalibiltiy Status\n";
    cout<<"Entre your choice: ";
    cin>>choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
       string newTitle;
       cout<<" Entre new Title: ";
       getline(cin,newTitle);
       book->title=newTitle;
        break;
    }
    
    case 2:
    { 
       string newAurthor;
       cout<<" Entre new Aurthor's Name: ";
       getline(cin,newAurthor);
       book->author=newAurthor;
        break;
    }
    case 3:
      {
       string newPublisher;
       cout<<" Entre new Publisher's Name: ";
       getline(cin,newPublisher);
       book->publisher_name=newPublisher;
        break;
      }
    case 4:
    {
       int newC;
       cout<<" Entre new Status(y/n): ";
       cin>>newC;
       book->totalCopies=newC;
       break;
       default:
       cout<<" Invalid Id"<<endl;

    }
}
cout<<"Data updated Successfully! "<<endl;
}

void BookCollection::FindBook(int id)
{
    for(int i=0;i<books.size();i++)
    {
        if(books[i].GetId()==id)
        {
        books[i].displayBook();
        return;
        }
    }
    cout<<"Book with ID "<<id<<" Not found!"<<endl;

}

//RemoveBook function
void BookCollection::RemoveBook(int id)
{
    for(int i=0;i<books.size();i++)
    {
        if(books[i].GetId()==id)
        {
            books.erase(books.begin()+ i);
            cout<<" Book removed successfully! "<<endl;
            return;
        }
    }
        cout<<" Book with Id "<<id<<" not found"<<endl;
}

//GetString Function
string Book::GetString()
{
    return to_string(bookID) + "," + title + "," + author + "," + publisher_name + "," 
    + to_string(totalCopies);
}

//Readstring
void Book::ReadString(string line)
{
    size_t pos;
    string token;

    pos = line.find(',');
    token = line.substr(0, pos);
    bookID = stoi(token);
    line.erase(0, pos + 1);

    pos = line.find(',');
    token = line.substr(0, pos);
    title = token;
    line.erase(0, pos + 1);

    pos = line.find(',');
    token = line.substr(0, pos);
    author = token;
    line.erase(0, pos + 1);

    pos = line.find(',');
    token = line.substr(0, pos);
    publisher_name = token;
    line.erase(0, pos + 1);

    totalCopies = stoi(line);  // Remaining part
}

//File saving
void BookCollection::WriteDataToFile()
{
    ofstream ofs("Books.csv", ios::app);
    if(ofs.is_open())
    {
        for (Book &b : books)
        {
            ofs << b.GetString() << endl;
        }
        ofs.close();
    }
}

//file reading
void BookCollection::ReadDataFromFile()
{
    ifstream reader("Books.csv");
    if (!reader)
    {
        cout << "File not found!" << endl;
        return;
    }

    string line;
    while (getline(reader, line))
    {
        if (line.length() > 4)
        {
            Book b;
            b.ReadString(line);
            books.push_back(b);
        }
    }
    reader.close();
}
