#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "quiz.h"
#include "conio2.h"
using namespace std;

bool User::input()
{
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(26,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(26,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<" QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"      "<<"*";
       gotoxy(26,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       gotoxy(58,1);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);
       gotoxy(20,7);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(20,8);
              cout<<"*"<<"     ";
       gotoxy(20,9);
              cout<<"*"<<"     ";
       gotoxy(20,10);
              cout<<"*"<<"     ";
       gotoxy(20,11);
              cout<<"*"<<"     ";


       gotoxy(60,8);
              cout<<"*"<<"     ";
       gotoxy(60,9);
              cout<<"*"<<"     ";
       gotoxy(60,10);
              cout<<"*"<<"     ";
       gotoxy(60,11);
              cout<<"*"<<"     ";

      gotoxy(20,12);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(23,9);
       textcolor(LIGHTBLUE);
       cout<<"        "<<"Enter UserId: ";
       gotoxy(45,9);
       cin.getline(userId,20);

       if(strcmp(userId,"0")==0)
              return false;

       gotoxy(23,10);

       textcolor(LIGHTBLUE);
       cout<<"        "<<"Enter Password: ";

    char ch;
    int i=0;
    while(1)
    {
       ch=getch();
       if(ch==13)
        {
              break;
        }
        if(ch==8)
        {
               if(i==0)
                  continue;
               cout<<"\b \b";
               i--;
               continue;
        }
        cout<<ch;
        delay(200);
        cout<<"\b*";
        pwd[i]=ch;
        i++;
     }
     pwd[i]='\0';
     if(strcmp(pwd,"0")==0)
        return false;
     return true;
}


void User::setUserDetails(string userId,string name,string pwd)
{
    strcpy(this->userId,userId.c_str());
    strcpy(this->userName,name.c_str());
    strcpy(this->pwd,pwd.c_str());
}

void Admin::createAdmin(string userId,string name,string pwd)
{
       fstream fobj("Admin.bin",ios::in | ios::binary);
       if(fobj.fail())
       {
            fobj.open("Admin.bin",ios::out|ios::binary);
            Admin adminUser;
            adminUser.setUserDetails(userId,name,pwd);
            fobj.write((char*)&adminUser,sizeof(Admin));
            cout<<"File created!"<<endl;
            getch();
       }
       fobj.close();
}






bool User::checkUserExists(string usertype)
{
      if(strcmp(userId,"0")==0 || strcmp(pwd,"0")==0)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Both fields are mandatory";
              getch();
              return 0;
      }
      ifstream fin;
      User* uptr;

      if(usertype=="Admin")
      {
             fin.open("Admin.bin",ios::in|ios::binary);
             uptr=new Admin;

      }else if(usertype=="Student")
      {
             fin.open("Student.bin",ios::in|ios::binary);
             uptr=new Student;
      }else
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Invalid User Type!!";
              getch();
              return 0;
      }

      bool userIdFound=false;
      bool userpwdFound=false;

      while(1)
      {
             fin.read((char*)uptr,sizeof(*uptr));
             if(fin.eof())
               break;
             if(strcmp(userId,uptr->userId)==0)
             {
                    userIdFound=true;
                    if(strcmp(pwd,uptr->pwd)==0)
                    {
                           userpwdFound=true;
                           break;
                    }
             }
      }
      bool result=false;
      if(userIdFound==false)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"No such User exists!!!";
              getch();
              return 0;
      }
      else if(userIdFound&&userpwdFound==false)
      {
              gotoxy(30,17);
              textcolor(LIGHTRED);
              cout<<"Invalid Password!!!";
              getch();
              return 0;
      }
      else
      {
             strcpy(userName,uptr->userName);
             result=true;
      }
      fin.close();
     return result;
}

string User::getName()
{
     string name(userName);
     return name;
}

string User::getUserId()
{
       string userid(userId);
       return userid;
}

