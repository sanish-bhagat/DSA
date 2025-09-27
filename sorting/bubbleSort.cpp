#include<bits/stdc++.h>
using namespace std;

//push the max to the last by adjacent swaps

//time complexity for the best case is O(N)

void bubble_sort(int arr[],int n) {
    for(int i=n-1;i>=0;i--) {
        int didSwap=0;
        for(int j=0;j<=i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didSwap=1;
            }
        }
        if(didSwap==0) break;
    }
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
    bubble_sort(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}