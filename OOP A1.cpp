/*
Implement a class Complex which represents the Complex 
Number data type. Implement the following 
1. Constructor (including a default constructor which 
creates the complex number 0+0i). 
2. Overloaded operator+ to add two complex numbers. 
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.
*/

#include<iostream>
using namespace std; 
class Complex{ 
public:
 float x, y;
 Complex()
 { 
 x = 0; 
 y = 0; 
 } 
 Complex operator+(Complex);
 Complex operator*(Complex);

 friend istream &operator >>(istream &input, Complex &t)
 {
 cout<<"Enter real part "; 
 input>>t.x; 
 cout<<"Enter imaginary part "; 
 input>>t.y; 
 } 
 friend ostream &operator << (ostream &output, Complex &t)
 {
 output<<t.x<<"+"<<t.y<<"i"; 
 } 
};
Complex Complex::operator+(Complex c){
 Complex temp; 
 temp.x= x + c.x; 
 temp.y= y + c.y; 
 return temp;
} 
Complex Complex::operator*(Complex c){
 Complex temp2; 
 temp2.x= x*c.x - y*c.y; 
 temp2.y= x*c.y + y*c.x;
 return temp2; 
} 
int main(){ 
 Complex c1,c2,c3,c4; 
 cout<<"Default value of complex: "<<c1<<"\n"; 
 cout<<"\nEnter complex number 1: \n"; 
 cin>>c1; 
 cout<<"\nEnter complex number 2: \n"; 
 cin>>c2; 
 c3=c1+c2; 
 c4=c1*c2; 
 cout<<"\nAddition: "<<c3; 
 cout<<"\nMultiplication: "<<c4; 
}
