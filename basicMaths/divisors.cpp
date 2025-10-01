#include<bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int main() {
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) {
        if(n%i==0) {
            cout<<i<<" ";
        }
    }   
}
