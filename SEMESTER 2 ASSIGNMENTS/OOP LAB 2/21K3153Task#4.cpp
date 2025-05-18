#include<iostream>
using namespace std;
eliminate_duplicates(int arr[],int *a){
	for(int i=0;i<*a;i++){
		for(int j=i+1;j<*a;j++){
			while(arr[i]==arr[j]){
				for(int d=j;d<*a;d++){
					arr[d]=arr[d+1];
				}
				*a=*a-1;
			}
		}
	}
}
main(){
	int a;
	cout<<"How many numbers are there in your array?";
	cin>>a;
	int c=a;
	int arr[a];
	for(int i=0;i<a;i++){
		cout<<"Enter values for your array";
		cin>>arr[i];
	}
	eliminate_duplicates(arr,&a);
	for(int i=0;i<a;i++){
		cout<<"\t"<<arr[i];
	}
	cout<<"\t Number of elements: "<<a;
	}
