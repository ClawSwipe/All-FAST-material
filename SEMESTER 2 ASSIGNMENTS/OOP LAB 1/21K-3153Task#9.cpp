#include<iostream>
using namespace std;
main(){
	cout<<"Enter the number of days";
	int days;
	cin>>days;
	int years;
	years=days/365;
	int day2;
	day2=days%365;
	int months=day2/30;
	int day3=day2%30;
	cout<<"Years:"<<years<<"  Months:"<<months<<"  Days:"<<day3;
}
