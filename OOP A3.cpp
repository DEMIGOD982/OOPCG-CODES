/*
Imagine a publishing company which does marketing for book 
and audio cassette versions. Create a class publication that stores the title (a string) 
and price (type float) of a publication. From this class derive two classes: book, which adds a page 
count (type int), and tape, which adds a playing time in minutes (type float). 
Write a program that instantiates the book and tape classes, 
allows user to enter data and displays the data members. If 
an exception is caught, replace all the data member values with zero values.
*/
#include <iostream>
#include <string>
using namespace std; 

class Publication
{ 
 public:
 string name; 
 float price; 
 void Name()
 { 
 cout << "Book name: " ; 
 cin >> name;cout << endl; 
 } 
 void Price()
 { 
 cout << "Book Price: "; 
 cin >> price;cout << endl; 
 } 
 virtual void detail() = 0; 
 virtual void display() = 0; 
};

class Book: public Publication
{ 
 public:
 float pages; 
 int temp,x; 
 
 void detail()
 { 
 cout << "Page count: " ; 
 cin >> pages;cout << endl; 
 temp = pages; 
 try
 { 
 if (temp!=pages) 
 { 
 throw x; 
 } 
 else
 { 
 name=name; 
 price=price; 
 pages=pages; 
 } 
 
 
 } 
 
 catch(int x) 
 { 
 name="--"; 
 price=0; 
 pages=0; 
 cout<<"Please enter right details! "<<endl; 
 
 } 
 }

 void display()
 { 
 cout<<"book name :"<<name<<endl; 
 cout<<"book price :"<<price<<endl; 
 cout<<"page count :"<<pages<<endl; 
 cout<<endl; 
 
 } 
};

class Tape: public Publication
{ public:
 float time; 
 int temp,x; 
 void detail()
 { 
 cout << "Duration : "; 
 cin >> time;cout << endl; 
 temp = time; 
 
 try
 { 
 
 if (temp!=time) 
 { 
 throw x; 
 } 
 else
 { 
 name=name; 
 price=price; 
 time=time; 
 } 
 
 
 } 
 
 catch(int x) 
 { 
 name="--"; 
 price=0; 
 time=0; 
 cout<<"Please enter right details! "<<endl; 
 } 
 
 
 } 
 void display(){
 cout<<"Name :"<<name<<endl; 
 cout<<"Price :"<<price<<endl; 
 cout<<"Time :"<<time<<endl; 
 cout<<endl; 
 } 
 
};

int main()
{ 
 Book A; 
 Tape B; 
 int ch; 
 do { 
 cout << "Enter 1 for Book " << endl; 
 cout << "Enter 2 for Tape " << endl; 
 cout << "Enter 3 to Exit " << endl; 
 cout << "Enter choice : "; 
 cin >> ch; 
 cout << endl; 
 switch(ch) 
 { 
 case(1) 
 :{
 A.Name();
 A.Price();
 A.detail();
 A.display();
 break; 
 } 
 case(2):{
 B.Name();
 B.Price();
 B.detail();
 B.display();
 break; 
 } 
 case(3) 
 :{
 return 0; 
 } 
 } 
 }while(ch != 3);
}
