#include<iostream>
#include<fstream>
#include<stdlib.h>

#define number 500

using namespace std;

int main()
{


ifstream myfile("number.txt");

int num;
char temp;
int count = 0;

while(myfile>>num)
{
cout<<"Number: "<<num<<endl;
count++;
}

cout<<count<<endl;

myfile.close();


}