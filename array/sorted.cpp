#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N)

int isSorted(int arr[],int n) {
    for(int i=1;i<n;i++) {
        if(arr[i]>=arr[i-1]) {

        } else {
            return false;
        }
    }
    return true;
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

    cout<<isSorted(arr,n);
    
}