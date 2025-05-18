#include<iostream>
#include<string>
using namespace std;
class Distance{
    public:
    int feet;
    int inches;
    void display(int *totf,int *toti){
        cout<<"The total distance is "<<*totf<<" feet and "<<*toti<<" inches";
    }
    void add(Distance d1,Distance d2, int *totf, int *toti){
        *totf= d1.feet+d2.feet;
        *toti= d2.inches+d2.inches;
        if(*toti>=12){
            *totf=*totf+1;
            *toti=*toti-12;
        }
    }
};
main(){
    Distance d1,d2;
    cout<<"Enter the feet and inches of the first distance";
    cin>>d1.feet>>d1.inches;
    cout<<"Enter the feet and inches of the second distance";
    cin>>d2.feet>>d2.inches;
    int totf=0,toti=0;
    d1.add(d1,d2,&totf,&toti);
    d1.display(&totf,&toti);
        
}