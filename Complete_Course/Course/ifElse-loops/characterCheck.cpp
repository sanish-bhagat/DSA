#include<iostream>
using namespace std;

int main() {
    char ch;
    cout<<"Enter the character: ";
    cin>>ch;

    if('a'<=ch && ch<='z') {
        cout<<"Character is lower case.";
    } else if('A'<=ch && ch<='Z') {
        cout<<"Character is upper case.";
    } else if('0'<=ch && ch<='9') {
        cout<<"Character is a no.";
    }
}