#include "Student.h"//information part of student header
Student::Student(){};

Student::Student(char*studName,char*country,char*passNum,char*course,char*college,float attendance,float cgpa)
{
    //this-> studName=studName;
    strcpy(this->studName,studName);
    strcpy(this->country,country);
    strcpy(this->passNum,passNum);
    strcpy(this->course,course);
    strcpy(this->college,college);
    this->attendance=attendance;
    this->cgpa=cgpa;

}

char* Student::getName(){

   return studName;
}

char* Student::getCountry(){

   return country;
}

char* Student::getPassNum(){

   return passNum;
}

char* Student::getCourse(){

   return course;
}

char* Student::getCollege(){

   return college;
}

float Student::getAttendance(){

   return attendance;
}

float Student::getCgpa(){

   return cgpa;
}
void Student:: setName(char studName[30])
{
    strcpy(this->studName,studName);
}
void Student:: setCountry(char country[30])
{
   strcpy(this->country,country);
}
void Student:: setPassNum(char passNum[30])
{
    strcpy(this->passNum,passNum);
}
void Student:: setCourse(char course[50])
{
    strcpy(this->course ,course);
}
void Student:: setCollege(char college[50])
{
    strcpy(this->college,college);
}
void Student:: setAttendance(float attendance)
{
    this->attendance = attendance;
}
void Student:: setCgpa(float cgpa)
{
    this->cgpa = cgpa;
}
Student::~Student(){};
