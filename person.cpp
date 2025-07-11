 #include"Person.h"
 //Geter Function for Person's contact
 string Person:: getContact()
 { 
return contact;
 }


 //Seter Function for person's contact
void Person:: setContact(string con)
 {
    if (con.length() >= 10)
        contact = con;
    else
    {
        cout<<"Invalid contact number"<<endl;
    }
}


//default Person constructor
Person::Person()
{
  name="No name";
  email="empty";
  contact="-0";  
}

//Parametrized Person Constructor
 Person::Person(string nam,string em,string cont)
 {
   name=nam;
   email=em;
   contact=cont;
 }

 //copy constructor:
 Person::Person(const Person &P)
{
  name=P.name;
  email=P.email;
  contact=P.contact;
}

//Person::~Person()
