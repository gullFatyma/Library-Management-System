#include"Librarian.h"
#include"Implementation.cpp"
#include"utility.cpp"
int Librarian::getId() 
{
    return librarianId;
}


     //seter Function for LibraianId
    void Librarian::setId(int lib_ID) 
    {
     if (lib_ID > 0) 
     {
            librarianId = lib_ID;
        } 
        else
         {
            cout<<"Invalid ID"<<endl;
        }
    }

    
    userType Librarian:: getuserType()
    {
       return  userType::LIBRARIAN;
    }

     //Default Librarian constructor
     Librarian::Librarian():Person() 
    {
      librarianId = 0;
        role = "empty";
    }

    //Parametrized Librarian constructor
   Librarian:: Librarian(int id, string Name, string Email,string Contact, string Role):Person(Name,Email, Contact)
    {
        librarianId = id;
        role = Role;

    }

    //Copy Constructor
    Librarian::Librarian(const Librarian &l):Person(l)
    {
        librarianId=l.librarianId;
        role=l.role;
    }

    

    //Add function
    void Librarian::addLibrarian(LibrarianCollection &LiCollection)
    {
        Librarian Li;
        cout<<"Entre details of Librarian: "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Librarian Id:  ";
        Li.librarianId=utility::GetNumberFromUser(20);
        Li.setId(Li.librarianId);
        cout<<"Name: ";
        Li.name=utility::GetStringFromUser(100);
        cout<<"Email: ";
        Li.email=utility::GetStringFromUser(100);
        string co;
        cout<<"Contact: ";
        co=utility::GetStringFromUser(11);
        Li.setContact(co);
        cout<<"Role: ";
        Li.role=utility::GetStringFromUser(100);
        LiCollection.AddData(Li);
        cout<<"Data stored!!"<<endl;
        cout<<"---------------------------------------------"<<endl;
        
     }
     
     //Display Librarian
     void Librarian::DisplayL()
    {
        cout<<"Details of Librarian: "<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<endl;
        cout<<"Librarian Id:  "<<getId()<<endl;
        cout<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<endl;
        cout<<"Contact: "<<getContact()<<endl;
        cout<<endl;
        cout<<"Role: "<<role<<endl;
        cout<<endl;
        cout<<"---------------------------------------------"<<endl;
     }
    
     //Add Collection
     void LibrarianCollection::AddData(Librarian &lib)
     {
       // Prevent duplicate librarian by ID
       for (auto& l : LibrarianCol) {
           if (l.getId() == lib.getId()) {
               cout << "Librarian with ID " << lib.getId() << " already exists. Duplicate not added." << endl;
               return;
           }
       }
       LibrarianCol.push_back(lib);
     }

     //Display Collection
     void LibrarianCollection::DisplayCOLLECTION()
     {
        cout<<"Total Librarians: "<<LibrarianCol.size()<<endl;
        for(Librarian & L: LibrarianCol)
        {
            L.DisplayL();
        }
     }

     //Find By Id
     void LibrarianCollection::FindBy_Id(int Id)
     {
        for(int i=0;i<LibrarianCol.size();i++)
        {
            if(LibrarianCol[i].getId()==Id)
            {
                LibrarianCol[i].DisplayL();
                return;
            }
        }
        cout<<"Librarian with ID "<<Id<<" not found!"<<endl;
     }

     //GetId Function
     Librarian* LibrarianCollection::GetLibrarian(int Id)
     {
        for(int i=0;i<LibrarianCol.size();i++)
          {
            if(LibrarianCol[i].getId()==Id)
             {
               return &LibrarianCol[i];
             }
          }
          return NULL;
     }

     //Update Function
     void LibrarianCollection::UpdateLibrarian(int Id)
     {
        Librarian* lib=GetLibrarian(Id);
      if(lib== NULL )
      {
          cout<<" Librarian not Found!"<<endl;
      }
      int choice;
      cout<<"What do you want to update ?"<<endl;
      cout<<"1. Name\n";
      cout<<"2. Email\n";
      cout<<"3. Contact\n";
      cout<<"4. Role\n";
      cout<<"Entre your choice: ";
      choice=utility::GetNumberFromUser(20);
      cin.ignore();
     
      string CONTACT;
      string ROLE;

      switch (choice)
      {
      case 1:
      { 
         string Name;
         cout<<" Entre new  Name: ";
         Name=utility::GetStringFromUser(50);
         lib->name=Name;
          break;
      }

      case 2:
        {
         string Email;
         cout<<" Entre new Email: ";
         Email=utility::GetStringFromUser(100);
         lib->email=Email;
          break;
        }

      case 3:
          {
         cout<<" Entre new Contact: ";
         CONTACT=utility::GetStringFromUser(100);
         lib->setContact(CONTACT);
         break;
          }

       case 4:
       {
        cout<<"Entre new Role: ";
        ROLE=utility::GetStringFromUser(35);
        lib->role=ROLE;
        break; 
        default:
         cout<<" Invalid Id"<<endl;
         break;
       
  }
  cout<<"Data updated Successfully! "<<endl;
  
     }
    }

    //Remove Librarian 
    void LibrarianCollection::RemoveLibrarian(int Id)
    {
        for(int i=0; i<LibrarianCol.size();i++)
        {
            if(LibrarianCol[i].getId()==Id)
            {
                LibrarianCol.erase(LibrarianCol.begin()+i);
                cout<<"Data Removed Successfully!"<<endl;
                return;
            }
        }
        cout<<"Librarian with Id "<<Id<< " not found! "<<endl;
    }



