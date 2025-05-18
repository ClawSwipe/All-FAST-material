#include <iostream>
#include <cstring>
using namespace std;
main(){
    cout<<"Please enter your string";
    string a;
    getline(cin,a);
    cout<<"string is "<<a<<endl;
    int len=a.length();
    int sum=0;
    do{
    	sum=0;
        len=a.length();
        for(int i=0;i<len;i++){
        switch (a[i]) {
            case 'a':
            case 'b':
            case 'c':
            if(sum>=7){
                break;
            }
            cout << "2";
            sum++;
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'd':
            case 'e':
            if(sum>=7){
                break;
            }
            case 'f':
            cout << "3";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'g':
            case 'h':
            if(sum>=7){
                break;
            }
            case 'i':
            cout << "4";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'j':
            case 'k':
            if(sum>=7){
                break;
            }
            case 'l':
            cout << "5";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'm':
            case 'n':
            if(sum>=7){
                break;
            }
            case 'o':
            cout << "6";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'p':
            case 'q':
            case 'r':
            if(sum>=7){
                break;
            }
            case 's':
            cout << "7";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 't':
            case 'u':
            if(sum>=7){
                break;
            }
            case 'v':
            cout << "8";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'w':
            case 'x':
            case 'y':
            if(sum>=7){
                break;
            }
            case 'z':
            cout << "9";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            cout<<"\n";
            break;
            
            case 'A':
            case 'B':
            if(sum>=7){
                break;
            }
            case 'C':
            cout << "2";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'D':
            case 'E':
            if(sum>=7){
                break;
            }
            case 'F':
            cout << "3";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'G':
            case 'H':
            if(sum>=7){
                break;
            }
            case 'I':
            cout << "4";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'J':
            case 'K':
            if(sum>=7){
                break;
            }
            case 'L':
            cout << "5";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'M':
            case 'N':
            if(sum>=7){
                break;
            }
            case 'O':
            cout << "6";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'P':
            case 'Q':
            case 'R':
            if(sum>=7){
                break;
            }
            case 'S':
            cout << "7";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'T':
            case 'U':
            if(sum>=7){
                break;
            }
            case 'V':
            cout << "8";
            sum++;
            
            if(sum==3){
                cout<<"-";
            }
            break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            if(sum>=7){
                break;
            }  
            cout << "9";          
            sum++;
            if(sum==3){
                cout<<"-";
            }
            cout<<"\n";
            break;
            case 32:
            continue;
            default:
            cout<<"Invalid input"<<endl;
		}
    }
    cout<<"\nEnter another string or -1 to terminate";
    getline(cin,a);
    }while(a!="-1");
}
