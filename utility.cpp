#include<iostream>
#include<conio.h>
#include<string>
#pragma once
using namespace std;
class utility
{
    public:
   static int GetNumberFromUser(int len)
    {
        char strNum[11];
        char ch;
        int i=0;
        while(i<len)
        {
            ch=getch();
            if(ch>='0'&&ch<='9')
            {
                cout<<ch;
            strNum[i]=ch;
            i++;
            }

            if(ch=='\r')
            {
                break;
            }

            if(ch=='\b' &&i>0)
            {
                cout<<"\b \b";
               i--;
            }
        }
        strNum[i]='\0';
        cout<<"\n";
        if(i<=0)
        {
            return 0;
        }
        else
        return atoi(strNum);
    }

    static string GetStringFromUser(int len)
    {
        char strBuffer[256];
        if(len>256)
        {
            len=256;
        }
        char ch;
        int i=0;
        while(i<len)
        {
            ch=getch();
            if((ch>='a'&&ch<='z') ||(ch>='A'&&ch<='Z') ||(ch>='0'&&ch<='9')||ch==' '||ch=='@'||ch=='.')
            {
                cout<<ch;
            strBuffer[i]=ch;
            i++;
            }

            if(ch=='\r')
            {
                break;
            }

            if(ch=='\b' &&i>0)
            {
                cout<<"\b \b";
               i--;
            }
        }
        strBuffer[i]='\0';
        cout<<"\n";
        if(i<=0)
            return " ";
        else
        return strBuffer;
    }

};
