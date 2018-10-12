#include<iostream>
using namespace std;

class Admin
{
public:
    char pwd[20];
    Admin()
    {
        strcpy(pwd,"123");
    }
    Admin(char * s)
    {
        strcpy(pwd,s);
    }
};



class Student
{
public:
    int reg_no;
    char pawd[20];
    char name[20];
    char year[5];
    char branch[10];
    void in()
    {
        cout<<"\n\t\tENTER REG NO. OF THE STUDENT :-\n\t\t";
        cin>>reg_no;
        cout<<"\n\t\tENTER NAME OF THE STUDENT :-\n\t\t";
        cin>>name;
        cout<<"\n\t\tWHICH YEAR :-\n\t\t";
        cin>>year;
        cout<<"\n\t\tWHICH BRANCH :-\n\t\t";
        cin>>branch;
        cout<<"\n\t\tASSIGN PASSWORD :-\n\t\t";
        cin>>pawd;
    }
};






