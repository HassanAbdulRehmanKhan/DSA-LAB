#include<iostream>
using namespace std;
int main(){
	string name;
	do{
		cout<<"Enter  name =";
		getline(cin,name);
		cout<<"You Entered : "<<name<<'\n';
	
		
	}
		while(name!="goodbye");
}
