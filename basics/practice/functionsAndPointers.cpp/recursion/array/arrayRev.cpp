#include<iostream>
using namespace std;

int main() {
    int arr1[5]={1,2,3,4,5};
    int arr2[5];
    for(int i=0;i<=4;i++) {
        arr1[i]=arr1[4-i];
        cout<<arr1[i]<<" ";
    }
}