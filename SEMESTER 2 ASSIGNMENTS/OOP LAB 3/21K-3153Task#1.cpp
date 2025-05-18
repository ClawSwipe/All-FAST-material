#include<iostream>
#include<string>
using namespace std;
class User{
    public:
    int age;
    string name;
};
main(){
    cout<<"Enter your name and your age";
    User me;
    cin>>me.name>>me.age;
    cout<<"My name is "<<me.name<<" and I am "<<me.age<<" years old.";
}