#include<iostream>
#include<string>
using namespace std;
class Employee{
    public:
    string Fname;
    string Lname;
    double salary;
    double negsalary(double salary){
        if(salary<0){
            salary=0;
            return salary;
        }
        else{
            return salary;
        }
    }
    void display(Employee E1){
        cout<<"Employee "<<E1.Fname<<" "<<E1.Lname<<"'s salary is "<<E1.salary<<endl;
    }
    void raise(Employee E1){
        E1.salary=E1.salary + (0.1*E1.salary);
        cout<<"Employee "<<E1.Fname<<" "<<E1.Lname<<"'s salary is now "<<E1.salary<<endl;
    }
};
main(){
    Employee E1,E2;
    cout<<"Enter the first name, last name and the salary of the first employee";
    cin>>E1.Fname>>E1.Lname>>E1.salary;
    E1.salary=E1.negsalary(E1.salary);
    cout<<"Enter the first name, last name and the salary of the second employee";
    cin>>E2.Fname>>E2.Lname>>E2.salary;
    E2.salary=E2.negsalary(E2.salary);
    E1.display(E1);
    E1.raise(E1);
    E2.display(E2);
    E2.raise(E2);

}