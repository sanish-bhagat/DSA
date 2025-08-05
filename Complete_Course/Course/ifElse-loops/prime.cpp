#include<Iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the terms: ";
    cin>>n;

    bool isPrime=1;

    for(int i=2;i<n;i++) {
        if(n%i==0) {
            isPrime=0;
            break;
        }    
    }

    if(isPrime==0) {
        cout<<"Not a prime no.";
    }
    else {
        cout<<"Is a prime no.";
    }
}