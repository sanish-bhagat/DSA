#include<iostream>
using namespace std;

int main() {
    int a=4;
    int b=2;
    char op;
    cout<<"Enter the operation to be performed: ";
    cin>>op;

    switch(op) {
        case '+':
            cout<<a+b;
            break;
        
        case '-':
            cout<<a-b;
            break;

        case '*':
            cout<<a*b;
            break;

        case '/':
            cout<<a/b;
            break;
        
        case '%':
            cout<<a%b;
            break;

        default:
            cout<<"Invalid";
    }
}