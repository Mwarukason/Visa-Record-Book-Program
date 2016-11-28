#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Student.h"

using namespace std;

void Add(vector<Student>&);//adding students into the system
void print(vector<Student>&);//viewing all records in the system
void menu();//menu display
int Search(vector<Student>&);//search for a record using passport number as primary key
void Delete(vector<Student>&);//delete a record
void Edit(vector<Student>&);//edit a record
void visaStatus(vector<Student>&);//checking if visa shuld be renewed or not
void printInfo(vector<Student>&,int);//view info of a particular student
void SaveFile(vector<Student>&);//saving info in a vector as binary file
void ReadFile(int);//reading from the binary file
bool checkPass(vector<Student>&,char*,int);//checking if passport number already exist
bool _validate(char*);//validating name, country,course nd college not to contain numbers
bool numValidate(char*);//validating if it is a number
bool passValidate(char*);//validating if passport is alphanum
bool AttValidate(bool);//check if attendance is a number
bool MarkValidate(bool);

const int NotUsed = system( "color 1A" );//changing background colour 1: blue    A: green
int main()
{
     char ans,choice;
    vector<Student> myStudents;//instantiating an instance of a vector of type Student
    cout.setf(ios::fixed | ios:: showpoint);
    cout.precision(2);
    char msg[20] = "\n.....WELCOME...!";
    for(unsigned int i=0; i<strlen(msg); i++){
      cout <<msg[i] << "\a";
      Sleep(500);
   }
   Sleep(500);
   do{
        menu();
        cin>>choice;
        choice = toupper(choice);
        system("cls");
        switch(choice)
    {
        case '1':  Add(myStudents);
                   break;
        case '2':  print(myStudents);
                   break;
        case '3':  Search(myStudents);
                   break;
        case '4':  Edit(myStudents);
                   break;
        case '5':  Delete(myStudents);
                   break;
        case '6':  SaveFile(myStudents);
                   break;
        case '7':  ReadFile(myStudents.size());
                  break;
        case '8': cout<<"Checking visa status.....\n";
                  visaStatus(myStudents);
                  break;
        case 'Q': cout<<"Exiting.....\n";
                   exit(1);
                   break;
        default : cout<<"Invalid input\n"; //continue;
                   //break;

    }
    cout<<"Do you wish to return to Main Menu: (Y/N) ";
    cin>>ans;
    ans = toupper(ans);
    system("cls");
   }while(ans=='Y');
    return 0;
}
void Add(vector<Student>& mystudent)
{
    const int size =30;
     char studName[size];
    char country[size];
    char passNum[size];
    char course[50];
    char college[50];
    float attendance,cgpa;
    char num[10];

        cin.ignore();
        int nums;
       while(true)
      {
          bool adv;
          cout<<"How many students you wish to add: ";
          cin.getline(num,10);
          adv = numValidate(num);
          if(adv==true)
          {
            nums = atoi(num);
              break;
          }
          endl(cout);
      }
    for(int i=0;i<nums;i++)
    {
        bool adv;

        while(true)
        {
             cout<<"Enter student name: ";
             cin.getline(studName,size);
              adv = _validate(studName);
             if(adv==true) break;
             endl(cout);
        }
        while(true)
        {
            cout<<"Enter student country: ";
            cin.getline(country,size);
            adv = _validate(country);
             if(adv==true) break;
             endl(cout);
        }
        while(true)
        {bool fail;
            cout<<"Enter passport number: ";
            cin.getline(passNum,size);
            adv = passValidate(passNum);
          fail = checkPass(mystudent,passNum,size);
            if(adv==true && fail==true)
                break;
            endl(cout);
        }

        while(true)
        {
           cout<<"Enter student course: ";
           cin.getline(course,50);
           adv = _validate(course);
           if(adv==true) break;
           endl(cout);
        }
        while(true)
        {
           cout<<"Enter student college: ";
           cin.getline(college,50);
           adv = _validate(college);
           if(adv==true) break;
        }

       while(true)
       {
           bool fail;
           cout<<"Enter student attendance: ";
           cin>>attendance;
           fail= cin.fail();//if user inputs a float or integer..cin.fail returns false otherwise true
           adv = AttValidate(fail);
           if(adv==true) break;
           endl(cout);

       }
       //cin.ignore();
       while(true)
       {
           bool fail;
           cout<<"Enter student CGPA: ";
           cin>>cgpa;
           fail= cin.fail();
           adv=MarkValidate(fail);
           if(adv==true) break;
           endl(cout);

       }
        //A:
        Student newStudent(studName,country,passNum,course,college,attendance,cgpa);
        mystudent.push_back(newStudent);
        cin.ignore();
        endl(cout);
    }
   endl(cout);
}
void print(vector<Student>& mystudent)
{
    if(mystudent.empty()) cout<<"No records in the system\n";
    else
{
        for(unsigned int i=0;i< mystudent.size();i++)
    {
        cout<<"Student Name: "<< mystudent[i].getName()<<endl
            <<"Student Country: "<< mystudent[i].getCountry()<<endl
            <<"Student Passport Number: "<< mystudent[i].getPassNum()<<endl
            <<"Student Course: "<< mystudent[i].getCourse()<<endl
            <<"Student College: "<< mystudent[i].getCollege()<<endl
            <<"Student Attendance: "<< mystudent[i].getAttendance()<<endl
            <<"Student CGPA: "<< mystudent[i].getCgpa()<<endl;
            endl(cout);

        endl(cout);
    }
}
}
void menu()
{
     system("cls");
    cout << "\t\t+-------------------------------------+" << endl;
    cout << "\t\t| INTERNATIONAL STUDENT-VISA DEPARTMENT" << endl;
    cout << "\t\t|=====================================|" << endl;
    cout << "\t\t| Select:                             |" << endl;
    cout << "\t\t| 1 => Add records                    |" << endl;
    cout << "\t\t| 2 => View All Records               |" << endl;
    cout << "\t\t| 3 => Search for a Record            |" << endl;
    cout << "\t\t| 4 => Edit Record                    |" << endl;
    cout << "\t\t| 5 => Delete Record                  |" << endl;
    cout << "\t\t|-------------------------------------|" << endl;
    cout << "\t\t| 6 => Save File                      |" << endl;
    cout << "\t\t| 7 => Read From File                 |" << endl;
    cout << "\t\t| 8 => Check Visa Status              |" << endl;
    cout << "\t\t|-------------------------------------|" << endl;
    cout << "\t\t| Q => Quit                           |" << endl;
    cout << "\t\t+-------------------------------------+" << endl;
    cout << endl;
    cout << "Choice => ";

}
int Search(vector<Student>& mystudent)
{
    int targetIndex=-1;//flag
    if(mystudent.empty()) cout<<"Sorry! No records in the system\n";
    else
    {
        char ans;
        bool adv;
        char targetPass[30];
        do {
         cin.ignore();
     while(true)
        {
            cout<<"Enter the passport Number of the record to look for: ";
            cin.getline(targetPass,30);
            adv = passValidate(targetPass);
            if(adv==true) break;
            endl(cout);
        }
    bool found=false;


   for(unsigned int i=0;i<mystudent.size();i++)
    {
            if(strncmp(mystudent[i].getPassNum(),targetPass,30)==0)//strncmp(a,b) compares a nd b

           {
               found = true;
               targetIndex = i;

           }
        }
        if(!found) cout<<"Sorry..No match for that passport number\n";
      else
      {
          cout<<"Passport number "<<targetPass<<" found "<<endl;
                printInfo(mystudent,targetIndex);
      }

        cout<<"Do you want to search for another record (Y/N): ";
            cin>>ans;
            ans=toupper(ans);
       system("cls");
     }while(ans=='Y');
}
  return targetIndex;

}
void Delete(vector<Student>& mystudent)
{
    char ans;
    if(mystudent.empty()) cout<<"Sorry! No records in the system\n";
    else
    {
        do
            {
                int x =Search(mystudent);
                if(x >=0)
                {
                    cout<<"Are you sure you want to delete:(Y/N) ";
                    cin>>ans;
                    ans=toupper(ans);
                     if(ans=='Y')
         {
              mystudent.erase(mystudent.begin()+x);
              cout<<"Record deleted\n";
         }
         else
               return;
                }

        cout<<"Do you wish to delete another record: (Y/N) ";
                cin>>ans;
                ans = toupper(ans);
            }while(ans=='Y');

    }
}
void Edit(vector<Student>& mystudent)
{
    if(mystudent.empty()) cout<<"Sorry! No records in the system\n";
    else
    {     char choice;
        do{
        int x =Search(mystudent);
        if(x >= 0)

            {
                const int size =30;
                char studName[size];
                char country[size];
                char passNum[size];
                char course[50];
                char college[50];
                float attendance,cgpa;
               char choice,ans,ans1;

            cin.ignore();
            cout <<"Changes will be saved permanently.. Are you sure you want to edit(Y/N): ";
            cin>>ans1;
            ans1=toupper(ans1);
            if(ans1!='Y') return;
            else
            {
                do{
        cout<<"Select the option you wish to edit: \n"
            <<"<1>: Name\n"
            <<"<2>: Country\n"
            <<"<3>: Passport Number\n"
            <<"<4>: Course Name\n"
            <<"<5>: College Name\n"
            <<"<6>: Attendance\n"
            <<"<7>: CGPA\n";
        cin>>ans;
        cin.ignore();
        system("cls");
        bool adv;
        switch(ans)
        {
            case '1': while(true){
                      cout<<"Enter new name: ";
                       cin.getline(studName,size);
                       adv = _validate(studName);
                        if(adv) break;
                        endl(cout);
                       }
                       mystudent[x].setName(studName);
                        cout<<"Record Updated\n";//specify wat has been updated
                        printInfo(mystudent,x);
                       break;
            case '2':  while(true)
                       {
                        cout<<"Enter student country: ";
                        cin.getline(country,size);
                        adv = _validate(country);
                       if(adv==true) break;
                       endl(cout);
                     }
                      mystudent[x].setCountry(country) ;
                     cout<<"Record Updated\n";
                     printInfo(mystudent,x);
                      break;
            case '3':
                      while(true)
                     {
                      cout<<"Enter passport number: ";
                      cin.getline(passNum,size);
                      adv = passValidate(passNum);
                     if(adv==true) break;
                      endl(cout);
                     }
                     mystudent[x].setPassNum(passNum);
                     cout<<"Record Updated\n";
                     printInfo(mystudent,x);
                      break;
            case '4': while(true)
                      {
                        cout<<"Enter student course: ";
                        cin.getline(course,50);
                        adv = _validate(course);
                       if(adv==true) break;
                       endl(cout);
                     }
                    mystudent[x].setCourse(course);
                    cout<<"Record Updated\n";
                    printInfo(mystudent,x);
                      break;
            case '5': while(true)
                     {
                       cout<<"Enter student course: ";
                       cin.getline(course,50);
                      adv = _validate(course);
                     if(adv==true) break;
                     endl(cout);
                    }
                    mystudent[x].setCollege(college);
                    cout<<"Record Updated\n";
                    printInfo(mystudent,x);
                    break;
            case '6': while(true)
                      {
                        bool fail;
                        cout<<"Enter student attendance: ";
                        cin>>attendance;
                        fail= cin.fail();//if user inputs a float or integer..cin.fail returns false otherwise true
                        adv = AttValidate(fail);
                       if(adv==true) break;
                       endl(cout);
                     }
                     mystudent[x].setAttendance(attendance);
                     cout<<"Record Updated\n";
                     printInfo(mystudent,x);
                     break;
            case '7':  while(true)
                       {
                        bool fail;
                       cout<<"Enter student CGPA: ";
                       cin>>cgpa;
                       fail= cin.fail();
                       adv=MarkValidate(fail);
                      if(fail) break;
                      endl(cout);
                      }
                        mystudent[x].setCgpa(cgpa);
                        cout<<"Record Updated\n";
                        printInfo(mystudent,x);
                      break;
            default: cout<<"Invalid Input\n";
                      break;
        }
        cout<<"Do you wish to continue editing: (Y/N) ";
        cin>>choice;
        choice = toupper(choice);
         system("cls");
        }while(choice=='Y');
        }
     }
     cout<<"Do you wish to edit another record (Y/N):";
     cin>>choice;
     choice=toupper(choice);
    }while(choice=='Y');

    }

}
void visaStatus(vector<Student>& mystudent)
{
    char ans;
    if(mystudent.empty()) cout<<"Sorry! No records in the system\n";

    else
    {
        do
     {
         int x = Search(mystudent);
        if(mystudent[x].getAttendance() < 80.00 && mystudent[x].getCgpa() < 2.00)
        cout<<"Visa for Passport Number "<< mystudent[x].getPassNum()<< " cannot be renewed\n";
         else
        cout<<"Visa for Passport Number "<< mystudent[x].getPassNum()<< " approved..\n";

    cout<<"Do you wish to continue checking Visa Status: (Y/N) ";
    cin>>ans;
    ans = toupper(ans);
    system("cls");
    }while(ans=='Y');

    }

}
void printInfo(vector<Student>& mystudent,int targetIndex)
{
    char ans;
    //system("cls");
    cout<<"Do you want to view information about this record..(Y/N): ";
                cin>>ans;
                ans=toupper(ans);

                if(ans=='Y')
                {

                   cout<<"Name: "<< mystudent[targetIndex].getName()<<endl;
                   cout<<"Country: "<< mystudent[targetIndex].getCountry()<<endl;
                   cout<<"Passport Number: " << mystudent[targetIndex].getPassNum()<<endl;
                   cout<<"Course: "<< mystudent[targetIndex].getCourse()<<endl;
                   cout<<"College: "<< mystudent[targetIndex].getCollege()<<endl;
                   cout<<"Attendance: "<< mystudent[targetIndex].getAttendance()<<endl;
                   cout<<"CGPA: "<< mystudent[targetIndex].getCgpa()<<"\n\n";

               }
               else
                    return;
}
void SaveFile(vector<Student>&mystudent)
{
    if(mystudent.empty()) cout<<"Sorry...No Information to save\n";
    else
    {

        fstream file("Visa.bin",ios:: out |ios::binary | ios:: trunc);
           if(!file.is_open())
             cout<<"Error while opening file\n";
         else
        {
        file.write((char*)&mystudent,sizeof(Student)*(mystudent.size()));
        file.seekg(0);
        cout<<"FILE SAVED..\n";
        file.close();
        }
    }

}
void ReadFile(int x)
{
     vector<Student> student_2(x);
    fstream file("Visa.bin", ios::in | ios::binary);
           if(!file.is_open())
             {cout<<"Error while opening file\n";
               exit(1);
             }
         else
         {
           file.read((char*)&student_2,sizeof(Student)*x);
           file.close();
         }
         //testing if information was read to student_2
         for(int i=0;i <student_2.size(); i++)
         print(student_2);


}
bool _validate(char* x)
{
    bool check =true;
    try{
        for(int i=0; i< strlen(x); i++)
       {
        if(!isalpha(x[i]))
        {
            check = false;
            throw check;
        }
       }
    }
    catch(bool)
    {
        cout<<"Invalid input...Please enter characters only\n";
    }

  return check;
}
bool numValidate(char* var)
{
    bool check =true;
    try{
     for(int i=0;i < strlen(var); i++)
    {
        if(!isdigit(var[i]))
        {
            check = false;
            throw check;
        }
    }
  }
  catch(bool)
  {
      cout<<"Invalid input..Please enter only digits:\n";
  }
  return check;
}
bool AttValidate(bool x)
{
    bool check =true;
    try
     {
        if(x==true)
        {
            check = false;
            cin.clear();
            cin.ignore(1000,'\n');// clear out the bad input from the stream
            throw 7;
        }

    }
    catch(int)
    {
        cout<<"Invalid Input..Please enter a number\n"
            <<"Attendance must be between <0.0 - 100.0> only\n";

    }
    return check;
}
bool MarkValidate(bool x)
{
    bool check =true;
    try
     {
        if(x==true)
        {
            check = false;
            cin.clear();
            cin.ignore(1000,'\n');
            throw 7;
        }

    }
    catch(int)
    {
        cout<<"Invalid Input..Please enter a number\n"
            <<"CGPA must be between <0.0 - 4.0> only\n";

    }
    return check;
}
bool passValidate(char* var)
{
    bool check = true;
    try
    {
        for(int i=0; i< strlen(var); i++)
        {
            if(!isalnum(var[i]))
            {
                check = false;
                throw check;
            }
        }
    }
    catch(bool)
    {
        cout<<"Invalid input..Please enter letters or digits\n";
    }
   return check;
}
bool checkPass(vector<Student>& mystudent,char* pass,int x)
{
    bool check = true;
    try{
    for(unsigned int i=0;i < mystudent.size(); i++)
    {
        if(strncmp(mystudent[i].getPassNum(),pass,x)==0)
        {
            check = false;

                throw 7;
        }
    }
    }
    catch(int)
    {
        cout<<"Passport number: "<<pass<<" is for another record\n"
            <<"Please verify and enter the correct number\n";
    }
  return check;
}


