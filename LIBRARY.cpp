
                                   /************************************************
                                            D.S.A MINI PROJECT

                                     *      TOPIC : LIBRARY MANAGEMENT SYSTEM     *

                                            By  - AROOP KUMAR (3224)
                                                - ASHISH (3227)
		                            ************************************************/


///  REQUIRED HEADER FILES  ///
#include<iostream>
#include<string.h>
#include"PASS.h"
#include<stdlib.h>
#include<conio.h>
#include<fstream>


///  STANDARD NAMESPACE  ///
using namespace std;


///  CLASS DECLARATION  ///
class Library
{
public :
    char b_id[30], b_name[30], author[30], pub[30];

    int quan,curr, fine , B;

    Library()
    {
        strcpy(b_id,"NONE");
        strcpy(b_name,"NONE");
        strcpy(author,"NONE");
        strcpy(pub,"NONE");
        curr = 0;
        fine = 0;
        quan = 0;
    }

    void menu();
    void pass_adm();
    void admin();
    void booklist(int x);
    int branch(int x);
    void student();
    void sch(int x);
    void input();
    void show(int x);
    void add();
    void modify();
    void status();
    void memadd();
};
Library obj;

///  MENU FUNCTION  ///
void Library :: menu()
{
    int ch;
        cout<<"\n\t\t\t   ************< A.I.T LIBRARY MANAGEMENT SYSTEM >************\n"<<endl;
        cout<<"\n\t\t      >>>SIGN IN AS :-\n";
        cout<<"\n\t\t\t1. ADMINISTRATOR\n\n\t\t\t2. STUDENT\n\n\t\t\t3. CLOSE APPLICATION\n";
        cout<<"\n\n\t\t\t>>ENTER YOUR CHOICE : ";
        cin>>ch;

    switch(ch)
    {
        case 1 : pass_adm(); break;

        case 2 : student(); break;

        case 3 : cout<<"\n\n\t\tPROGRAM CLOSED SUCCESSFULLY!!!\n";
                 exit(0); break;

        default : cout<<"\n\n\t\tPLEASE ENTER CORRECT OPTION :(";
                  getch();
                  system("cls");
                  menu();
    }
}


///  PASSWORD VERIFICATION (ADMIN) ///
void Library :: pass_adm()
{
    int i=0;
    char ch,pass[20];
    cout<<"\n\n\t\tENTER PASSWORD : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        pass[i]='\0';
        break;
    }
    else if(ch==8&&i>=0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    pass[i]=ch;
    i++;
    }
    }
    Admin a;
    if(strcmp(pass,a.pwd)==0)
    {
        cout<<"\n\n\t\tPASSWORD VERIFIED :)\n\n\t\tPRESS ANY KEY TO PROCEED.\n\t\t";
        getch();
        system("cls");
        admin();
    }
    else
    {
        cout<<"\n\n\t\tWRONG PASSWORD!!!\n\t\tTRY AGAIN.....\n";
        getch();
        pass_adm();
    }

}


///  ADMIN INTERFACE  ///
void Library :: admin()
{
    int ch;
        cout<<"\n\t\t\t************ WELCOME ADMIN ************\n\t";
        cout<<"\n\t\t>>PLEASE CHOOSE ANY ONE OPTION :\n";
        cout<<"\n\t\t1. VIEW BOOKLIST\n\n\t\t2. SEARCH FOR A BOOK\n\n\t\t3. ADD BOOK\n\n\t\t4. MODIFY BOOK\n\n\t\t5. ADD NEW MEMBERS\n\n\t\t6. GO TO MAIN MENU\n\n\t\t7. CLOSE APPLICATION\n";
        cout<<"\n\t\tENTER YOUR CHOICE : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : booklist(2);
                     break;
            case 2 : sch(2);
                     break;
            case 3 : add();
                     break;
            case 4 : modify();
                     break;
            case 5 : memadd();
                     break;
            case 6 : system("cls");
                     menu();
                     break;
            case 7 : cout<<"\n\n\t\tPROGRAM CLOSED SUCCESSFULLY!!!\n";
                     exit(0);
                     break;
            default:cout<<"\n\t\tPLEASE ENTER CORRECT OPTION ! :(";
            getch();
            system("cls");
            admin();
        }
}


