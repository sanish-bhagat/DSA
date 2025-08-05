#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;

    int n1=n;
    int s=0;

    while(n1>0) {
        int r=n1%10;
        s=s*10+r;
        n1=n1/10;
    }

    if(n==s) {
        cout<<n<<" is a palindrome.";
    } else {
        cout<<n<<" is not a palindrome.";
    }
}