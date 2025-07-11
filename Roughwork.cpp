 #include<iostream>
 using namespace std;

 #include <iostream>
#include <conio.h>  
#include <string>
#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"

#include "Appointment.h"
#include "Prescription.h"

using namespace std;

void MainMenu()
{
	cout << "1. Manage Patients" << endl;
	cout << "2. Manage Doctors" << endl;
	cout << "3. Manage Nurses" << endl;
	cout << "4. Manage Prescription" << endl;
	cout << "5. Manage Appointments" << endl;
	cout << "6. Backup" << endl;
	cout << "7. Restore" << endl;
	cout << "8. Exit" << endl;
}

/*

class GrandParent
{
public:
    int abc;
    GrandParent()
    {
        cout << "+ I am Grand Parent" << endl;
    }

    ~GrandParent()
    {
        cout << "- I am Grand Parent" << endl;
    }
};
class Parent : public GrandParent
{
public:
    Parent()
    {
        cout << "+ I am Parent" << endl;
    }

    ~Parent()
    {
        cout << "- I am Parent" << endl;
    }
};
class Child : public Parent
{
public:
    Child()
    {
        cout << "+ I am Chand" << abc << endl;
    }

   ~Child()
    {
        cout << "- I am Chand" << endl;
    }
};
*/

void ManagePatients();
void ManagePrescriptions();

class PatientCollection
{
public:
    Patient* patients[10000];
    int Count;

    PatientCollection()
    {
        Count = 0;
    }

    void AddPatient(Patient p)
    {
        patients[Count] = new Patient(p);
        Count++;
    }

	~PatientCollection()
	{
		for (int i = 0; i < Count; i++)
		{
			delete patients[i];
		}
	}

    void AddPatient(int id, string name)
    {
        patients[Count] = new Patient();
        patients[Count]->PatientID = id;
        patients[Count]->Name = name;
        Count++;

    }

    Patient* GetPatientByID(int id)
    {
        for (int i = 0; i < Count; i++)
        {
            if (patients[i]->PatientID == id)
            {
                return patients[i];
            }
        }
        // not found return dummy patient with id -1
        
        return NULL;
    }

    void DisplayAll()
    {
        cout << "ID" << "\t" << "Name" << endl;

        for (int i = 0; i < Count; i++)
        {
            patients[i]->Display();
        }
    }

};

class DoctorCollection{
public:
	vector<Doctor> doctors;

	DoctorCollection()
	{
	}

    int GetCount()
    {
		return doctors.size();
    }

	void AddDoctor(Doctor d)
	{
		doctors.push_back(d);
		
	}
	void AddDoctor(int id, string name)
	{
        Doctor d;
        d.DID = id;
        d.Name = name;
        doctors.push_back(d);
	}
	Doctor* GetDoctorByID(int id)
	{
		for (int i = 0; i < doctors.size(); i++)
		{
			if (doctors[i].DID == id)
			{
				return &doctors[i];
			}
		}
		// not found return dummy doctor with id -1

		return NULL;
	}

    void DisplayAll()
    {
		for (Doctor doc : doctors)
        {
			cout << "Doctor ID: " << doc.DID << ", Name: " << doc.Name << endl;
		}
    }

	};

class NurseCollection {
public:
	Nurse nurses[100];
	int Count;
	NurseCollection()
	{
		Count = 0;
	}
	void AddNurse(Nurse n)
	{
		nurses[Count] = n;
		Count++;
	}
	void AddNurse(int id, string name)
	{
		nurses[Count].StaffID = id;
		nurses[Count].Name = name;
		Count++;
	}
	Nurse* GetNurseByID(int id)
	{
		for (int i = 0; i < Count; i++)
		{
			if (nurses[i].StaffID == id)
			{
				return &nurses[i];
			}
		}
		// not found return dummy nurse with id -1
		return NULL;
	}
};

class AppointmentCollection
{
public:
    Appointment appointments[100];
    int Count;
    AppointmentCollection()
    {
        Count = 0;
    }
    void AddAppointment(Appointment a)
    {
        appointments[Count] = a;
        Count++;
    }

    Appointment* GetAppointmentByID(int id)
    {
		for (int i = 0; i < Count; i++)
		{
			if (appointments[i].AppID == id)
			{
				return &appointments[i];
			}
		}
		// not found return dummy appointment with id -1
		return NULL;
    }

};

