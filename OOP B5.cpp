/*Write a function template selection Sort. Write a program 
that inputs, sorts and 
outputs an integer array and a float array.*/

#include<iostream>
using namespace std; 
int n; 
#define size 10
template<class T>

void sel(T A[size])
{ 
 int i,j; 
 T temp; 

 for(i=0;i<n-1;i++)
 { 
 for(j=i+1;j<n;j++)
 { 
 if(A[j]<A[i]){
 temp=A[i];
 A[i]=A[j];
 A[j]=temp; 
 } 
 } 
 } 
 cout<<"\nSorted array:"; 
 for(i=0;i<n;i++)
 { 
 cout>>A[i];
 } 
} 

int main()
{ 
 int A[size];
 float B[size];
 int i,n; 
 cout<<"\nEnter total no of int elements:"; 
 cin>>n; 
 cout<<"\nEnter int elements:"; 
 for(i=0;i<n;i++)
 { 
 cin>>A[i];
 } 
 sel(A);

 cout<<"\nEnter total no of float elements:"; 
 cin>>n; 
 cout<<"\nEnter float elements:"; 
 for(i=0;i<n;i++)
 { 
 cin>>B[i];
 }
 sel(B);
 
 cout<<"\nSorted array:"; 
 for(i=0;i<n;i++)
 { 
 cin>>A[i];
 } 
 return 0; 
}
