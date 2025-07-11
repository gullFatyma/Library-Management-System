#pragma once
#include<iostream>
using namespace std;

class Date
{   
    public:
  int day;
  int month;
  int year;
        
  Date()
  {
    day=0;
    month=0;
    year=0;
  }
  Date(int d,int m,int y)
  {
    day=y;
    month=m;
    year=y;
  }
        int daysSince(Date d) 
        {
            int thisTotal = year * 365 + month * 30 + day;
            int otherTotal = d.year * 365 + d.month * 30 + d.day;
            return thisTotal - otherTotal;
        }
    };
