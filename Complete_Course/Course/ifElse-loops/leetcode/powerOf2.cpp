#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;
    // int r=0;
    // for(int i=0;i<=30;i++) {
    //     int ans=pow(2,i);
        
    //     if(ans==n) {
    //         r=1;
    //     } 
    // }

    // if(r==1) {
    //     cout<<"true";
    // } else {
    //     cout<<"false";
    // }

    int ans=1;
    bool flag=0;

    for(int i=0;i<=30;i++) {
        if(ans==n) {
            flag=1;
        }
        if(ans<INT_MAX/2) {
            ans*=2;
        }
        
    }

    if(flag==true) {
        cout<<"true";
    } else {
        cout<<"false";
    }
}