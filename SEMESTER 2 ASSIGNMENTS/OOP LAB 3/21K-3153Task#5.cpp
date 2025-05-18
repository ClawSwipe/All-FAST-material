#include<iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Book{
	public:
	string name;
	string ISBN;
	string author;
	string publisher;
	void getBookinfo(Book b[],int j){
		int i;
		for(i=0;i<j;i++){
			cout<<"The name of the book is "<<b[i].name<<". The ISBN number is "<<b[i].ISBN<<". The author is "<<b[i].author<<". The publisher is "<<b[i].publisher<<endl;
		}
	}
};
main(){
	Book b[5];
	for(int i=0;i<5;i++){
		cin>>b[i].name>>b[i].ISBN>>b[i].author>>b[i].publisher;
	}
	b[0].getBookinfo(b,5);
}
