#include<iostream>
using namespace std;
void initialize(int *x,int *y,char *z){
    *x=0;
    *y=0;
    *z=32;
    cout<<"The new values of x, y and z are: "<<"\nx:"<<*x<<"\ny:"<<*y<<"\nz: "<<*z<<endl;
}
void getHoursRate(int *hours,int *rateperhour){
    cout<<"Input the hours worked and the rate per hour";
    int h,r;
    cin>>h>>r;
    *hours=h;
    *rateperhour=r;
}
int payCheck(int hours, int rate){
    int salary;
    if(hours<40){
        salary=hours*rate;
        return salary;
    }
    else{
        salary=40*rate;
        hours-=40;
        salary=salary+(hours*(rate*1.5));
        return salary;
    }
}
void printCheck(int hours, int rate, int salary){
    cout<<"The hours worked are: "<<hours<<"\nThe rate per hour is: "<<rate<<"\n The salary is: "<<salary<<endl;
}
void funcOne(int x, int y){
    int num;
    cout<<"Enter a number";
    cin>>num;
    x=((2*x)+y)-num;
    cout<<"The new X is: "<<x<<endl;
}
void nextChar(char *z){
    cout<<"The initial value of Z was: "<<*z;
    *z+=1;
    cout<<"\nThe new value of Z is: "<<*z<<endl;
}
main(){
    int x,y;
    char z;
    cout<<"Enter the values of x, y and z to be initialized";
    cin>>x>>y;
    cin>>z;
    initialize(&x,&y,&z);
    int hours,rateperhour;
    getHoursRate(&hours,&rateperhour);
    int salary=payCheck(hours,rateperhour);
    printCheck(hours,rateperhour,salary);
    cout<<"Enter x and y to test funcOne";
    int x2,y2;
    cin>>x2>>y2;
    funcOne(x2,y2);
    nextChar(&z);
    




}