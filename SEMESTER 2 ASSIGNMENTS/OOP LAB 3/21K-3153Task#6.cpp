#include<iostream>
#include <string>
using namespace std;
class Result{
	public:
	int rollno;
	string name;
	int marks;
	void input(Result R[],int j){
		for(int i=0;i<j;i++){
			cout<<"Enter rollno, name and marks"<<endl;
			cin>>R[i].rollno>>R[i].name>>R[i].marks;
		}
	}
	void show(Result R[],int j){
		for(int i=0;i<j;i++){
			cout<<"Roll no: "<<R[i].rollno<<"\t Name: "<<R[i].name<<"\t Marks: "<<R[i].marks<<endl;
		}
	}
	void total(Result R[],int j){
		int tot=0;
		for(int i=0;i<j;i++){
			tot+=R[0].marks;
		}
		cout<<"The total marks are "<<tot<<endl;
	}
	int average(Result R[],int j){
		int avg=0,tot=0;
		for(int i=0;i<j;i++){
			tot+=R[0].marks;
		}
		avg=tot/3;
		cout<<"The average marks are "<<avg<<endl;

	}	
	
};
main(){
	Result R[3];
	R[0].input(R,3);
	R[0].show(R,3);
	R[0].total(R,3);
	R[0].average(R,3);
	
}
