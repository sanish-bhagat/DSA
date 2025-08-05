#include<iostream>
using namespace std;

int main() {
    int arr[8]={1,2,3,4,5,6,7,8};
    for(int i=0;i<=7;i++) {
        if(i%2==0) {
            cout<<arr[i]+10<<" ";
        }
        else {
            cout<<arr[i]*2<<" ";
        }
    }
}