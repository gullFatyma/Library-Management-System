#include "IssueBook.h"
#include "Member.h"
#include "Fine.h"
#pragma once
// #include"implementation.cpp"
int IssueBook::getTid()
{
  return IssueBookId;
}

// Seter Function For IssueBookId
void IssueBook::setIssueBookID(int TrId)
{
  if (TrId > 0)
  {
    IssueBookId = TrId;
  }
  else
    cout << "Invalid ID!!!" << endl;
}

// Default Transacton Constructor
IssueBook::IssueBook()
    : IssueBookId(0), borrowID(new Member()), issuedby(new Librarian()),
      IssueDate{0, 0, 0}, Actual_Returndate{0, 0, 0}, ReturnDate{0, 0, 0}, isReturned('n')
{
}

Member* IssueBook:: getBorrower() 
 {
    return borrowID;
}
// Parametrized IssueBook constructor
IssueBook::IssueBook(int TrId, Librarian *L, Member *bId, BookCopies Borrowed, Date ID, Date AD, Date ReturnD, char isReturn)
{
  IssueBookId = TrId;
  issuedby = L;
  borrowID = bId;
  Bookborrowed = Borrowed;
  IssueDate = ID;
  Actual_Returndate = AD;
  ReturnDate = ReturnD;
  isReturned = isReturn;
}

// copy Constructor
IssueBook::IssueBook(const IssueBook &t)
{
  IssueBookId = t.IssueBookId;
  borrowID = new Member(*t.borrowID);
  issuedby = new Librarian(*t.issuedby);
  Bookborrowed = t.Bookborrowed;
  IssueDate = t.IssueDate;
  Actual_Returndate = t.Actual_Returndate;
  ReturnDate = t.ReturnDate;
  isReturned = t.isReturned;
}

// IssueBook add function
void IssueBook::addIssueBook_data(IssueBook_collection &issue, BookCopies_Collection &Copy, MemberCollection &Collectionn, LibrarianCollection &LiCollection)
{
  int m, libr;
  IssueBook I;
  cout << "***Entre Details of IssueBook***" << endl;
  cout << "____________________________________________" << endl;
  cout << "IssueBook Id: ";
  cin >> IssueBookId;
  I.setIssueBookID(IssueBookId);

  cout << "Borrower's ID:  ";
  cin >> m;
  cin.ignore();
  bool found = false;
  for (Member &mem : Collectionn.Members)
  {
    if (mem.getId() == m)
    {
      I.borrowID = new Member(mem);
      found = true;
      break;
    }
  }
  if (!found)
  {
    cout << "Member ID does not exist !" << endl;
    return;
  }

  cout << "Librarian ID: ";
  cin >> libr;
  cin.ignore();
  bool Found = false;
  for (Librarian &lib : LiCollection.LibrarianCol)
  {
    if (lib.getId() == libr)
    {
      I.issuedby = new Librarian(lib);
      Found = true;
      break;
    }
  }
  if (!Found)
  {
    cout << "Librarian ID does not exist !" << endl;
    return;
  }

  string CopyId;
  cout << "BookCopy ID: ";
  getline(cin, CopyId);
  bool foUnd = false;
  for (BookCopies &B : Copy.copyCol)
  {
    if (B.CopyID == CopyId)
    {
      I.Bookborrowed = B;
      foUnd = true;
      break;
    }
  }
  if (!foUnd)
  {
    cout << "BookID does not exist!...." << endl;
    return;
  }
  cout << "Issue Date[dd mm yyyy]: ";
  int dd, mm, yyyy;
  cin >> dd >> mm >> yyyy;
  I.IssueDate.day = dd;
  I.IssueDate.month = mm;
  I.IssueDate.year = yyyy;

  cout << "Return Date: ";
  cin >> dd >> mm >> yyyy;
  I.ReturnDate.day = dd;
  I.ReturnDate.month = mm;
  I.ReturnDate.year = yyyy;

  cout << "Actual Return Date: ";
  cin >> dd >> mm >> yyyy;
  I.Actual_Returndate.day = dd;
  I.Actual_Returndate.month = mm;
  I.Actual_Returndate.year = yyyy;
  cout << "IsReturend[y/n]: ";
  cin >> I.isReturned;
  cin.ignore();
  issue.ADDbooks_details(I);
}

