#include<iostream>
#include<string>
using namespace std;
class Animal{
    public:
    string name;
    int age;
    string origin;
    void set(string a,int b,string c){
        name=a;
        age=b;
        origin=c;
        cout<<"My name is "<<name<<", I am "<<age<<" years old "<<"and I am from "<<origin<<endl;
    }
};
main(){
    cout<<"Enter the name, the age and place of origin for the Zebra";
    Animal zebra;
    cin>>zebra.name>>zebra.age>>zebra.origin;
    zebra.set(zebra.name,zebra.age,zebra.origin);
    cout<<"Enter the name, the age and place of origin for the Dolphin";
    Animal dolphin;
    cin>>dolphin.name>>dolphin.age>>dolphin.origin;
    dolphin.set(dolphin.name,dolphin.age,dolphin.origin);    
}