class PrescriptionCollection
{
public:
	Prescription prescriptions[100];
	int Count;
	PrescriptionCollection()
	{
		Count = 0;
	}
	void AddPrescription(Prescription p)
	{
		prescriptions[Count] = p;
		Count++;
	}
	Prescription* GetPrescriptionByID(int id)
	{
		for (int i = 0; i < Count; i++)
		{
			if (prescriptions[i].PresID == id)
			{
				return &prescriptions[i];
			}
		}
		return NULL;
	}
};


PatientCollection pCol;
DoctorCollection doctorCol;
NurseCollection nurseCol;
AppointmentCollection appCol;
PrescriptionCollection presCol;

int LoggedInUser = 2;

void ManageAppointments();


int main()
{

	pCol.AddPatient(1, "Ali");
	pCol.AddPatient(2, "Sana");
	pCol.AddPatient(3, "Sara");
	pCol.AddPatient(4, "Ahmed");

	doctorCol.AddDoctor(1, "Dr. Naveed");
	doctorCol.AddDoctor(2, "Dr. Usman");

    nurseCol.AddNurse(1, "Sadia");
    nurseCol.AddNurse(2, "Aslam");


    /*Patient p1;
    p1.PatientID = 1;
    p1.Name = "Ahmed";
    pCol.AddPatient(p1);

    pCol.AddPatient(2, "Sana");

    cout << "Count Patients" << pCol.Count << endl;*/



    cout << "Welcome to Hospital Management System!\n";
    cout << "\n";

    while (1)
    {

        MainMenu();
        int choice = 0;

        cout << "Enter your choice: ";
        cin >> choice;

        //cout << "You have selected: " << choice << endl;

        switch (choice)
        {
        case 1:
            ManagePatients();
            break;
		case 4:
            ManagePrescriptions();
			break;
        case 5:
            ManageAppointments();
        default:
            break;
        }

        if (choice == 8)
        {
            exit(0);
        }

    }

}

void ManagePatients()
{

    while (1)
    {
        Patient p;

        Patient::PatientMenu();
        int choice = 0;

        cout << "Enter your choice: ";
        cin >> choice;

        //cout << "You have selected: " << choice << endl;

        switch (choice)
        {
        case 1:  // Add new patient
        {
            Patient p1;
            cout << "Enter Patient ID";
            cin >> p1.PatientID;
            cout << "Enter Name";
            cin >> p1.Name;
            pCol.AddPatient(p1);

            //p.GetInputFromUser();
        }
        break;
        case 2:
            // Search Patient
        {
            int pid;
            cout << "Enter Patient ID to search: ";
            cin >> pid;
            Patient* temp = pCol.GetPatientByID(pid);
            if (temp == NULL)
            {
                cout << "Patient not found" << endl;
            }
            else
                temp->Display();
        }
        break;
        case 3:
        {
        // Update Patient Information
        int pid;
        cout << "Enter Patient ID to update: ";
        cin >> pid;
        Patient* temp = pCol.GetPatientByID(pid);
        if (temp == NULL)
        {
            cout << "Patient not found" << endl;
        }
        else
        {
            cout << "Enter Patient ID: ";
            cin >> temp->PatientID;
            cout << "Enter Name: ";
            cin >> temp->Name;
        }
        }
        break;        
        case 5:
        {
           pCol.DisplayAll();
        }
        break;
        default:
            break;
        }

        if (choice == 6)
        {
            break;
        }

    }
}


void ManageAppointments()
{
	while (1)
	{
		Appointment a;
		cout << "1. Issue Appointment" << endl;
		cout << "2. Search Appointment" << endl;
		cout << "3. Update Appointment" << endl;
		cout << "4. Cancel Appointment" << endl;
		cout << "5. Back to Main Menu" << endl;
		int choice = 0;
		cout << "Enter your choice: ";
		cin >> choice;
		//cout << "You have selected: " << choice << endl;
		switch (choice)
		{
        case 1:
            // Add new appointment
        {
            Appointment app;
			cout << "Enter Appointment ID: ";
			cin >> app.AppID;
			cout << "Enter Appointment Day: ";
			cin >> app.AppDate.dd;
			cout << "Enter Appointment Month: ";
			cin >> app.AppDate.mm;
			cout << "Enter Appointment Year: ";
			cin >> app.AppDate.yyyy;

			cout << "Enter Patient ID: ";
			int pid;
			cin >> pid;
			Patient* temp = pCol.GetPatientByID(pid);
            if (temp != NULL)
            {
				app.RefPatient = temp;
                cout << "Enter Doctor ID:";
                int did;
                cin >> did;
				Doctor* doc = doctorCol.GetDoctorByID(did);
                if (doc != NULL)
                {
					app.Examinar = doc;
					Nurse* nurse = nurseCol.GetNurseByID(LoggedInUser);
                    if (nurse != NULL)
                    {
                        app.IssueBy = nurse;
						cout << "Appointment Issued Successfully!" << endl;
						appCol.AddAppointment(app);
                    }

                }
            }
            else
            {
				cout << "Patient not found" << endl;
            }

        }

			break;
        case 2:
            // Search appointment
        {
			int appID;
			cout << "Enter Appointment ID to search: ";
			cin >> appID;
			Appointment* temp = appCol.GetAppointmentByID(appID);
            if (temp != NULL)
            {
                temp->Display();
            }
            else
            {
                cout << "Appointment not found";
            }
         }
			break;
		case 3:
			// Update appointment
			break;
		case 4:
			// Delete appointment
			break;
		default:
			break;
		}
		if (choice == 5)
		{
			break;
		}
	}
}


