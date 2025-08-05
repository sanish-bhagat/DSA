#include<iostream>
using namespace std;

int main() {
    int n=125;
    int prod=1;
    int sum=0;

    while(n>0) {
        int r=n%10;
        prod*=r;
        sum+=r;

        n=n/10;
    }

    cout<<prod-sum;
}