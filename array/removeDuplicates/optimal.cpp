#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N)
// space complexity is O(1)

int removeDuplicates(int arr[],int n) {
    int i=0;

    for(int j=1;j<n;j++) {
        if(arr[i] != arr[j]) {
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
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

    cout<<removeDuplicates(arr,n);
}