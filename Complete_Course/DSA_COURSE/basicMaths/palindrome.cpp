#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int n1=n;
    int rev=0;
    
    while(n1!=0) {
        int ld=n1%10;
        rev=(rev*10)+ld;
        n1/=10;
    }

    if(n==rev) {
        cout<<"Palindrome";
    } else {
        cout<<"Not palindrome";
    }
}