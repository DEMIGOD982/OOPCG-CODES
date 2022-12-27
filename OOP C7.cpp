/*
write a program in C++ to use map associative container. The keys will be the names of states, 
and the values will be the populations of the states. When the program runs, the user is prompted 
to type the name of a state. The program then looks in the map, using the state name as an index, 
and returns the population of the state.
*/
#include<iostream>
#include<map>
#include<string>
using namespace std; 
int main(){ 
 map<string, int> pm; 
 
 pm.insert(pair<string,int>("Maharashtra",1330));
 pm.insert(pair<string,int>("Rajasthan",900)); 
 pm.insert(pair<string,int>("Goa",1200)); 
 pm.insert(pair<string,int>("Bihar",900));
 pm.insert(pair<string,int>("TamilNadu",500)); 
 
 map<string, int>::iterator i; 
 
 cout<<"Size of population map: "<<pm.size()<<"\n"; 
 
 for(i=pm.begin();i!=pm.end();i++){        //To display the state names & population 
 cout<<i->first<<": "<<i->second<<" million\n"; 
 } 
 while(true){
 string state; 
 cout<<"Enter state name to check population: "; 
 cin>>state; 
 
 i=pm.find(state);
 if(i!=pm.end())
 cout<<state<<"'s population is "<<i->second<<" million.\n"; 
 else
 cout<<"key is not in population\n"; 
 
 pm.clear();
 } 
}
