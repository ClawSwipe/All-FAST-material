#include<iostream>
using namespace std;
typedef struct{
	char name[50];
	int rollno;
	float GPA;
}students;
main(){
	int num;
	cout<<"How many students do you want to scan?";
	cin>>num;
	students std[num];
	for(int i=0;i<num;i++){
		cout<<"Enter the name of student "<<i+1;
		cin>>std[i].name;
		cout<<"Enter the roll number of student "<<i+1;
		cin>>std[i].rollno;
		cout<<"Enter the GPA of student "<<i+1;
		cin>>std[i].GPA;				
	}
	cout<<"\n";
	for(int i=0;i<num;i++){
		cout<<" The name of student "<<i+1<<" is "<<std[i].name<<endl;

		cout<<"The roll number of student "<<i+1<<" is 21K-"<<std[i].rollno<<endl;

		cout<<"The GPA of student "<<i+1<<" is "<<std[i].GPA<<endl;
				
	}	
}