void ManagePrescriptions()
{
	while (1)
	{
		cout << "1. New Prescription" << endl;
		cout << "2. Search Prescription" << endl;
		cout << "3. Update Prescription" << endl;
		cout << "4. Delete Prescription" << endl;
		cout << "5. Back to Main Menu" << endl;
		int choice = 0;
		cout << "Enter your choice: ";
		cin >> choice;
		//cout << "You have selected: " << choice << endl;
		switch (choice)
		{
        case 1:
        {
            // Add new prescription
            Prescription pres;
            pres.PresID = 123;
            pres.PresDate = Date(11, 4, 2025);
            pres.RefPatient = pCol.GetPatientByID(4);
            pres.Examiner = doctorCol.GetDoctorByID(1);
            pres.Diagnosis = "Fever";

            for (int i = 0; i < 10; i++)
            {
                pres.Dozes[i].medicine = new Medicine();
                pres.Dozes[i].DoseDetails = "2 times a day";

                cout << "Do you want to add more items? Press y";
                char ch = 'n';
                ch = _getch();

                if (ch != 'y')
                    break;
            }

            presCol.AddPrescription(pres);
            pres.Display();

        }
			break;
		case 2:
			// Search prescription
			break;
		case 3:
			// Update prescription
			break;
		case 4:
			// Delete prescription
			break;
		default:
			break;
		}
		if (choice == 5)
		{
			break;
		}
	}
}




//1. Manage Patients
//		a. Add New Patient
//	    b. Search Patient
//	    c. Update Patient Information
//	    d. Delete Patient
//	    e. Back to Main Menu
//2. Manage Doctors
//3. Manage Staff
//4. Manage Room
//5. Manage Appointment
//6. Backup
//7. Restore
//8. Exit
//  class shape
//  {
//  public:
//  float x,y;
//  void show()
//  {
//     cout<<" I am shape...."<<endl;
//  }
//  };
//  class circle :public shape
//  {
//     public:
//     void show()
//  {
//     cout<<" I am circle...."<<endl;
//  }

//  };
//  class Rectangle :public shape
//  {
//     public:
//     void show()
//  {
//     cout<<" I am Rectangle...."<<endl;
//  }
//  float calculate(float l , float w)
//  {
//    return l*w;
//  }
//  };
//  class Myself: public shape,Rectangle
//  {
// public:
// void show()
// {
//     cout<<"I am myself"<<endl;
// }
//  };
//  int main()
// {
//     shape b;
//     Rectangle r;
//     circle c;
//     Myself m;
//     b.show();
//     cout<<"=============="<<endl;
//     r.show();
//     cout<<"..."<<r.calculate(34.3,34.5);
//     cout<<"=============="<<endl;
//     c.show();
//     shape* s=&r;
//     cout<<"=============="<<endl;
//     s->show();
//     return 0;
// } 
// class Book 
// {
// private:
//     int bookID;
// public:
//     string title;
//     string author;
//     string publisher_name;
//     bool isavailable;

//     //Getter Function
//     int GetId()
//     { 
//        return bookID; 
//      }

//      //set ID Function
//      void SetId(int book_ID)
//      {
//         if (book_ID > 0)
//          {
//             bookID = book_ID;
//         } else {
//             cout<<"Invalid ID"<<endl;
//         }
//     }
//     //defaullt constructor
//     Book() 
//     {
//         bookID= 0;
//         title = "Empty";
//         author = "Empty";
//         publisher_name="No name";
//         isavailable=false;