// Display Function
void IssueBook::display()
{

  cout << "Details of IssueBook" << endl;
  cout << "____________________________________________" << endl;
  cout << "IssueBook Id: " << getTid() << endl;
  cout << endl;
  cout << "Borrower's ID:  " << borrowID->getId() << endl;
  cout << endl;
  cout << "Librarian ID: " << issuedby->getId() << endl;
  cout << endl;
  cout << "Book ID: " << Bookborrowed.CopyID << endl;
  cout << endl;
  cout << "Issue Date: " << IssueDate.day << "/" << IssueDate.month << "/" << IssueDate.year << endl;
  cout << endl;
  cout << "Return Date: " << ReturnDate.day << "/" << ReturnDate.month << "/" << ReturnDate.year;
  cout << endl;
  cout << "Actual Return Date: " << Actual_Returndate.day << "/" << Actual_Returndate.month << "/" << Actual_Returndate.year << endl;
  cout << endl;
  cout << "IsReturned: " << isReturned << endl;
  cout << endl;
  cout << "------------------------------------------------------------" << endl;
}

void IssueBook_collection::ADDbooks_details(IssueBook &I)
{
  Ibooks.push_back(I);
}

void IssueBook_collection::Display()
{
  for (IssueBook &I : Ibooks)
  {
    I.display();
  }
}

IssueBook *IssueBook_collection::GetIssueBook(int Id)
{
  for (int i = 0; i < Ibooks.size(); i++)
  {
    if (Ibooks[i].getTid() == Id)
    {
      return &Ibooks[i];
    }
  }
  return nullptr;
}

void IssueBook_collection::Update(int Id)
{
  IssueBook *Book = GetIssueBook(Id);
  if (Book == nullptr)
  {
    cout << "Not Found!" << endl;
  }
  int choiCe;
  cout << "What do you want to update ?" << endl;
  cout << "1. Issue Date\n";
  cout << "2. Return Date\n";
  cout << "3. Actual Date\n";
  cout << "4. Avalibiltiy Status\n";
  cout << "Entre your choice: ";
  cin >> choiCe;
  cin.ignore();

  switch (choiCe)
  {
  case 1:
  {
    Date IssueD;
    cout << " Entre new IssueDate: ";
    cin >> IssueD.day >> IssueD.month >> IssueD.year;
    Book->IssueDate = IssueD;
    break;
  }

  case 2:
  {
    Date ReturnD;
    cout << " Entre new IssueDate: ";
    cin >> ReturnD.day >> ReturnD.month >> ReturnD.year;
    Book->ReturnDate = ReturnD;
    break;
  }

  case 3:
  {
    Date ActualD;
    cout << " Entre new IssueDate: ";
    cin >> ActualD.day >> ActualD.month >> ActualD.year;
    Book->Actual_Returndate = ActualD;
    break;
  }

  case 4:
  {
    char status;
    cout << " Entre new Availibilty Status[y/n]: ";
    cin >> status;
    Book->isReturned = status;
    break;
  }
  default:
    cout << " Invalid Id" << endl;
  }
  cout << "Data updated Successfully! " << endl;
}

void IssueBook_collection::RemoveTransaction(int ID)
{
  for (int i = 0; i < Ibooks.size(); i++)
  {
    if (Ibooks[i].getTid() == ID)
    {
      Ibooks.erase(Ibooks.begin() + i);
      cout << " Transaction removed successfully! " << endl;
      return;
    }
  }
  cout << " Book with Id " << ID << " not found" << endl;
}

void IssueBook_collection::Find(int id)
{
  for (int i = 0; i < Ibooks.size(); i++)
  {
    if (Ibooks[i].getTid() == id)
    {
      Ibooks[i].display();
      return;
    }
  }
  cout << "Book with ID " << id << " Not found!" << endl;
}


