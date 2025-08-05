#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;

    int s=0;
    
    while(n!=0) {
        int r=n%10;

        if((s>INT_MAX/10) || (s<INT_MIN/10)) {
            return 0;
        }
        s=s*10+r;
        n/=10;
    } 

    cout<<s;
}