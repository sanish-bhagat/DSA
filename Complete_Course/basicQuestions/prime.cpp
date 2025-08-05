#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;

    bool flag=false;

    for(int i=2;i<n;i++) {
        if(n%i==0) {
            flag= true;
            break;
        }
    }

    if(flag==true) {
        cout<<n<<" is not a prime no.";
    } else {
        cout<<n<<" is a prime no.";
    }
}