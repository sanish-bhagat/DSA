#include<iostream>
using namespace std;

int main() {
    int n=000000000000000000000000000111111;

    int count=0;
    
    while(n>0) {
        if(n&1) {
            count++;
        }
        n=n>>1;
    }
    cout<<count;

}