//     }
// //Parametrized constructor
//     Book(int ID, string t,string pub, string a,bool av) 
//     {
//         bookID = ID;
//         title = t;
//         author = a;
//         publisher_name=pub;
//         isavailable=false;
//     }
// //copy Constructor
//     Book(const Book&b)
//     {
//         bookID=b.bookID;
//         title=b.title;
//         author=b.author;
//         publisher_name=b.publisher_name;
//         isavailable=b.isavailable;
//     }
//     //destructor
// ~Book()
// {

// }
// };
// #pragma once
// #include<iostream>
// #include<string>
// #include"Person.h"
// using namespace std;

// class Librarian
//  {
// private:
//     int librarianId;
//     string contact;
// public:
//      string name;
//      string email;
//     string role;

//     //geter Function:
//     string  getContact()
//   { 
//   return contact;
//   }


//  //Seter Function for contact
// void setContact(string con)
//  {
//     if (con.length() >= 10)
//         contact = con;
//     else
//         cout<<"Invalid contact number"<<endl;
// }

// //geter function 
//  int getId()
// { 
//  return librarianId;
// }


// //seter Function for LibraianId
// void setId(int lib_ID) 
// {
// if (lib_ID > 0) 
// {
//        librarianId = lib_ID;
//    } 
//    else
//     {
//        cout<<"Invalid ID"<<endl;
//    }
// }
// Librarian()
// {
//   librarianId = 0;
//   contact=-999;
//   name="===";
//   email="Invalid";
//     role = "empty";
//     cout<<"const"<<endl;
// }

// //Parametrized Librarian constructor
//  Librarian(int id, string Name, string Email,string Contact, string Role)
// {
//     librarianId = id;
//     name=Name;
//     email=Email;
//     contact=Contact;
//     role = Role;
//     cout<<"const"<<endl;
// }
// //Copy Constructor
// Librarian::Librarian(const Librarian &l)
// {
//     librarianId=l.librarianId;
//     name=l.name;
//     contact=l.contact;
//     email=l.email;
//     role=l.role;
// }

// //Destructor
// ~Librarian()
// {

// }
//  };
    // int getId();
    // void setId(int lib_ID) ;

    // Librarian() ;
   
    // Librarian(int id, string Name,string Email, string Contact, string Role) ;
    

//     class Member
//     {
//    private:
//    int memberID;
//     string contact ;
//    public:
//    string name;
//    string email;
//    Date DateOf_joining;
        

// //Geter Function for MemberId
// int Member:: getId()
// {
//    return memberID;
// }

// //seter Function for MemberId
// void Member::SetId(int mem_ID) 
// {
//   if (mem_ID > 0)
//    {
//       memberID = mem_ID;
//   } 
//   else
//   {
//       cout<<"Invalid ID"<<endl;
//   }
// }

//     //Geter Function For contact
//         string  getContact()
//    { 
//     return contact;
//    }


//   //Seter Function for contact
// void setContact(string con)
// {
//      if (con.length() >= 10)
//         contact = con;
//   else
//       cout<<"Invalid contact number"<<endl;
// }

// //Default Constructor
//        Member()
//    {
//    memberID = 0;
//    DateOf_joining={0,0,0};
//    name="no name";
//    email="inalid formate";
//    contact="00000";

//    }
// //Parametrized constructor
//        Member(int id,Date DOJ, string Name, string Email,string contacT)
//        {
//         memberID = id;
//         DateOf_joining=DOJ;
//        name=Name;
//       email=Email;
//      contact=contacT;
//      }

//       //Destructir
//       ~Member()
//       {

//       }  
      
//       //Copy Constructor
//       Member::Member(const Member &m)
//       {
//         memberID =m.memberID;
//         DateOf_joining=m.DateOf_joining;
//        name=m.name;
//       email=m.email;
//        contact=m.contact;
//       }
//     };
// class Transaction
// {
// private:
// int TransactionId;
//  int borrowID;     //Member Id
//  int issuedby;    //librarian id
//  int Bookborrowed;      
//  public:
//  Date IssueDate;
//  Date Actual_Returndate;     
//  Date ReturnDate;
//  bool isReturned;

//  //int getID();               
//  //void setID(Member* m);

//  int getTid();
//  void setTransactionID(int TrId);  //TransactionId
//  int  getId()
//   {
//    return borrowID;
// }

// //seter Function for MemberId
// void SetId(int mem_ID) 
// {
//   if (mem_ID > 0)
//    {
//       borrowID = mem_ID;
//   } 
//   else
//   {
//       cout<<"Invalid ID"<<endl;
//   }
// }
 
