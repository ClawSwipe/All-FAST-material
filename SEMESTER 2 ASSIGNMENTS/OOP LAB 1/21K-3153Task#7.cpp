#include<iostream>
using namespace std;
main(){
cout<<"Enter the start and end of your range";
int max,sum=0,min;
cin>>min>>max;
for(int i=min;i<=max;i++){
if(i%2!=0 && i%3==0){
cout<<"The number "<<i<<" is both odd and divisible by 3"<<endl;
sum+=i;
}
else if(i%2!=0){
cout<<"The number "<<i<<" is odd"<<endl;
sum+=i;
}
else if(i%3==0){
cout<<"The number "<<i<<" is divisible by 3"<<endl;
sum+=i;
}
}
cout<<"The sum is "<<sum;
}
