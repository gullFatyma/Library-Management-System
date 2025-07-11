#include<iostream>
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