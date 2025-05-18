#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
main(){
	srand(time(0));
	cout<<"Enter the rows and columns of your array";
	int row,col;
	cin>>row>>col;
	int arr[row][col];
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j]=rand()%10+1;
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<"\t"<<arr[i][j];
		}
		cout<<"\n";
	}
	cout<<"Transposed:\n";
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){
			cout<<"\t"<<arr[j][i];
		}
		cout<<"\n";
	}	
		
	
}
