#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;

    int m=n;
    int mask=0;

    if(n==0) {
        return 1;
    }

    while(n!=0) {
        mask=(mask<<1)|1;
        m=m>>1;
    } 

    int ans=(~n) & mask;
    cout<<ans;
}