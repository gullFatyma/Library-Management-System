#include "Member.h"
#include "utility.cpp"
#include "Implementation.cpp"

// Geter Function for MemberId
int Member::getId()
{
   return memberID;
}

// seter Function for MemberId
void Member::SetId(int mem_ID)
{
   if (mem_ID > 0)
      memberID = mem_ID;
   else
      cout << "Invalid ID.............." << endl;
}

// Default Member constructor
Member::Member() : Person(), Date()
{
   memberID = 0;
   DateOf_joining = {0, 0, 0};
}

//UserType Function
userType Member::getuserType()
{
   return userType::MEMBER;
}

// Parametrized Member constructor
Member::Member(int id, Date DOF, string Name, string Email, string contacT) : Person(Name, Email, contacT)
{
   memberID = id;
   DateOf_joining = DOF;
}

// Copy Constructor()
Member::Member(const Member &m) : Person(m)
{
   memberID = m.memberID;
   DateOf_joining = m.DateOf_joining;
}

// Add Function for Member
void Member::addMember(MemberCollection &Collectionn)
{
   Member Mem;
   cout << "Entre details of Member: " << endl;
   cout << "---------------------------------" << endl;
   cout << "Member Id:  ";
   cin >> Mem.memberID;
   SetId(Mem.memberID);
   cout << "Date of Joining(dd\\mm\\yy): ";
   cin >> Mem.DateOf_joining.day >> Mem.DateOf_joining.month >> Mem.DateOf_joining.year;
   cin.ignore();
   cout << "Name: ";
   getline(cin, Mem.name);
   cout << "Email: ";
   getline(cin, Mem.email);
   string co;
   cout << "Contact: ";
   getline(cin, co);
   Mem.setContact(co);
   cout << "Data stored!!" << endl;
   cout << "---------------------------------------------" << endl;
   Collectionn.AddMember(Mem);
}

// display Function
void Member::displayMember()
{
   cout << "Details of Member: " << endl;
   cout << "---------------------------------" << endl;
   cout << endl;
   cout << "Member Id: " << getId() << endl;
   cout << endl;
   cout << "Date of Joining(dd\\mm\\yy): "
        << DateOf_joining.day << "/ " << DateOf_joining.month << " / " << DateOf_joining.year << endl;
   cout << endl;
   cout << "Name: " << name << endl;
   cout << endl;
   cout << "Email: " << email << endl;
   cout << endl;
   cout << "Contact: " << getContact() << endl;
   cout << endl;
   cout << "---------------------------------------------" << endl;
}

// Add Function of Collction
void MemberCollection::AddMember(Member &Mem)
{
   Members.push_back(Mem);
}

// Display Function of Collection
void MemberCollection::DisplayCollection()
{
   cout << "Total Members: " << Members.size() << endl;
   for (Member &M : Members)
   {
      M.displayMember();
   }
}

// Find Member Function
void MemberCollection::FindBy_Id(int ID)
{
   for (int i = 0; i < Members.size(); i++)
   {
      if (Members[i].getId() == ID)
      {
         Members[i].displayMember();
         return;
      }
   }
   cout << "Member with ID " << ID << " Not found!" << endl;
}

// Get FUnction....
Member *MemberCollection::GetMember(int Id)
{
   for (int i = 0; i < Members.size(); i++)
   {
      if (Members[i].getId() == Id)
         ;
      {
         return &Members[i];
      }
   }
   return NULL;
}

// Update Member Function
void MemberCollection::UpdateMember(int Id)
{
   Member *member = GetMember(Id);
   if (member == NULL)
   {
      cout << " Book not Found!" << endl;
   }
   int choice;
   cout << "What do you want to update ?" << endl;
   cout << "1. Date of Joining\n";
   cout << "2. Name\n";
   cout << "3. Email\n";
   cout << "4. Contact\n";
   cout << "Entre your choice: ";
   cin >> choice;
   cin.ignore();

   string CONTACT;
   switch (choice)
   {
   case 1:
   {
      Date DOJ;
      cout << " Entre new Title: ";
      cin >> DOJ.day >> DOJ.month >> DOJ.year;
      member->DateOf_joining = DOJ;
      break;
   }

   case 2:
   {
      string Name;
      cout << " Entre new  Name: ";
      getline(cin, Name);
      member->name = Name;
      break;
   }

   case 3:
   {
      string Email;
      cout << " Entre new Email: ";
      getline(cin, Email);
      member->email = Email;
      break;
   }

   case 4:
   {
      cout << " Entre new Contact: ";
      getline(cin, CONTACT);
      member->setContact(CONTACT);
      break;
   default:
      cout << " Invalid Id" << endl;
   }
   }
   cout << "Data updated Successfully! " << endl;
}