void IssueBook_collection::DisplayByMemberId(int memberId)
{
    cout << "\n--- Issued Books for Member ID: " << memberId << " ---\n";
    bool found = false;
    for (auto& issue : Ibooks)
    {
        if (issue.getBorrower() && issue.getBorrower()->getId() == memberId)
        {
            issue.display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No issued books found for this member ID.\n";
    }
}

// gETsTRING
string IssueBook::GetString()
{
  return to_string(IssueBookId) + "," + to_string(borrowID->getId()) + "," +
  to_string(issuedby->getId()) + "," + Bookborrowed.CopyID + "," +
  to_string(IssueDate.day) + "-" + to_string(IssueDate.month) + "-" + to_string(IssueDate.year) + "," +
  to_string(ReturnDate.day) + "-" + to_string(ReturnDate.month) + "-" + to_string(ReturnDate.year) + "," +
  to_string(Actual_Returndate.day) + "-" + to_string(Actual_Returndate.month) + "-" +
  to_string(Actual_Returndate.year) + "," + isReturned;
}

// Read string Functions
void IssueBook::ReadString(const string &line, MemberCollection &members, LibrarianCollection &librarians, BookCopies_Collection &copies)
{
  string temp = line;
  size_t pos;

  pos = temp.find(',');
  IssueBookId = stoi(temp.substr(0, pos));
  temp.erase(0, pos + 1);

  pos = temp.find(',');
  int memberId = stoi(temp.substr(0, pos));
  temp.erase(0, pos + 1);

  borrowID = nullptr;
  for (Member &m : members.Members)
  {
  if (m.getId() == memberId)
  {
  borrowID = new Member(m);
  break;
  }
  }

  pos = temp.find(',');
  int librarianId = stoi(temp.substr(0, pos));
  temp.erase(0, pos + 1);
  issuedby = nullptr;
  for (Librarian &l : librarians.LibrarianCol)
  {
  if (l.getId() == librarianId)
  {
  issuedby = new Librarian(l);
  break;
    }
  }

  pos = temp.find(',');
  string copyId = temp.substr(0, pos);
  temp.erase(0, pos + 1);
  Bookborrowed = BookCopies(); 
  for (BookCopies &b : copies.copyCol)
  {
  if (b.CopyID == copyId)
  {
  Bookborrowed = b;
  break;
  }
  }

  pos = temp.find(',');
  string dateStr = temp.substr(0, pos);
  temp.erase(0, pos + 1);

  size_t dash1 = dateStr.find('-');
  size_t dash2 = dateStr.find('-', dash1 + 1);
  IssueDate.day = stoi(dateStr.substr(0, dash1));
  IssueDate.month = stoi(dateStr.substr(dash1 + 1, dash2 - dash1 - 1));
  IssueDate.year = stoi(dateStr.substr(dash2 + 1));

  pos = temp.find(',');
  dateStr = temp.substr(0, pos);
  temp.erase(0, pos + 1);

  dash1 = dateStr.find('-');
  dash2 = dateStr.find('-', dash1 + 1);
  ReturnDate.day = stoi(dateStr.substr(0, dash1));
  ReturnDate.month = stoi(dateStr.substr(dash1 + 1, dash2 - dash1 - 1));
  ReturnDate.year = stoi(dateStr.substr(dash2 + 1));

  pos = temp.find(',');
  dateStr = temp.substr(0, pos);
  temp.erase(0, pos + 1);

  dash1 = dateStr.find('-');
  dash2 = dateStr.find('-', dash1 + 1);
  Actual_Returndate.day = stoi(dateStr.substr(0, dash1));
  Actual_Returndate.month = stoi(dateStr.substr(dash1 + 1, dash2 - dash1 - 1));
  Actual_Returndate.year = stoi(dateStr.substr(dash2 + 1));

  if (!temp.empty())
    isReturned = temp[0];
  else
    isReturned = 'n';
}

//file saving
void IssueBook_collection::WriteDataToFile()
{
ofstream ofs("IssueBook.csv", ios::out);
if (!ofs)
{
cout << "Error opening IssueBook.csv for writing." << endl;
return;
 }
for (auto& issue : Ibooks)
{
 ofs << issue.GetString() << "\n";
}
ofs.close();
}

//file reading
void IssueBook_collection::ReadDataFromFile(MemberCollection& members, LibrarianCollection& librarians, BookCopies_Collection& copies)
{
ifstream ifs("IssueBook.csv");
if (!ifs)
{
cout << "IssueBook.csv file not found." << endl;
return;
}
Ibooks.clear();
string line;
while (getline(ifs, line))
{
if (line.length() > 4)
{
IssueBook issue;
issue.ReadString(line, members, librarians, copies);
Ibooks.push_back(issue);
}
}
ifs.close();
}

IssueBook::~IssueBook()
{
  delete borrowID;
  delete issuedby;
}