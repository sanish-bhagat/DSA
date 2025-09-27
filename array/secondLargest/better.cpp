#include<bits/stdc++.h>
using namespace std;

//time complexity is O(2N)

void secondLargest(int arr[],int n) {
    int largest=arr[0];

    for(int i=0;i<n;i++) {
        if(arr[i]>largest) {
            largest = arr[i];
        }
    }

    int sLargest=INT_MIN;

    for(int i=0;i<n;i++) {
        if(arr[i]>sLargest && arr[i]!=largest) {
            sLargest=arr[i];
        }
    }
    cout<<sLargest;
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
    
    secondLargest(arr,n);
}