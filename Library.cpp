#pragma once
#include "Fine.cpp"
#include "IssueBook.cpp"
#include <vector>
using namespace std;

class Library 
{
public:
    vector<IssueBook> Ibooks;
    vector<fine> fines;

    // Return book function
    void returnBook(int issueId)
    {
        for (auto& issue : Ibooks)
        {
            if (issue.getTid() == issueId && !issue.isReturned)
            {
                issue.isReturned = true;

                // Set actual return date to current date
                time_t now = time(0);
                tm* localTime = localtime(&now);
                issue.Actual_Returndate.year = 1900 + localTime->tm_year;
                issue.Actual_Returndate.month = 1 + localTime->tm_mon;
                issue.Actual_Returndate.day = localTime->tm_mday;

                // If returned late
                if (difftime(now, convertToTimeT(issue.ReturnDate)) > 0)
                {
                    // Check if fine already exists for this transaction
                    bool exists = false;
                    for (auto& f : fines)
                    {
                        if (f.TId->getTid() == issue.getTid())
                        {
                            exists = true;
                            break;
                        }
                    }
                    if (!exists)
                    {
                        fines.emplace_back(&issue);
                        fines.back().calculateFine();
                    }
                }

                // Write fines to Fine.csv after update
                FineCollection fineCollection;
                fineCollection.fineList = this->fines;
                fineCollection.WriteDataToFile();

                break;
            }
        }
    }

    // Daily overdue check
    void dailyOverdueCheck()
    {
        time_t now = time(0);
        for (auto& issue : Ibooks)
        {
            if (!issue.isReturned && difftime(now, convertToTimeT(issue.ReturnDate)) > 0)
            {
                // Check if fine already exists
                bool exists = false;
                for (auto& f : fines)
                {
                    if (f.TId->getTid() == issue.getTid())
                    {
                        exists = true;
                        break;
                    }
                }
                if (!exists)
                {
                    fines.emplace_back(&issue);
                    fines.back().calculateFine();
                }
            }
        }
        // Write fines to Fine.csv after update
        FineCollection fineCollection;
        fineCollection.fineList = this->fines;
        fineCollection.WriteDataToFile();
    }
};