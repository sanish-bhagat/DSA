#include<iostream>
using namespace std;

int main() {
    int arr[5]={1,2,3,4,5};
    int mul=1;
    for(int i=0;i<=4;i++) {
        mul*=arr[i];
    }
    cout<<mul;
}