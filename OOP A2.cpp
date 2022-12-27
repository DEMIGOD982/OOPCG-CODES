/*
Develop an object oriented program in C++ to create a database of student information system
containing the following information: Name, Roll number,Class, division, Date of Birth, Blood group,
Contact address, telephone number, driving license no. andother. Construct the database with
suitable member functions for initializing and destroying the data viz constructor,
default constructor, Copy constructor, destructor, static member functions, friend class,
this pointer, inline code and dynamic memory allocation operators-new and delete.
*/

#include <iostream>
#include <string>
using namespace std;
class per_info
{
    string lic, dob, bldgrp;

public:
    per_info();
    per_info(per_info &obj);
    ~per_info()
    {
        cout << "Destructor called" << endl;
    }
    friend class student;
};
class student
{
    string name, address, Class;
    char div;
    int roll_no;
    long mob;
    static int cnt;

public:
    void create(per_info &);
    void display(per_info &);

    inline static void increment_cnt()
    {
        cnt++;
    }
    inline static void show_cnt()
    {
        cout << "Total No. of Records are: " << cnt << endl;
    }
    student();
    student(student &);
    ~student()
    {
        cout << "Destructor called" << endl;
    }
};

int student::cnt;
student::student()
{
    name = "Sunil Kumawat";
    address = "Hadapsar, PUNE";
    Class = "SE Computer";
    div = 'B';
    roll_no = 21042;
    mob = 942329999;
}
per_info::per_info()
{
    lic = "ABD12345";
    dob = "06/06/2003";
    bldgrp = "O+";
}
student::student(student &obj)
{
    this->name = obj.name;
    this->address = obj.address;
    this->Class = obj.Class;
    this->div = obj.div;
    this->roll_no = obj.roll_no;
    this->mob = obj.mob;
}
per_info::per_info(per_info &obj)
{
    lic = obj.lic;
    dob = obj.dob;
    bldgrp = obj.bldgrp;
}
void student::create(per_info &obj)
{
    cout << endl;
    cout << "Name : " << endl;
    cin >> name;
    cout << "Address : " << endl;
    cin >> address;
    cout << "Date of Birth : " << endl;
    cin >> obj.dob;
    cout << "Class : " << endl;
    cin >> Class;
    cout << "Division : " << endl;
    cin >> div;
    cout << "Roll No. : " << endl;
    cin >> roll_no;
    cout << "Blood group : " << endl;
    cin >> obj.bldgrp;
    cout << "License Number : " << endl;
    cin >> obj.lic;
    cout << "Phone Number : " << endl;
    cin >> mob;
    cout << endl;
}

void student::display(per_info &obj)
{
    cout << endl;
    cout << "Name : " << name << endl;
    cout << "Address : " << address << endl;
    cout << "Date of birth : " << obj.dob << endl;
    cout << "Class : " << Class << endl;
    cout << "division : " << div << endl;
    cout << "Roll No. : " << roll_no << endl;
    cout << "Blood group : " << obj.bldgrp << endl;
    cout << "License Number : " << obj.lic << endl;
    cout << "Phone Number : " << mob << endl;
    cout << endl;
}
int main()
{
    int n;
    int choice;
    char condition;

    cout << "Enter Number of Students :" << endl;
    cin >> n;
    student *sobj = new student[n];
    per_info *pobj = new per_info[n];

    do
    {
        cout << "\n Menu \n 1. Create Database \n 2. Display Databse \n 3. Copy Constructor\n 4. Default Constructor \n 5. Delete(Destructor) "; 
            cout
             << "\n Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                sobj[i].create(pobj[i]);
                sobj[i].increment_cnt();
            }
        }
        break;
        case 2:
        {
            sobj[0].show_cnt();
            for (int i = 0; i < n; i++)
            {
                sobj[i].display(pobj[i]);
            }
        }
        break;
        case 3:
        {
            student obj1;
            per_info obj2;
            obj1.create(obj2);
            student obj3(obj1);

            per_info obj4(obj2);
            cout << "Copy Constructor is called ";
            obj3.display(obj4);
        }
        break;
        case 4:
        {
            student obj1;
            per_info obj2;
            cout << "Default Constructor is called ";
            obj1.display(obj2);
        }
        break;
        case 5:
        {
            delete[] sobj;
            delete[] pobj;
        }
        }
        cout << "\n Want to continue:(y/n)";
        cin >> condition;
    } while (condition == 'y');
    return 0;
}