void LibrarianCollection::PostRegistrationMenu() 
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
resetcolor();
}

//Login Function
bool LibrarianCollection::loginUser()
{

   string name, email;
   cout << "Enter Name: ";
   name = utility::GetStringFromUser(50);
   cout << "Enter Email: ";
   email = utility::GetStringFromUser(50);
   
   for (auto& lib : LibrarianCol)
    {
   if (lib.name == name && lib.email == email)
    {
   cout << "Librarian Login Successful!\n";
   Main_menu();
   return true;
   }
   else
   {
   cout << "Invalid Librarian credentials.\n";
   return false;
   }
  }
   }

 //registerUser Function   
void  LibrarianCollection::registerUser()
{
    setcolor(37);
    Librarian lib;
    cout << "Registering Librarian:\n";
    lib.addLibrarian(LiCollection); 
    cout << "Librarian Registered Successfully!\n";
    WriteDataToFile();
    PostRegistrationMenu();
    
}

//GetString Function
   string Librarian::GetString()
   {
     return to_string(librarianId)+","+(name)+","+(email)+","+(getContact())+","+(role);
   }
   
   void Librarian::ReadString(string line)
   {
     size_t pos=0;
     string token;
     pos=line.find(',');
     token=line.substr(0,pos);
     librarianId=stoi(token);
     line.erase(0,pos+1);
    
    
    // Extract Name
    pos = line.find(',');
    token = line.substr(0, pos);
    name = token;  // Assuming 'name' is inherited from Person
    line.erase(0, pos + 1);

    // Extract Email
    pos = line.find(',');
    token = line.substr(0, pos);
    email = token;  
    line.erase(0, pos + 1);

    // Extract Contact
    pos = line.find(',');
    token = line.substr(0, pos);
    setContact(token); 
    line.erase(0, pos + 1);

    // Remaining part is Role
    role = line;
}

   
//file ssaving
void LibrarianCollection::WriteDataToFile()
{
    ofstream ofs("Librarian.csv", ios::out); // overwrite file, not append
    if(ofs.is_open())
    {
        for( auto& l : LibrarianCol)
        {
            string str = l.GetString();
            ofs << str << endl;
        }
    }
    ofs.close();
}

//file reading
void LibrarianCollection::ReadDataFromFile()
{
    ifstream reader("Librarian.csv");
    if(!reader)
    {
        cout<<"file not found"<<endl;
        return;
    }
    string line;
    while(getline(reader,line))
    {
        if(line.length()>4)
        {
            Librarian l;
            l.ReadString(line);
            // Check for invalid contact (e.g., "-0", "empty", or empty string)
            std::string contact = l.getContact();
            if (contact == "-0" || contact == "empty" || contact.empty()) {
                cout << "Invalid contact number found in file, skipping entry." << endl;
                continue; // Skip this librarian
            }
            LibrarianCol.push_back(l);
        }
    }
}