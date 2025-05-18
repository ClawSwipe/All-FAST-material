#include <iostream>
using namespace std;
zero_small(int *a, int *b){
	if(*a<*b){
		*a=0;
	}
	else{
		*b=0;
	}
	
}
main(){
	cout<<"Enter two integers";
	int a,b;
	cin>>a>>b;
	cout<<"The numbers are"<<endl<<"Number 1:"<<a<<"\tNumber 2:"<<b<<endl;
	zero_small(&a,&b);
	cout<<"The smallest number is now 0"<<endl<<"The numbers are now"<<endl<<"Number 1:"<<a<<"\tNumber 2:"<<b;
}
			
