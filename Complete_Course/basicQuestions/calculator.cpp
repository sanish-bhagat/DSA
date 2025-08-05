#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;
    
    float a=4;
    float b=2;

    if(n==1) {
        cout<<a+b;
    }
    else if(n==2){
        cout<<a-b;
    }
    else if(n==3) {
        cout<<a*b;
    }
    else if(n==4){
        cout<<a/b;
    }
    else {
        cout<<"Invalid";
    }
}