// //geter function 
//  int getId()
// { 
//  return issuedby;
// }


// //seter Function for LibraianId
// void setId(int lib_ID) 
// {
// if (lib_ID > 0) 
// {
//        issuedby = lib_ID;
//    } 
//    else
//     {
//        cout<<"Invalid ID"<<endl;
//    }
// }

// int GetId()
//      { 
//         return Bookborrowed; 
//     }

//  //Seter Function for BookId   
//     void  SetId(int book_ID)
//      {
//         if (book_ID > 0)
//          {
//             Bookborrowed = book_ID;
//         } else {
//             cout<<"Invalid ID"<<endl;
//         }
//     }

//     //default constructor
//     Transaction()
//  {
//   TransactionId=0;
//    borrowID=0;
//    issuedby=0;
//    Bookborrowed=0;
//    IssueDate={0,0,0};
//    Actual_Returndate={0,0,0};
//    ReturnDate={0,0,0};
//    isReturned=false;
//  }

//  //copy constructor
//  Transaction(const Transaction &t)
//  {
//     TransactionId=t.TransactionId;
//    borrowID=t.borrowID;
//    issuedby=t.issuedby;
//    Bookborrowed=t.Bookborrowed;
//    IssueDate=t.IssueDate;
//    Actual_Returndate=t.Actual_Returndate;
//    ReturnDate=t.ReturnDate;
//    isReturned=t.isReturned;
//  }
// //Parametrized Transaction constructor
// Transaction::Transaction(int TrId,int L,int  bId,int Borrowed,Date ID,Date AD,Date ReturnD,bool isReturn)
// {
//  TransactionId=TrId;
//  issuedby=L;
//   borrowID=bId;
//   Bookborrowed=Borrowed;
//   IssueDate=ID;
//   Actual_Returndate=AD;
//   ReturnDate=ReturnD;
//   isReturned=isReturn;
// }

// //Destructor
// ~Transaction()
// {

// }
  
// };
// class fine
// {  
//  int TId;        //transactionId
//  int member_Id;
//  public:
//   int fineAmount;
//  Date date_ToPay;
//  bool isPaid;
 

//  //Geter Function
//  int  getId()
//   {
//    return TId;
// }

// //seter Function for MemberId
// void SetId(int mem_ID) 
// {
//   if (mem_ID > 0)
//    {
//       TId = mem_ID;
//   } 
//   else
//   {
//       cout<<"Invalid ID"<<endl;
//   }
// }

// int  getId()
//   {
//    return member_Id;
// }

// //seter Function for MemberId
// void SetId(int mem_ID) 
// {
//   if (mem_ID > 0)
//    {
//       member_Id = mem_ID;
//   } 
//   else
//   {
//       cout<<"Invalid ID"<<endl;
//   }
// }

// //Default Constructor
// fine()
// {
//     TId;
//     member_Id=0;
//     fineAmount=0000;
//     date_ToPay={0,0,0};
//     isPaid=false;
// }

// //Fine Parametrized Constructor
// fine( int id,int ID,int amount ,Date date,bool paid)
// {
// member_Id=ID;
// fineAmount=amount;
// date_ToPay=date;
// isPaid=paid;

// }

// //copy constructor
// fine(const fine &f)
// {
//     member_Id=f.member_Id;
// fineAmount=f.fineAmount;
// date_ToPay=f.date_ToPay;
// isPaid=f.isPaid;
// }

// //destructor
// ~fine()
// {

// }
// };
// #include<iostream>
// using namespace std;
// class Database
// {
// private:
// string data;
// Database()
// {
//     data="Intial Data";
// }
// static Database* obj;
// static int count;
// public:
// static Database* getObj()
// {
//     if(!obj)
//     {
//     obj= new Database();
//     }
//     count++;
//     return obj;

// }
// void setData(string newData)
// {
//     data=newData;

// }
// void display()
// {
//     cout<<"Data: "<<data<<endl;
// }

// void displayCount()
// {
//     cout<<"Object Accessed : "<<count<<"Times"<<endl;
// }

// };
// Database* Database::obj=nullptr;
// int Database::count=0;
// int main()
// {
//     Database* db=Database::getObj();
//     db->display();
//     db->displayCount();
//     db->setData("New Dataaa");
//     db->display();
//     db->displayCount();
//     Database* db2=Database::getObj();
//     db2->display();
//     db2->displayCount();
//     db->setData("another data");
//     db2->display();
// }