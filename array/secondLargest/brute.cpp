#include<bits/stdc++.h>
using namespace std;

int largest;
// BRUTE SOLUTION =>>

int partition(int arr[],int low,int high) {
    int pivot=arr[0];
    int i=low;
    int j=high;

    while(i<j) {
        while(arr[i]<=pivot && i<=high-1) {
            i++;
        }

        while(arr[j] > pivot && j>=low+1) {
            j--;
        }

        if(i<j) swap(arr[i],arr[j]);
    }

    swap(arr[low],arr[j]);
    return j;
}

void sort(int arr[],int low,int high) {
    if(low<high) {
        int pIndex=partition(arr,low,high);
        sort(arr,low,pIndex-1);
        sort(arr,pIndex+1,high);
    }
}

void secondLargest(int arr[],int n) {
    sort(arr,0,n-1);
    int largest=arr[n-1];
    for(int i=n-2;i>=0;i--) {
        if(arr[i]!=largest) {
            int sLargest=arr[i];
            cout<<sLargest;
            break;
        }
    }
}


int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements opf the array: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    
    secondLargest(arr,n);
}


