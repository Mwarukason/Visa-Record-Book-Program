#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Student
{
    char studName[30];
    char country[30];
    char passNum[30];
    char course[50];
    char college[50];
             float attendance,cgpa;
    public:
        Student();//default constructor
         Student(char*,char*,char*,char*,char*,float,float);//overloaded constructor

        //accessors functions to access private members
        char* getName();//get name and return name
        void setName(char []);
        char* getCountry();
        void setCountry(char []);
        char* getPassNum();
        void setPassNum(char []);
        char* getCourse();
        void setCourse(char []);
        char* getCollege();
        void setCollege(char []);
        float getAttendance();
        void setAttendance(float);
        float getCgpa();
        void setCgpa(float);
       ~Student();



};

#endif // STUDENT_H
