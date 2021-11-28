#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "conio2.h"
#include "quiz.h"
using namespace std;

int main()
{

    int type;
    textcolor(LIGHTGREEN);
    gotoxy(25,1);
    for(int i=1; i<=30; i++)
       cout<<"*";
    gotoxy(25,2);
    cout<<"*"<<"     ";
    textcolor(LIGHTBLUE);
    cout<<" QUIZ APPLICATION";
    textcolor(LIGHTGREEN);
    cout<<"      "<<"*";
    gotoxy(25,3);
     for(int i=1; i<=30; i++)
       cout<<"*";


   textcolor(LIGHTGREEN);
    gotoxy(16,7);
    for(int i=1; i<=50; i++)
       cout<<"*";
    gotoxy(16,8);
    cout<<"*"<<"     ";
    textcolor(LIGHTBLUE);
    cout<<"WELCOME TO TECH TEST - QUIZ APPLICATION";
    textcolor(LIGHTGREEN);
    cout<<"    "<<"*";
    gotoxy(16,9);
    for(int i=1; i<=50; i++)
       cout<<"*";


    textcolor(LIGHTGREEN);
    gotoxy(16,11);
    for(int i=1; i<=50; i++)
       cout<<"*";
    gotoxy(16,12);
    cout<<"*"<<"     ";
    textcolor(LIGHTBLUE);
    cout<<"TEST YOUR SKILLS! IMPROVE YOUR KNOWLEDGE !";
    textcolor(LIGHTGREEN);
    cout<<" "<<"*";
    gotoxy(16,13);
    for(int i=1; i<=50; i++)
       cout<<"*";
    gotoxy(25,16);
    cout<<"Press any key to continue.....";
    getch();
    Admin::createAdmin("uadmin","Pawan","abc");
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
       gotoxy(20,12);
              cout<<"*"<<"     ";
       gotoxy(20,13);
              cout<<"*"<<"     ";
       gotoxy(20,14);
              cout<<"*"<<"     ";
       gotoxy(20,15);
              cout<<"*"<<"     ";
       gotoxy(20,16);
              cout<<"*"<<"     ";
       gotoxy(60,8);
              cout<<"*"<<"     ";
       gotoxy(60,9);
              cout<<"*"<<"     ";
       gotoxy(60,10);
              cout<<"*"<<"     ";
       gotoxy(60,11);
              cout<<"*"<<"     ";
       gotoxy(60,12);
              cout<<"*"<<"     ";
       gotoxy(60,13);
              cout<<"*"<<"     ";
       gotoxy(60,14);
              cout<<"*"<<"     ";
       gotoxy(60,15);
              cout<<"*"<<"     ";
       gotoxy(20,16);
       for(int i=20; i<=60; i++)
              cout<<"*";

       gotoxy(23,9);
       textcolor(LIGHTBLUE);
       cout<<"        "<<"1. Admin";
       gotoxy(23,11);
       cout<<"        "<<"2. Student";
       gotoxy(23,13);
       cout<<"        "<<"Select Your Choice: ";
       cin>>type;


       if(type==0)
              break;
       cin.ignore();
       if(type==1)
       {
            Admin adminobj;
            bool c=false;
                       do{
                                c=adminobj.input();
                                 if(c==false)
                                 {
                                     textcolor(LIGHTRED);
                                     gotoxy(25,18);
                                     cout<<"Login cancelled !!!!";
                                     textcolor(LIGHTBLUE);
                                     gotoxy(25,20);
                                     cout<<"Press any key to go back.....";
                                     getch();
                                     break;
                                 }
                                 c=adminobj.checkUserExists("Admin");
                                 if(c==true)
                                 {
                                     textcolor(LIGHTMAGENTA);
                                     gotoxy(30,15);
                                     cout<<"Login Accepted";
                                     textcolor(LIGHTMAGENTA);
                                     gotoxy(30,17);
                                     cout<<"Welcome   "<<adminobj.getName();
                                     getch();
                                     int choice;
                                    do{
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
                                                                             gotoxy(20,5);
                                                                             for(int i=20; i<=60; i++)
                                                                                    cout<<"*";

                                                                             gotoxy(20,6);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,7);
                                                                                    cout<<"*"<<"     ";

                                                                             gotoxy(60,6);
                                                                                    cout<<"*"<<"     ";

                                                                             gotoxy(20,7);
                                                                             for(int i=20; i<=60; i++)
                                                                                    cout<<"*";

                                                                             gotoxy(26,6);
                                                                             textcolor(LIGHTBLUE);
                                                                             cout<<"        "<<"Admin Menu";

                                                                             textcolor(LIGHTGREEN);
                                                                             gotoxy(20,10);
                                                                             for(int i=20; i<=60; i++)
                                                                                    cout<<"*";

                                                                             gotoxy(20,11);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,12);
                                                                                    cout<<"*"<<"     ";
                                                                           gotoxy(20,13);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,14);
                                                                                    cout<<"*"<<"     ";
                                                                            gotoxy(20,15);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,16);
                                                                                    cout<<"*"<<"     ";
                                                                              gotoxy(20,17);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,18);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,19);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,20);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,21);
                                                                                    cout<<"*"<<"     ";

                                                                             gotoxy(60,10);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,11);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,12);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,13);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,14);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,15);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,16);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,17);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,18);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,19);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,20);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,21);
                                                                                    cout<<"*"<<"     ";
                                                                            gotoxy(60,22);
                                                                                    cout<<"*"<<"     ";

                                                                             gotoxy(20,22);
                                                                             for(int i=20; i<=60; i++)
                                                                                    cout<<"*";

                                                                             textcolor(LIGHTBLUE);
                                                                             gotoxy(31,12);
                                                                                    cout<<"1."<<" Add Question";
                                                                             gotoxy(31,13);
                                                                                    cout<<"2."<<" Add Student";
                                                                             gotoxy(31,14);
                                                                                    cout<<"3."<<" Show Questions";
                                                                             gotoxy(31,15);
                                                                                    cout<<"4."<<" Show Student";
                                                                             gotoxy(31,16);
                                                                                    cout<<"5."<<" Remove Question";
                                                                             gotoxy(31,17);
                                                                                    cout<<"6."<<" Remove Student";
                                                                             gotoxy(31,18);
                                                                                    cout<<"7."<<" Exit";
                                                                             gotoxy(31,20);
                                                                                    cout<<"Enter Choice:";
                                                                             cin>>choice;

                                                                             switch(choice)
                                                                             {
                                                                             case 1:
                                                                                           adminobj.addQuestion();
                                                                                           break;
                                                                              case 2:
                                                                                           adminobj.addStudent();
                                                                                           break;
                                                                              case 3:
                                                                                           adminobj.viewQuestion();
                                                                                           break;
                                                                             case 4:
                                                                                           adminobj.viewStudent();
                                                                                           break;
                                                                             case 5:
                                                                                           adminobj.removeQuestion();
                                                                                           break;
                                                                             case 6:
                                                                                           adminobj.removeStudent();
                                                                                           break;
                                                                            case 7:
                                                                                           clrscr();
                                                                                           break;
                                                                            default:
                                                                                           textcolor(LIGHTRED);
                                                                                           gotoxy(31,24);
                                                                                              cout<<"Wrong Choice. Try again !!!";
                                                                                           getch();

                                                                             }
                                                           if(choice==7)
                                                               break;
                                                 }while(1);
                            break;
                            }
              }while(c==false);
       }
       else if(type==2)
       {
            Student stuobj;
            bool c=false;
                       do{
                                c=stuobj.input();
                                 if(c==false)
                                 {
                                     textcolor(LIGHTRED);
                                     gotoxy(25,18);
                                     cout<<"Login cancelled !!!!";
                                     textcolor(LIGHTBLUE);
                                     gotoxy(25,20);
                                     cout<<"Press any key to go back.....";
                                     getch();
                                     break;
                                 }
                                 c=stuobj.checkUserExists("Student");
                                 if(c==true)
                                 {
                                     textcolor(LIGHTMAGENTA);
                                     gotoxy(30,15);
                                     cout<<"Login Accepted";
                                     textcolor(LIGHTMAGENTA);
                                     gotoxy(30,17);
                                     cout<<"Welcome "<<stuobj.getName();
                                     getch();
                                     int choice;
                                    do{
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
                                                                             gotoxy(26,5);
                                                                             for(int i=1; i<=30; i++)
                                                                                    cout<<"*";

                                                                             gotoxy(26,6);
                                                                                    cout<<"*";
                                                                             gotoxy(55,6);
                                                                                 cout<<"*";



                                                                             gotoxy(26,7);
                                                                             for(int i=1; i<=30; i++)
                                                                                    cout<<"*";

                                                                             gotoxy(27,6);
                                                                             textcolor(LIGHTBLUE);
                                                                             cout<<"        "<<"Student Menu";


                                                                             textcolor(LIGHTGREEN);
                                                                             gotoxy(20,10);
                                                                             for(int i=20; i<=60; i++)
                                                                                    cout<<"*";

                                                                             gotoxy(20,11);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,12);
                                                                                    cout<<"*"<<"     ";
                                                                           gotoxy(20,13);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,14);
                                                                                    cout<<"*"<<"     ";
                                                                            gotoxy(20,15);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,16);
                                                                                    cout<<"*"<<"     ";
                                                                              gotoxy(20,17);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(20,18);
                                                                                    cout<<"*"<<"     ";


                                                                             gotoxy(60,10);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,11);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,12);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,13);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,14);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,15);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,16);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,17);
                                                                                    cout<<"*"<<"     ";
                                                                             gotoxy(60,18);
                                                                                    cout<<"*"<<"     ";


                                                                             gotoxy(20,18);
                                                                             for(int i=20; i<=60; i++)
                                                                                    cout<<"*";

                                                                             textcolor(LIGHTBLUE);
                                                                             gotoxy(31,12);
                                                                                    cout<<"1."<<" Start Quiz";
                                                                             gotoxy(31,13);
                                                                                    cout<<"2."<<" View Performance";
                                                                             gotoxy(31,14);
                                                                                    cout<<"3."<<" Exit";

                                                                             gotoxy(31,16);
                                                                                    cout<<"Enter Choice:";

                                                                             cin>>choice;

                                                                             switch(choice)
                                                                             {
                                                                             case 1:
                                                                                           stuobj.quiz();
                                                                                           break;
                                                                              case 2:
                                                                                           stuobj.viewPerformence();
                                                                                           break;
                                                                              case 3:
                                                                                           clrscr();
                                                                                           break;

                                                                            default:
                                                                                           textcolor(LIGHTRED);
                                                                                           gotoxy(31,24);
                                                                                              cout<<"Wrong Choice. Try again !!!";
                                                                                           getch();
                                                                             }
                                                           if(choice==3)
                                                               break;
                                                 }while(1);
                            break;
                            }
              }while(c==false);
       }else
       {
                                 textcolor(LIGHTRED);
                                 gotoxy(23,13);
                                 cout<<"\t\t\t\t\t";
                                 gotoxy(30,13);
                                 cout<<"Invalid User Type !!!!";
                                 textattr(WHITE);
                                 getch();
       }
    }while((type!=1 | type!=2));
    return 0;
}

