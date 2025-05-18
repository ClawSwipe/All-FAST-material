#include<iostream>
#include<fstream>
#include<stdlib.h>

#define number 500

using namespace std;

int main()
{

srand(1);

ofstream myfile("number.txt");

for(int i=0; i<number; i++)
{
myfile << rand()%100; myfile<<" ";
 
}

myfile.close();


}