///  VIEWING BOOKLIST  ///
void Library :: booklist(int x)
{
    int b,r=0;
                system("cls");
                b = branch(x);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t\t    ************ Book List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(quan==0 && x==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(x);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(x==1)
                    student();
                else
                    admin();
}


///  BRANCH SELECTION  ///
int Library :: branch(int x)
  {
      int ch;
      cout<<"\n\t\t>>Please Choose one Branch :-\n";
      cout<<"\n\t\t1. COMPUTER\n\n\t\t2. ENTC\n\n\t\t3. IT\n\n\t\t4. MECHANICAL\n\n\t\t5. ASGE\n\n\t\t6. OTHERS\n\n\t\t7. GO TO MAIN MENU\n";
      cout<<"\n\t\t>>ENTER YOUR CHOICE : ";
      cin>>ch;
      switch(ch)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  student();
                  else
                    admin();
          default : cout<<"\n\t\tPLEASE ENTER CORRECT OPTION !:(";
                    getch();
                    system("cls");
                    branch(x);
        }
  }


///  SEARCHING A BOOK  ///
void Library :: sch(int x)
{
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b = branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
            student();
            else
            admin();
        }

      system("cls");
      cout<<"\n\t\tSEARCH BY :-\n";
      cout<<"\n\t\t1. BOOK NAME\n\n\t\t2. BOOK ID\n\n";
      cout<<"\n\t\tENTER YOUR CHOICE : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tENTER NAME OF THE BOOK : ";
          cin>>ch;
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&quan!=0&&b_name[i]!='\0'&&ch[i]!='\0'&&(ch[i]==b_name[i]||ch[i]==b_name[i]+32);i++);
            if(b_name[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBOOK FOUND :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tENTER BOOK ID : ";
          cin>>ch;
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&quan!=0&&b_id!='\0'&&ch[i]!='\0'&&ch[i]==b_id[i];i++);
              if(b_id[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBOOK FOUND :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             sch(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tBOOK NOT AVAILABLE!!!:( \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x==1)
    student();
    else
    admin();
}


///  ADDING NEW MEMBERS  ///
void Library :: memadd()
{
    system("cls");
    ofstream file("Student.txt",ios :: binary | ios :: app);
    if(!file)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            admin();
        }

    Student s;
    s.in();

    file.write((char *)&s,sizeof(s));
    file.close();
    cout<<"\nPRESS ANY KEY TO CONTINUE......\n";
    getch();
    system("cls");
    admin();
}


///  STUDENT INTERFACE  ///
void Library :: student()
{
    system("cls");
    int ch;
        cout<<"\n\t\t************** WELCOME STUDENT **************\n";
        cout<<"\n\t\t\t>>>PLEASE SELECT ONE OPTION FROM BELOW : \n";
        cout<<"\n\t\t\t1. VIEW BOOKLIST\n\n\t\t\t2. SEARCH FOR A BOOK\n\n\t\t\t3. MY STATUS\n\n\t\t\t4. GO TO MAIN MENU\n\n\t\t\t5. CLOSE APPLICATION";
        cout<<"\n\n\t\t>>ENTER YOUR CHOICE : ";
        cin>>ch;

        switch(ch)
        {
            case 1 : booklist(1); break;

            case 2 : sch(1); break;

            case 3 : status();

            case 4 : system("cls");
                     menu();

            case 5 : cout<<"\nPROGEAM TERMINATED SUCCESSFULLY\n";
                     exit(0);

            default : cout<<"\n\t\tPLEASE ENTER A VALID OPTION!:(";
                      getch();
                      system("cls");
                      student();
        }

}


///  INPUT FUNCTION  ///
void Library :: input()
{
     int i;
     fflush(stdin);
     cout<<"\n\t\tENTER THE DETAILS :-\n";
     cout<<"\n\t\tENTER NAME OF THE BOOK : ";
     cin.getline(b_name,50);
     cout<<"\n\t\tENTER AUTHOR'S NAME : ";
     cin.getline(author,50);
     cout<<"\n\t\tENTER NAME OF PUBLISHER : ";
     cin.getline(pub,50);
     cout<<"\n\t\tENTER BOOK ID : ";
     cin.getline(b_id,50);
     cout<<"\n\t\tENTER BRANCH/GENRE : ";
     cin>>B;
     cout<<"\n\t\tENTER TOTAL QUANTITY : ";
     cin>>quan;
     cout<<"\n\t\tENTER REG NO. OF BORROWER : ";
     cin>>curr;
     if(curr!=0)
     {
         cout<<"\n\t\tEnter fine to be imposed\n\t\t";
         cin>>fine;
     }
}


///  DISPLAY BOOK INFO  ///
void Library :: show(int i)
{
    cout<<"\n\t\tBOOK NAME : "<<b_name<<endl;
    cout<<"\n\t\tAUTHOR OF BOOK : "<<author<<endl;
    cout<<"\n\t\tBOOK ID : "<<b_id<<endl;
    cout<<"\n\t\tPUBLICATION : "<<pub<<endl;
    cout<<"\n\t\tFINE IMPOSED : "<<fine<<endl;
    if(i==2)
    {
        cout<<"\n\t\tQUANTITY LEFT : "<<quan<<endl;
        cout<<"\n\t\tCURRENTLY BORROWED BY : "<<curr<<endl;
    }
}


///  ADDING A BOOK TO THE BOOKLIST  ///
void Library :: add()
{
    system("cls");
    B = branch(2);
    system("cls");
    input();
    ofstream outf("Booksdata.txt",ios::app|ios::binary);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\t\tBOOK ADDED SUCCESSFULLY.\n";
    cout<<"\n\t\tPress any key to continue.......\n";
    getch();
    system("cls");
    admin();
}


///  MODIFICATION  ///
void Library :: modify()
{
    int i, b, cont = 0; char st1[50];
    system("cls");
    b = branch(2);
    ifstream intf1("Booksdata.txt",ios::binary);
    if(!intf1)
    {
       cout<<"\n\t\tFile Not Found\n";
       cout<<"\n\t\tPress any key to continue.....";
       getch();
       system("cls");
       admin();
    }
    intf1.close();
    system("cls");
    cout<<"\n\t\tSEARCH BY :-\n";
    cout<<"\n\t\t1. BOOK NAME\n\n\t\t2. BOOK ID\n";
    cout<<"\n\t\tENTER YOUR CHOICE : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
        system("cls");
        cout<<"\n\t\tEnter Book Name : ";
        cin.getline(st1,50);
        system("cls");
        fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
        intf.seekg(0);
        intf.read((char*)this,sizeof(*this));
        while(!intf.eof())
        {
        for(i=0;b==B&&b_name[i]!='\0'&&st1[i]!='\0'&&(st1[i]==b_name[i]||st1[i]==b_name[i]+32);i++);
        if(b_name[i]=='\0'&&st1[i]=='\0')
        {
           cont++;
           input();
           int pos1 = intf.tellp();
           int pos2 = sizeof(*this);
           int pos = pos1 - pos2;
           intf.seekp(pos);
           intf.write((char*)this,sizeof(*this));
           break;
        }
        intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==2)
    {
        cout<<"\n\t\tENTER BOOK ID : ";
        cin.getline(st1,100);
        system("cls");
        fstream intf("Booksdata.txt",ios::in|ios::out|ios::ate|ios::binary);
        intf.seekg(0);
        intf.read((char*)this,sizeof(*this));
        while(!intf.eof())
        {
           for(i=0;b==B&&b_id[i]!='\0'&&st1[i]!='\0'&&st1[i]==b_id[i];i++);
           if(b_id[i]=='\0'&&st1[i]=='\0')
           {
              cont++;
              input();
              int pos1 = intf.tellp();
              int pos2 = sizeof(*this);
              int pos = pos1 - pos2;
              intf.seekp(pos);
              intf.write((char*)this,sizeof(*this));
              break;
           }
           intf.read((char*)this,sizeof(*this));
           }

           intf.close();
    }
    else
    {
        cout<<"\n\t\tINCORRECT INPUT.....:(\n";
        cout<<"\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        modify();
    }
           if(cont==0)
           {
              cout<<"\n\t\tBOOK NOT FOUND.\n";
              cout<<"\n\t\tPress any key to continue.....";
              getch();
              system("cls");
              modify();
           }
           else
              {
                  cout<<"\n\t\tUPDATE SUCCESSFUL!!!:)\n";
                  getch();
                  system("cls");
                  admin();
              }



}




///  CHECKING STATUS  ///
void Library :: status()
{
    int i=0,r;
    char ch,pass[21];
    cout<<"\n\t\tENTER REGISTRATION NO : ";
    cin>>r;
    cout<<"\n\n\t\tENTER PASSWORD : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        pass[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    }
    Student ob;
    ifstream file("Student.txt",ios::binary);
    file.seekg(0);
    while(!file.eof())
    {
        file.read((char *)&ob,sizeof(ob));
        if(ob.reg_no==r && strcmp(pass,ob.pawd)==0)
        {
            cout<<"\n\n\t\tSIGNED IN SUCCESSFULLY!:)\n\t\t";
            cout<<"\n\t\tPress any key to continue.....\n";
            getch();
            system("cls");
            ifstream fin("Booksdata.txt",ios::binary);
            fin.seekg(0,ios::beg);
                while(fin.read((char*)&obj,sizeof(obj)))
                {
                    if(obj.curr==r)
                    {
                        cout<<"Book issued :-";
                        obj.show(1);
                    }
                }
            fin.close();

        }
    }

}



///  MAIN FUNCTION  ///
int main()
{
    Library obj;
    obj.menu();
    return 0;
}
