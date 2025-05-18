#include<iostream>
using namespace std;
main(){
	int table[8][8]={{1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0},{1,0,1,0,0,0,0,0},{1,1,1,1,0,0,0,0,},{1,0,0,0,1,0,0,0},{1,1,0,0,1,1,0,0},{1,0,1,0,1,0,1,0},{1,1,1,1,1,1,1,1}};
	string b1,b2;
	int a=0,b=0;
	cout<<"Please enter the donor's blood group (Please be case specific)";
	cin>>b1;
	cout<<"Please enter the recipeint's blood group (Please be case specific)";
	cin>>b2;
	(b1=="O-")?(a=0):(b1=="O+")?(a=1):(b1=="A-")?(a=3):(b1=="A+")?(a=4):(b1=="B-")?(a=5):(b1=="B+")?(a=6):(b1=="AB-")?(a=6):(b1=="AB+")?(a=7):a=-1;
	(b2=="O-")?(b=0):(b2=="O+")?(b=1):(b2=="A-")?(b=3):(b2=="A+")?(b=4):(b2=="B-")?(b=5):(b2=="B+")?(b=6):(b2=="AB-")?(b=6):(b2=="AB+")?(b=7):b=-1;
	if(table[a][b]==1){
		cout<<"Blood transfusion possible";
	}
	else{
		cout<<"Blood transfusion not possible";
	}


	
}
