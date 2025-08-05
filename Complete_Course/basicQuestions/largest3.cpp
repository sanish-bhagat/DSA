#include<iostream>
using namespace std;

int main() {
    int a;
    cout<<"Enter a 1st no. : ";
    cin>>a;
    int b;
    cout<<"Enter a 2nd no. : ";
    cin>>b;
    int c;
    cout<<"Enter a 3rd no. : ";
    cin>>c;

    if(a>b && a>c) {
        cout<<"a is greater";
    }
    else if(b>a && b>c){
        cout<<"b is greater";
    }
    else {
        cout<<"c is greater";
    }
}