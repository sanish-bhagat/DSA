#include<bits/stdc++.h>
using namespace std;

//time complexity is O(x) + O(n-x) => O(n)
//space complexity or extra space used is O(1)

void zero(int arr[],int n) {
    int j=-1;

    for(int i=0;i<n;i++) {
        if(arr[i]==0) {
            j = i;
            break;
        }
    }

    for(int i=j+1;i<n;i++) {
        if(arr[i] != 0) {
            swap(arr[i],arr[j]);
            j++;
        }
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

    zero(arr,n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}