#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int n1=n;
    int sum=0;

    while(n>0) {
        int ld=n%10;
        sum=sum+(ld*ld*ld);
        n/=10;
    }

    if(n1==sum) {
        cout<<"Armstrong number";
    } else {
        cout<<"Not an armstrong number";
    }
}