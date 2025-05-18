#include<iostream>
using namespace std;
digit_name(int a){
	switch(a){
		case 1:
			cout<<"One";
			break;
		case 2:
			cout<<"Two";
			break;
		case 3:
			cout<<"Three";
			break;
		case 4:
			cout<<"Four";
			break;	
		case 5:
			cout<<"Five";
			break;
		case 9:
			cout<<"Nine";
			break;
		case 6:
			cout<<"Six";
			break;
		case 7:
			cout<<"Seven";
			break;
		case 8:
			cout<<"Eight";
			break;	
		default:
			cout<<"Digit error"<<"\n";													
	}
}
main(){
	int a;
	cout<<"Enter an integer between 1 and 9";
	cin>>a;
	digit_name(a);
}
