#include<bits/stdc++.h>
using namespace std;

void max(int arr[],int n) {
    int max = arr[0];
    for(int i=0;i<n;i++) {
        if(arr[i]>max) max=arr[i];
    }
    cout<<max;
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    max(arr,n);
}