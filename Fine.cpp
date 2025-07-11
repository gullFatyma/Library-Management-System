#pragma once
#include"fine.h"
#include<ctime>
 fine::fine()
 {
      TId=new IssueBook();
     fineAmount=0000;
     date_ToPay={0,0,0};
     isPaid=false;
 }
//Fine Parametrized Constructor
 fine::fine( IssueBook* id)
 { 
TId=id;
fineAmount=0;
date_ToPay={0,0,0};
isPaid=false;
}

 fine::fine(const fine &f)
{
    TId=f.TId;
fineAmount=f.fineAmount;
date_ToPay=f.date_ToPay;
isPaid=f.isPaid;
}


time_t convertToTimeT(const Date& d)
 {
    std::tm timeStruct = {};
    timeStruct.tm_mday = d.day;
    timeStruct.tm_mon = d.month - 1;
    timeStruct.tm_year = d.year - 1900;
    return mktime(&timeStruct);
}


void fine::calculateFine() 
{
     fineAmount = 0;

    if (TId->ReturnDate.year > TId->Actual_Returndate.year)
        fineAmount += 100;
    else if (TId->ReturnDate.month > TId->Actual_Returndate.month)
        fineAmount += 50;
    else if (TId->ReturnDate.day > TId->Actual_Returndate.day)
        fineAmount += 20;

}


void fine::PayFine()
{
    if (!isPaid)
    {
        isPaid = true;

        time_t now = time(0);
        tm *ltm = localtime(&now);

        date_ToPay.day = ltm->tm_mday;
        date_ToPay.month = ltm->tm_mon + 1;
        date_ToPay.year = ltm->tm_year + 1900;

        cout << "Fine paid successfully on " 
             << date_ToPay.day << "/" 
             << date_ToPay.month << "/" 
             << date_ToPay.year << "." << endl;
    }
    else
    {
        cout << "This fine has already been paid." << endl;
    }
}



void fine::display()
{
    cout<<"Enter details of Fine "<<endl;
    cout<<"-------------------------------------------------\n";
    cout<<endl;
    cout<<"Transaction Id: "<<TId->getTid()<<endl;
    cout<<endl;
    cout<<"Fine amount: "<<fineAmount<<endl;
    cout<<endl;
    cout<<"Date to pay: "<<date_ToPay.day<<"/"<<date_ToPay.month<<"/"<<date_ToPay.year<<endl;
    cout<<endl;
    cout<<"Is paid: "<<isPaid<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------\n";
}


void FineCollection::AddFine(fine &f)
{
    fineList.push_back(f);
}

void FineCollection::Display()
{
    for (fine &f : fineList)
    {
        f.display();
    }
}

fine* FineCollection::GetFine(int Tid)
{
    for (int i = 0; i < fineList.size(); i++)
    {
        if (fineList[i].TId->getTid() == Tid)
        {
            return &fineList[i];
        }
    }
    return nullptr;
}

void FineCollection::Update(int Tid)
{
    fine* f = GetFine(Tid);
    if (f == nullptr)
    {
        cout << "Fine Not Found!" << endl;
        return;
    }

    int choice;
    cout << "What do you want to update?\n";
    cout << "1. Fine Amount\n";
    cout << "2. Date to Pay\n";
    cout << "3. Payment Status\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter new fine amount: ";
        cin >> f->fineAmount;
        break;
    case 2:
        cout << "Enter new date to pay [dd mm yyyy]: ";
        cin >> f->date_ToPay.day >> f->date_ToPay.month >> f->date_ToPay.year;
        break;
    case 3:
        char paid;
        cout << "Is fine paid? [y/n]: ";
        cin >> paid;
        f->isPaid = (paid == 'y' || paid == 'Y');
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    cout << "Fine updated successfully!" << endl;
}

void FineCollection::RemoveFine(int Tid)
{
    for (int i = 0; i < fineList.size(); i++)
    {
        if (fineList[i].TId->getTid() == Tid)
        {
            fineList.erase(fineList.begin() + i);
            cout << "Fine removed successfully!" << endl;
            return;
        }
    }
    cout << "Fine with ID " << Tid << " not found!" << endl;
}

void FineCollection::DisplayByMemberId(int memberId) 
{
    bool found = false;
    cout << "\n--- Fines for Member ID: " << memberId << " ---\n";

    for (fine& f : fineList) {
        if (f.TId && f.TId->getBorrower() && f.TId->getBorrower()->getId() == memberId) {
            f.display();
            found = true;
        }
    }

    if (!found)
        cout << "No fines found for this member.\n";
}


//GetString Function
string fine::GetString()
{
string dateStr = to_string(date_ToPay.day) + "-" +
 to_string(date_ToPay.month) + "-" + to_string(date_ToPay.year);

int tid = (TId != nullptr) ? TId->getTid() : 0;
return to_string(tid) + "," + to_string(fineAmount) + "," + dateStr + "," + (isPaid ? "1" : "0");
}

//Read string
void fine::ReadString(const string& line)
{
    string temp = line;
    size_t pos = temp.find(',');
    string token;

    token = temp.substr(0, pos);
    int tid = stoi(token);
    if (TId == nullptr) TId = new IssueBook();
    TId->setIssueBookID(tid);

    temp.erase(0, pos + 1);

    pos = temp.find(',');
    token = temp.substr(0, pos);
    fineAmount = stoi(token);
    temp.erase(0, pos + 1);

    pos = temp.find(',');
    token = temp.substr(0, pos);
    temp.erase(0, pos + 1);

    size_t dash1 = token.find('-');
    size_t dash2 = token.find('-', dash1 + 1);
    date_ToPay.day = stoi(token.substr(0, dash1));
    date_ToPay.month = stoi(token.substr(dash1 + 1, dash2 - dash1 - 1));
    date_ToPay.year = stoi(token.substr(dash2 + 1));

    isPaid = (temp == "1");
}

//file saving
void FineCollection::WriteDataToFile()
{
    ofstream ofs("Fine.csv", ios::out);  // overwrite file on each save
    if (!ofs)
    {
        cout << "Error opening file for writing Fine data." << endl;
        return;
    }

    for (auto& f : fineList)
    {
        ofs << f.GetString() << endl;
    }

    ofs.close();
}

//file reading
void FineCollection::ReadDataFromFile()
{
    ifstream ifs("Fine.csv");
    if (!ifs)
    {
        cout << "Fine data file not found." << endl;
        return;
    }

    fineList.clear();  // Clear existing fines

    string line;
    while (getline(ifs, line))
    {
        if (line.length() > 4) // basic check
        {
            fine f;
            f.ReadString(line);
            fineList.push_back(f);
        }
    }

    ifs.close();
}

// Add destructor for fine
fine::~fine() {
    if (TId) delete TId;
}
