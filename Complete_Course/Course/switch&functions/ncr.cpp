#include<iostream>
using namespace std;

int fact(int n) {
    int f=1;

    for(int i=1;i<=n;i++) {
        f*=i;
    }
    return f;
}


int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int r;
    cout<<"Enter r: ";
    cin>>r;

    cout<<fact(n)/(fact(r)*fact(n-r));
}