string User::getName(string id)
{
      ifstream fin("Student.bin",ios::in|ios::binary);
      if(!fin)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return "";
      }
      while(1)
      {
             fin.read((char*)this,sizeof(*this));
             if(fin.eof())
             {
                break;
             }
             if(strcmp(id.c_str(),this->userId)==0)
             {
                    string name(this->userName);
                    fin.close();
                    return name;
             }
      }
      fin.close();
      return  "";
}


bool isPresent(vector<int>& index,int num)
{
       for(int i=0; i<index.size(); i++)
       {
              if(index[i]==num)
                 return true;
       }
       return false;
}

void Admin::addQuestion()
{
       Question obj;
       obj.add();
       clrscr();
}

void Question::add()
{
      fstream fobj("Question.bin",ios::app|ios::binary|ios::in);
      if(!fobj)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }
      fobj.seekg(0,ios::end);

      if(fobj.tellg()==0)
         qesId=1;
      else
      {
           fobj.seekg(-1*sizeof(*this),ios::end);
           fobj.read((char*)this,sizeof(*this));
           qesId++;
      }

      char choice;

      do
      {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(26,1);
              for(int i=1; i<=30; i++)
              cout<<"*";
              gotoxy(26,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<" QUIZ APPLICATION";
              textcolor(LIGHTGREEN);
              cout<<"      "<<"*";
              gotoxy(26,3);
              for(int i=1; i<=30; i++)
              cout<<"*";


              textcolor(LIGHTGREEN);
              gotoxy(26,5);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
                     cout<<"*"<<"     ";
              gotoxy(26,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(26,8);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<"*";
              textcolor(LIGHTBLUE);
              cout<<"     "<<"Add Question Menu";

            textcolor(LIGHTBLUE);

            string str;

            gotoxy(1,10);
               cout<<"     Enter Question: ";

           cin.ignore();

           getline(cin,str,'*');

           if(strcmp(str.c_str(),"0")==0)
           {
                     textcolor(LIGHTRED);
                     gotoxy(1,24);
                     cout<<"Closing add Question...";
                     getch();
                     break;
           }

           strncpy(ques,str.c_str(),499);

           gotoxy(1,12);
               cout<<"     Carries Marks: ";
            cin>>totalMarks;

            gotoxy(1,14);
               cout<<"     OPTIONS";

            gotoxy(6,16);
               cout<<"(a)";
            gotoxy(10,16);
             cin.ignore();
                getline(cin,str);
            strncpy(op1,str.c_str(),99);

            gotoxy(6,17);
               cout<<"(b)";
            gotoxy(10,17);
                getline(cin,str);
            strncpy(op2,str.c_str(),99);

            gotoxy(6,18);
               cout<<"(c)";
            gotoxy(10,18);
                getline(cin,str);
            strncpy(op3,str.c_str(),99);

           gotoxy(6,19);
               cout<<"(d)";
            gotoxy(10,19);
                getline(cin,str);
            strncpy(op4,str.c_str(),99);


          while(1)
          {
                  gotoxy(6,22);
                  textcolor(LIGHTBLUE);
                  gotoxy(6,22);
                      cout<<"Enter Correct ans(a/b/c/d): \b";
                  cin>>ans;
                  if(ans=='a' || ans=='b' || ans=='c' || ans=='d')
                  {
                         break;
                  }
                  else{
                         textcolor(LIGHTRED);
                         gotoxy(6,24);
                         cout<<"Invalid option entered. Please choose the correct option​";
                         getch();
                         gotoxy(6,24);
                         cout<<"\t\t\t\t\t\t\t\t";

                  }
          }
       fobj.write((char*)this,sizeof(*this));
       gotoxy(6,24);
       textcolor(LIGHTGREEN);
       cout<<"Quesion Added successfully";
       textcolor(LIGHTBLUE);
       gotoxy(6,26);
       cout<<"Do you want to add more question (Y/N):";
       cin>>choice;
       qesId++;
      }while(choice=='y' || choice=='Y');
      fobj.close();
}



void Admin :: viewQuestion()
{
       Question obj;
       obj.viewQuestion();
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(24,3);
       for(int i=1; i<=32; i++)
       cout<<"*";
       gotoxy(24,4);
       cout<<"*"<<"   ";
       textcolor(LIGHTBLUE);
       cout<<"No More Question Present.";
       textcolor(LIGHTGREEN);
       cout<<"  "<<"*";
       gotoxy(24,5);
       for(int i=1; i<=32; i++)
            cout<<"*";
       getch();
}

void Question :: viewQuestion()
{
    ifstream fin("Question.bin",ios::in | ios::binary);
    if(!fin)
    {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No question present!!";
            getch();
            return;
    }
      fin.seekg(0,ios::beg);



      while(1)
      {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(26,1);
              for(int i=1; i<=30; i++)
              cout<<"*";
              gotoxy(26,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<" QUIZ APPLICATION";
              textcolor(LIGHTGREEN);
              cout<<"      "<<"*";
              gotoxy(26,3);
              for(int i=1; i<=30; i++)
              cout<<"*";


              textcolor(LIGHTGREEN);
              gotoxy(26,5);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
                     cout<<"*"<<"     ";
              gotoxy(26,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(26,8);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<"*";
              textcolor(LIGHTBLUE);

              cout<<"  "<<"SHOW QUESTION DETAILS";

         fin.read((char*)this,sizeof(*this));

         if(fin.eof())
         {
               break;
         }
         else
         {
                this->show();
                getch();
         }
      }
}


void Question::show()
{
       textcolor(LIGHTBLUE);
       gotoxy(6,10);
       cout<<"Q."<<this->qesId<<" ";
       gotoxy(11,10);
       cout<<this->ques;
       gotoxy(6,13);
       cout<<"Carries marks: "<<this->totalMarks;
       gotoxy(6,15);
       cout<<"a. "<<this->op1;
       gotoxy(6,16);
       cout<<"b. "<<this->op2;
       gotoxy(6,17);
       cout<<"c. "<<this->op3;
       gotoxy(6,18);
       cout<<"d. "<<this->op4;
       gotoxy(6,20);
       textcolor(LIGHTBLUE);
       cout<<"Correct Option is: "<<this->ans;
}



void Admin :: removeQuestion()
{
      Question obj;
      obj.Remove();
      clrscr();
}

void Question :: Remove()
{
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(26,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(26,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<" QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"      "<<"*";
       gotoxy(26,3);
       for(int i=1; i<=30; i++)
       cout<<"*";



       textcolor(LIGHTGREEN);
       gotoxy(26,5);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
              cout<<"*"<<"     ";
       gotoxy(26,7);
              cout<<"*"<<"     ";

       gotoxy(55,6);
              cout<<"*"<<"     ";
       gotoxy(55,7);
              cout<<"*"<<"     ";

       gotoxy(26,8);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
       cout<<"*";
       textcolor(LIGHTBLUE);
       cout<<"     "<<"Remove Question Menu";

       textcolor(LIGHTGREEN);
       gotoxy(20,10);
       for(int i=15; i<=55; i++)
              cout<<"*";

       gotoxy(20,11);
              cout<<"*"<<"     ";
       gotoxy(20,12);
              cout<<"*"<<"     ";

       gotoxy(60,11);
              cout<<"*"<<"     ";
       gotoxy(60,12);
              cout<<"*"<<"     ";

       gotoxy(58,1);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);

       gotoxy(20,13);
       for(int i=15; i<=55; i++)
              cout<<"*";

       textcolor(LIGHTBLUE);
       gotoxy(26,11);
       cout<<" Enter Question Id: ";

       ifstream fin("Question.bin",ios::in | ios::binary);

       if(!fin)
       {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }

      fin.seekg(0,ios::end);
      if(fin.tellg()==0)
      {
            gotoxy(26,24);
            textcolor(LIGHTBLUE);
            cout<<"No More Question Present....";
            getch();
            return;
      }
      fin.seekg(0,ios::beg);

      ofstream fout("temp.bin",ios::out|ios::binary);
      if(!fout)
      {
            gotoxy(26,24);
            textcolor(LIGHTRED);
            cout<<"Sorry! removal not possible!";
            getch();
            return;
      }

      int id;
      bool valid=true;
      bool found=false;
      do
      {
           textcolor(LIGHTBLUE);
           valid=true;
           gotoxy(46,11);

           cout<<"\t\t";
           gotoxy(46,11);
           cin>>id;
           if(id == 0)
           {
                  fin.close();
                  fout.close();
                  remove("temp.bin");
                  return;
           }
           if(id < 0)
           {
                 textcolor(LIGHTRED);
                 gotoxy(28,16);
                 cout<<"ID Can't be negative!!!!";
                 getch();
                 gotoxy(28,16);
                 cout<<"\t\t\t\t\t\t\t";
           }
           else
           {
                   while(1)
                   {
                          fin.read((char*)this,sizeof(*this));
                          if(fin.eof())
                              break;
                          if(id == this->qesId)
                          {
                                 found=true;
                                 continue;
                          }else{
                                 fout.write((char*)this,sizeof(*this));
                          }
                   }
                   fin.close();
                   fout.close();
                   if(found)
                   {
                        textcolor(LIGHTGREEN);
                        gotoxy(28,16);
                        cout<<"Question removed Successfully!!!";
                        getch();
                        remove("Question.bin");
                        rename("temp.bin","Question.bin");
                        return;
                   }
                   else
                   {
                        textcolor(LIGHTRED);
                        gotoxy(28,16);
                        cout<<"Invalid Question ID!!!";
                        getch();
                        gotoxy(28,16);
                        cout<<"\t\t\t\t\t\t\t";
                        remove("temp.bin");
                   }
           }
      }while(valid);
      getch();
}



void Admin::addStudent()
{
       Student obj;
       obj.add();
       clrscr();
}

void Student::add()
{
     int id;
     char stuId[20];
     string str;

     fstream fobj("Student.bin",ios::app|ios::binary|ios::in);
      if(!fobj)
      {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }
      fobj.seekg(0,ios::end);
      if(fobj.tellg()==0)
         id=1;
      else
      {
           fobj.seekg(-1*sizeof(*this),ios::end);
           fobj.read((char*)this,sizeof(*this));
           char* pos=strchr(userId,'-');
           if(pos!=NULL)
           {
                  id=atoi(pos+1);
                  id++;
           }
      }
      char choice;
      fobj.seekg(0,ios::end);
      do
      {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(26,1);
              for(int i=1; i<=30; i++)
              cout<<"*";
              gotoxy(26,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<" QUIZ APPLICATION";
              textcolor(LIGHTGREEN);
              cout<<"      "<<"*";
              gotoxy(26,3);
              for(int i=1; i<=30; i++)
              cout<<"*";


              textcolor(LIGHTGREEN);
              gotoxy(26,5);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
                     cout<<"*"<<"     ";
              gotoxy(26,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(26,8);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<"*";
              textcolor(LIGHTBLUE);
              cout<<"     "<<"Add Student Menu";

              textcolor(LIGHTBLUE);
              gotoxy(1,10);
                 cout<<"     Enter student name: ";

            textcolor(LIGHTBLUE);

           cin.ignore();
           getline(cin,str);
           strncpy(userName,str.c_str(),49);

           if(strcmp(userName,"0")==0)
           {
                     textcolor(LIGHTRED);
                     gotoxy(1,24);
                     cout<<"Closing add Question...";
                     getch();
                     fobj.close();
                     break;
           }

           gotoxy(6,12);
               cout<<"Enter Student Password: ";

          textcolor(LIGHTBLUE);
           getline(cin,str);
           strncpy(pwd,str.c_str(),19);
           if(strcmp(pwd,"0")==0)
           {
                     textcolor(LIGHTRED);
                     gotoxy(6,21);
                     cout<<"Closing add Question...";
                     getch();
                     fobj.close();
                     break;
           }

          sprintf(stuId,"STU-%d",id);
          strcpy(userId,stuId);

          fobj.write((char*)this,sizeof(*this));
          gotoxy(6,14);
          textcolor(LIGHTGREEN);
          cout<<"Student Added successfully";
          getch();
          textcolor(LIGHTBLUE);
          gotoxy(6,16);
          cout<<"Do you want to add more Student (Y/N):";
          cin>>choice;
          id++;
       }while(choice=='y' || choice=='Y');
       fobj.close();
}




void Admin :: viewStudent()
{
       Student obj;
       obj.showStudentDetails();
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(24,3);
       for(int i=1; i<=32; i++)
       cout<<"*";
       gotoxy(24,4);
       cout<<"*"<<"   ";
       textcolor(LIGHTBLUE);
       cout<<"No More Student Present.";
       textcolor(LIGHTGREEN);
       cout<<" "<<"*";
       gotoxy(24,5);
       for(int i=1; i<=32; i++)
       cout<<"*";
       getch();
}

void Student :: showStudentDetails()
{
    ifstream fin("Student.bin",ios::in | ios::binary);
    if(!fin)
    {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No Student present!!";
            getch();
            return;
    }
    fin.seekg(0,ios::beg);
    while(1)
    {
              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(26,1);
              for(int i=1; i<=30; i++)
              cout<<"*";
              gotoxy(26,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<" QUIZ APPLICATION";
              textcolor(LIGHTGREEN);
              cout<<"      "<<"*";
              gotoxy(26,3);
              for(int i=1; i<=30; i++)
              cout<<"*";


              textcolor(LIGHTGREEN);
              gotoxy(26,5);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
                     cout<<"*"<<"     ";
              gotoxy(26,7);
                     cout<<"*"<<"     ";

              gotoxy(55,6);
                     cout<<"*"<<"     ";
              gotoxy(55,7);
                     cout<<"*"<<"     ";

              gotoxy(26,8);
              for(int i=20; i<=49; i++)
                     cout<<"*";

              gotoxy(26,6);
              cout<<"*";
              textcolor(LIGHTBLUE);

              cout<<"  "<<"SHOW STUDENT DETAILS";

              fin.read((char*)this,sizeof(*this));
              if(fin.eof())
              {
                     break;
              }
              else
              {
                 show();
                 getch();
              }
      }
}

void User::show()
{
       textcolor(LIGHTBLUE);
       gotoxy(6,10);
       cout<<"Student Id: "<<userId;
       gotoxy(6,12);
       cout<<"Student Name: "<<userName;
       gotoxy(6,14);
       cout<<"Student Password: "<<pwd;
}

void Admin :: removeStudent()
{
      Student obj;
      obj.Remove();
      clrscr();
}

void Student :: Remove()
{
       string str;
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(26,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(26,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<" QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"      "<<"*";
       gotoxy(26,3);
       for(int i=1; i<=30; i++)
       cout<<"*";



       textcolor(LIGHTGREEN);
       gotoxy(26,5);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
              cout<<"*"<<"     ";
       gotoxy(26,7);
              cout<<"*"<<"     ";

       gotoxy(55,6);
              cout<<"*"<<"     ";
       gotoxy(55,7);
              cout<<"*"<<"     ";

       gotoxy(26,8);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
       cout<<"*";
       textcolor(LIGHTBLUE);
       cout<<"     "<<"Remove Student Menu";

       textcolor(LIGHTGREEN);
       gotoxy(20,10);
       for(int i=15; i<=55; i++)
              cout<<"*";

       gotoxy(20,11);
              cout<<"*"<<"     ";
       gotoxy(20,12);
              cout<<"*"<<"     ";

       gotoxy(60,11);
              cout<<"*"<<"     ";
       gotoxy(60,12);
              cout<<"*"<<"     ";

       gotoxy(58,1);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);

       gotoxy(20,13);
       for(int i=15; i<=55; i++)
              cout<<"*";

       textcolor(LIGHTBLUE);
       gotoxy(26,11);

       cout<<" Enter Studnet Id:";

       ifstream fin("Student.bin",ios::in | ios::binary);
       if(!fin)
       {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
      }
      fin.seekg(0,ios::end);
      if(fin.tellg()==0)
      {
            gotoxy(26,24);
            textcolor(LIGHTGRAY);
            cout<<"No More Student Present....";
            getch();
            return;
      }
      fin.seekg(0,ios::beg);

      ofstream fout("temp.bin",ios::out|ios::binary);
      if(!fout)
      {
            gotoxy(26,24);
            textcolor(LIGHTRED);
            cout<<"Sorry! removal not possible!";
            getch();
            return;
      }
      bool valid=true;

      bool found=false;

     cin.ignore();

      do
      {
           textcolor(LIGHTBLUE);
           gotoxy(45,11);
           cout<<"\t\t";
           valid=true;
           gotoxy(45,11);

           getline(cin,str);

           if(str == "0")
           {
                  fin.close();
                  fout.close();
                  remove("temp.bin");
                  return;
           }
           if(str.size() < 3)
           {
                 textcolor(LIGHTRED);
                 gotoxy(27,16);
                 cout<<"ID Must have 3 characters !!!";
                 getch();
                 gotoxy(27,16);
                 cout<<"\t\t\t\t\t\t\t";
           }
           else
           {
                   while(1)
                   {
                          fin.read((char*)this,sizeof(*this));
                          if(fin.eof())
                              break;
                          if(strcmp(this->userId,str.c_str())==0)
                          {
                                 found=true;
                                 continue;
                          }else{
                                 fout.write((char*)this,sizeof(*this));
                          }
                   }
                   fin.close();
                   fout.close();
                   if(found)
                   {
                        textcolor(LIGHTGREEN);
                        gotoxy(27,16);
                        cout<<"Student removed Successfully!!!";
                        getch();
                        remove("Student.bin");
                        rename("temp.bin","Student.bin");
                        return;
                   }
                   else
                   {
                        textcolor(LIGHTRED);
                        gotoxy(27,16);
                        cout<<"Invalid Student Id !!!";
                        getch();
                        gotoxy(27,16);
                        cout<<"\t\t\t\t\t\t\t";
                        remove("temp.bin");
                   }
           }

      }while(valid);
      getch();
}


void Student :: quiz()
{
    Question quesObj;
    quesObj.startQuiz(userId);
    clrscr();
}

void Question::startQuiz(string id)
{
    ifstream fin("Question.bin",ios::in | ios::binary);
    if(!fin)
    {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
    }
    fin.seekg(0,ios::end);
    if(fin.tellg()==0)
    {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No question present!!";
            getch();
            return;
    }
   fin.seekg(0,ios::beg);
   vector<Question> allQuestions;

   while(1)
    {
         fin.read((char*)this,sizeof(*this));
         if(fin.eof())
              break;
         allQuestions.push_back(*this);
    }
    fin.close();

    vector<int> randQues;
    srand((unsigned int)time(NULL));
    int randNum=0;
    while(1)
    {
           randNum=(rand()%allQuestions.size());
           if(isPresent(randQues,randNum)==1)
               continue;
           randQues.push_back(randNum);
           if(randQues.size() == allQuestions.size())
              break;
    }

    User uObj;
    string userName=uObj.getName(id);
    int local_total_marks=0;
    int local_marks=0;

    for(int indx=0; indx<allQuestions.size(); indx++)
    {
             *this=allQuestions[randQues[indx]];

              clrscr();
              textcolor(LIGHTGREEN);
              gotoxy(26,1);
              for(int i=1; i<=30; i++)
              cout<<"*";
              gotoxy(26,2);
              cout<<"*"<<"     ";
              textcolor(LIGHTBLUE);
              cout<<" QUIZ APPLICATION";
              textcolor(LIGHTGREEN);
              cout<<"      "<<"*";
              gotoxy(26,3);
              for(int i=1; i<=30; i++)
              cout<<"*";

              textcolor(LIGHTGREEN);
              gotoxy(20,5);
              for(int i=20; i<=60; i++)
                     cout<<"*";

              gotoxy(20,6);
                     cout<<"*"<<"     ";
              gotoxy(20,7);
                     cout<<"*"<<"     ";
              gotoxy(20,8);
                     cout<<"*"<<"     ";
              gotoxy(20,9);
                     cout<<"*"<<"     ";


              gotoxy(60,6);
                     cout<<"*"<<"     ";
              gotoxy(60,7);
                     cout<<"*"<<"     ";
              gotoxy(60,8);
                     cout<<"*"<<"     ";
              gotoxy(60,9);
                     cout<<"*"<<"     ";

             gotoxy(20,9);
              for(int i=20; i<=60; i++)
                     cout<<"*";

              gotoxy(23,6);
              textcolor(LIGHTBLUE);
              cout<<"    "<<"Student Name: "<<userName;
              gotoxy(23,7);
              textcolor(LIGHTBLUE);
              cout<<"    "<<"Total Questions: "<<allQuestions.size();


              gotoxy(6,11);
              cout<<"Q."<<(indx+1)<<" "<<this->ques;
              gotoxy(6,13);
              cout<<"Carries marks: "<<this->totalMarks;
              gotoxy(6,15);
              cout<<"a. "<<this->op1;
              gotoxy(6,16);
              cout<<"b. "<<this->op2;
              gotoxy(6,17);
              cout<<"c. "<<this->op3;
              gotoxy(6,18);
              cout<<"d. "<<this->op4;
              gotoxy(6,20);
              textcolor(LIGHTBLUE);

            char uans;

            bool valid=false;
            do
            {
                   gotoxy(6,22);
                   textcolor(LIGHTBLUE);
                   cout<<"Enter your option(a/b/c/d):  \b";
                   cin>>uans;
                   if(uans>='a' && uans<='d')
                      break;
                   else
                   {
                        gotoxy(6,24);
                        textcolor(LIGHTRED);
                        cout<<"Select the correct answer from the choices a/b/c/d";
                        getch();
                        gotoxy(6,24);
                        cout<<"\t\t\t\t\t\t\t\t\t\t";
                   }
            }while(valid==false);

            local_total_marks+=this->totalMarks;

            if(this->ans==uans)
            {
                   local_marks+=this->totalMarks;
            }
     }

     textcolor(LIGHTGREEN);
     gotoxy(6,25);
     cout<<"Test finished";
     StudentPerformance stuPerObj;
     stuPerObj.setMarksDetails(id,local_marks,local_total_marks);
     getch();
}


void StudentPerformance::setMarksDetails(string id,int marks,int total_marks)
{
       strcpy(this->stuId,id.c_str());
       this->marks=marks;
       this->totalMarks=total_marks;
       this->saveMarksDetails();
}

void StudentPerformance::saveMarksDetails()
{
      ofstream fout("Performance.bin",ios::app|ios::binary);
      fout.write((char*)this,sizeof(*this));
      fout.close();
}

void Student::viewPerformence()
{
       string id;
       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(26,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(26,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<" QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"      "<<"*";
       gotoxy(26,3);
       for(int i=1; i<=30; i++)
       cout<<"*";

       textcolor(LIGHTGREEN);
       gotoxy(20,5);
       for(int i=15; i<=55; i++)
              cout<<"*";

       gotoxy(20,6);
              cout<<"*"<<"     ";
       gotoxy(20,7);
              cout<<"*"<<"     ";

       gotoxy(60,6);
              cout<<"*"<<"     ";
       gotoxy(60,7);
              cout<<"*"<<"     ";

       gotoxy(58,1);
       textcolor(WHITE);
       cout<<"Press 0 to Exit/Go back";

       textcolor(LIGHTGREEN);

       gotoxy(20,8);
       for(int i=15; i<=55; i++)
              cout<<"*";

       textcolor(LIGHTBLUE);
       gotoxy(26,6);


       cout<<" Enter Studnet Id: ";
       cin.ignore();

      getline(cin,id);
      StudentPerformance stuPerObj;
      stuPerObj.viewDetails(id);
      clrscr();
}



void StudentPerformance::viewDetails(string id)
{
        int testNo=1;
        ifstream fin("Performance.bin",ios::in | ios::binary);
        if(!fin)
        {
            gotoxy(1,24);
            textcolor(LIGHTRED);
            cout<<"File can not be opened!";
            getch();
            return;
       }
       fin.seekg(0,ios::end);
       if(fin.tellg()==0)
       {
            gotoxy(1,24);
            textcolor(LIGHTGRAY);
            cout<<"No Record present!!";
            getch();
            return;
       }

       fin.seekg(0,ios::beg);

       clrscr();
       textcolor(LIGHTGREEN);
       gotoxy(26,1);
       for(int i=1; i<=30; i++)
       cout<<"*";
       gotoxy(26,2);
       cout<<"*"<<"     ";
       textcolor(LIGHTBLUE);
       cout<<" QUIZ APPLICATION";
       textcolor(LIGHTGREEN);
       cout<<"      "<<"*";
       gotoxy(26,3);
       for(int i=1; i<=30; i++)
       cout<<"*";


       textcolor(LIGHTGREEN);
       gotoxy(26,5);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
              cout<<"*"<<"     ";
       gotoxy(26,7);
              cout<<"*"<<"     ";

       gotoxy(55,6);
              cout<<"*"<<"     ";
       gotoxy(55,7);
              cout<<"*"<<"     ";

       gotoxy(26,8);
       for(int i=20; i<=49; i++)
              cout<<"*";

       gotoxy(26,6);
       cout<<"*";
       textcolor(LIGHTBLUE);
       cout<<"     "<<"View Report Card";

       gotoxy(35,10);
       User obj;
       textcolor(LIGHTMAGENTA);
       string name=obj.getName(id);
       cout<<name<<endl;

       textcolor(LIGHTBLUE);

       gotoxy(1,12);
       for(int i=1; i<=80; i++)
              cout<<"-";

       gotoxy(2,13);
       cout<<"TEST NO.               |";

       gotoxy(35,13);
       cout<<"MARKS OBTAINED            |";

       gotoxy(69,13);
       cout<<"TOTAL MARKS";

       gotoxy(1,14);
       for(int i=1; i<=80; i++)
              cout<<"-";

       gotoxy(1,15);

       while(1)
       {
              fin.read((char*)this,sizeof(*this));
              if(fin.eof())
              {
                     break;
              }

              if(strcmp(id.c_str(),this->stuId)==0)
              {
                 this->show(testNo);
              }
      }

      if(testNo==1)
      {
             gotoxy(26,24);
             cout<<"No Record Found !!!";
      }
      else
      {
             gotoxy(26,24);
             cout<<"No More Records";
      }
      getch();
}


void StudentPerformance::show(int& testNo)
{
       textcolor(LIGHTBLUE);
       cout<<"   "<<testNo;
       textcolor(LIGHTGREEN);
       cout<<"                                 "<<this->marks;
       textcolor(LIGHTBLUE);
       cout<<"                          "<<totalMarks<<endl;
       testNo++;
}




