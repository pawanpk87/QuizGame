#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED
#include <vector>
using namespace std;
class User
{
protected:
       char userId[20];
       char pwd[20];
       char userName[50];
public:
       void setUserDetails(string ,string , string);
       string getName(string);
       string getUserId();
       bool checkUserExists(string);
       void show();
       bool input();
       string getName();
};

class Student : public User
{
public:
      void add();
      void Remove();
      void showStudentDetails();
      void quiz();
      void viewPerformence();
};

class Admin : public User
{
public:
       static void createAdmin(string,string,string);
       void addStudent();
       void removeStudent();
       void viewStudent();
       void addQuestion();
       void removeQuestion();
       void viewQuestion();
};

class Question
{
private:
    int qesId;
    int totalMarks;
    char ques[500],op1[100],op2[100],op3[100],op4[100],ans;
public:
       void add();
       void Remove();
       void setQuestionDetails(int,char*,char*,char*,char*,char*,char);
       void show();
       void viewQuestion();
       void startQuiz(string);
       int quesCount();
};


class StudentPerformance
{
private:
       char stuId[10];
       int marks,totalMarks;
public:
       void setMarksDetails(string,int,int);
       void viewDetails(string);
       void show(int&);
       void saveMarksDetails();
};

bool isPresent(vector<int>&,int);


#endif // QUIZ_H_INCLUDED
