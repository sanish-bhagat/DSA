#include<bits/stdc++.h>
using namespace std;

// time complexity is O(N)
//extra space used is O(1), as we are making the changes in the same array
// space complexity for the whole algorithm is O(N)

void leftRotate(int arr[],int n) {
    int temp=arr[0];

    for(int i=1;i<n;i++) {
        arr[i-1]=arr[i];
    }

    arr[n-1]=temp;
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

    leftRotate(arr,n);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}