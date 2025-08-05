#include<iostream>
using namespace std;

bool isPrime(int n) {

    for(int i=2;i<n;i++) {

        if(n%i==0) {
            return 1;
        }
        
    }
    return 0;
}

int main() {
    int n;
    cout<<"Enter a no. : ";
    cin>>n;

    if(isPrime(n)) {
        cout<<n<<" is not a prime no.";
    } else {
        cout<<n<<" is a prime no.";
    }

}