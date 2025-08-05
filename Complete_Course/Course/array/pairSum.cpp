#include<iostream>
using namespace std;

int pairSum(int arr[],int n) {
    int sum=5;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]+arr[j]==sum) {
                cout<<i<<" "<<j;
                break;
            }
        }
    }
}

int main() {
    int arr[6]={1,2,3,4,5,6};

    pairSum(arr,6);
}