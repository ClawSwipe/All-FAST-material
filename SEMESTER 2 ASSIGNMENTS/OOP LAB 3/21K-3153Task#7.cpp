#include<iostream>
#include<string>
using namespace std;
class Inventory{
    private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;
    public:
    Inventory(){
        itemNumber=0;
        quantity=0;
        cost=0;
        totalCost=0;
    }
    Inventory(int a,int b,double c){
        itemNumber=a;
        quantity=b;
        cost=c;
        setTotalCost(quantity,cost);
    }
    void setTotalCost(int quantity, double cost){totalCost=quantity*cost;}
    void setitemNumber(int a) {itemNumber=a;}
    void setQuantity(int b) {quantity=b;}
    void setCost(double c) {cost=c;}
    int getItemNumber(){return itemNumber;}
    int getQuantity(){return quantity;};
    double getCost(){return cost;};
    double getTotalCost(){return totalCost;};

};
main(){

    cout<<"Enter the item number, quantity and cost of the item";
    int a,b;
    double c;
    cin>>a>>b>>c;
    Inventory i(a,b,c);
    cout<<"The total cost of "<<i.getQuantity()<<" items of item number "<<i.getItemNumber()<<", each costing a "<<i.getCost()<<" units is "<<i.getTotalCost()<<" units."<<endl;
}