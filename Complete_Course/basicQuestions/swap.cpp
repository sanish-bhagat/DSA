#include<iostream>
using namespace std;

int main() {
    int a=10;
    int b=250;

    int temp=a;
    a=b;
    b=temp;

    cout<<a<<" "<<b;
}