// Remove Member by ID
void MemberCollection::RemoveMember(int Id)
{
   for (int i = 0; i < Members.size(); i++)
   {
      if (Members[i].getId() == Id)
      {
         Members.erase(Members.begin() + i);
         cout << "Member Removed Successfully! \n";
         return;
      }
   }
   cout << "Member with Id " << Id << " Not found!" << endl;
}

void MemberCollection::PostRegistrationMenu() 
{
int choice;
while (true) 
{
 cout << "What would you like to do next?\n";
cout << "1. Login\n";
cout << "2. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

if (cin.fail()) 
{
cin.clear();                // clear error flag
cin.ignore(1000, '\n');     // discard invalid input
cout << "Invalid input. Try again.\n";
continue;                   // restart loop
 }

if (choice == 1)
 {
   loginUser();  // call login function
   break;    // break loop after login
}

else if (choice == 2)
{
    cout << "Exiting program. Goodbye!\n";
    return;
}
else 
{
cout << "Invalid choice. Try again.\n";
 }
}
}

//Register Member Function
void MemberCollection::registerUser()
{
   setcolor(32);
   Member m;
   cout << "Registering Member:\n";
   m.addMember(Collectionn);
  // Members.push_back(m);
   cout << "Member Registered Successfully!\n";
   int choice;
   cout<<"1.Login\n\n2.Exit\n\nEnter choice: ";
   cin>>choice;
   if(choice==1)
   {
      loginUser();
   }
   else if(choice==2)
   {
      cout<<"Exiting Program.Goodbye!\n";
      return;
   }
   else
      cout<<"Invalid input....Try again\n";
   PostRegistrationMenu();
   resetcolor();
}

//Login Member FUnction
bool MemberCollection::loginUser()
{
   int ID;
   string email;
   cout << "Enter Id: ";
   ID = utility::GetNumberFromUser(20);
   cout << "Enter Email: ";
   email = utility::GetStringFromUser(50);

   for (auto &m : Members)
   {
      if (m.getId()== ID && m.email == email)
      {
         cout << "Member Login Successful!\n";
         MemberMainMenu(ID);
         return true;
      }
   }
   cout << "Invalid Member credentials.\n";
   return false;
}

// Get string Function
string Member::GetString()
{
   return to_string(memberID) + "," + name + "," + email + "," + getContact() + "," +
          to_string(DateOf_joining.day) + "/" + to_string(DateOf_joining.month) + "/" + to_string(DateOf_joining.year);
}


//ReadString Function
void Member::ReadString(string line)
{
   size_t pos = 0;
   string token;

   // Member ID
   pos = line.find(',');
   token = line.substr(0, pos);
   memberID = stoi(token);
   line.erase(0, pos + 1);

   // Name
   pos = line.find(',');
   token = line.substr(0, pos);
   name = token;
   line.erase(0, pos + 1);

   // Email
   pos = line.find(',');
   token = line.substr(0, pos);
   email = token;
   line.erase(0, pos + 1);

   // Contact
   pos = line.find(',');
   token = line.substr(0, pos);
   setContact(token);
   line.erase(0, pos + 1);

   // Date of Joining: format is dd/mm/yyyy
   pos = line.find('/');
   token = line.substr(0, pos);
   DateOf_joining.day = stoi(token);
   line.erase(0, pos + 1);

   pos = line.find('/');
   token = line.substr(0, pos);
   DateOf_joining.month = stoi(token);
   line.erase(0, pos + 1);

   DateOf_joining.year = stoi(line); // Remaining string
}


//file saving...
void MemberCollection::WriteDataToFile()
{
   ofstream ofs("Member.csv", ios::app);
   if (ofs.is_open())
   {
      for (auto &m : Members)
      {
         string str = m.GetString();
         ofs << str << endl;
      }
      ofs.close();
   }
   else
   {
      cout << "Error opening file for writing." << endl;
   }
}

//Reading from file.....
void MemberCollection::ReadDataFromFile()
{
   ifstream reader("Member.csv");
   if (!reader)
   {
      cout << "File not found." << endl;
      return;
   }

   string line;
   while (getline(reader, line))
   {
      if (line.length() > 4)
      {
         Member m;
         m.ReadString(line);
         // Check for invalid contact (e.g., "-0", "empty", or empty string)
         std::string contact = m.getContact();
         if (contact == "-0" || contact == "empty" || contact.empty()) {
            cout << "Invalid contact number found in file, skipping entry." << endl;
            continue; // Skip this member
         }
         Members.push_back(m);
      }
   }
   reader.close();
}
