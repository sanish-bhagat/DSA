#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int ans=0;
    int pow=1;

    while(n>0) {
        int ld=n%2;
        ans+=ld*pow;
        pow*=10;
        n=n/2;
    }

    cout<<ans;


}