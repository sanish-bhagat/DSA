#include<bits/stdc++.h>
using namespace std;

//binary search is only valid if the elements of the array is in increasing or decreasing order

//TC is  always O(log n) for binary search

int binarySearch(int arr[],int size,int key) {
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;   // mid = (start + end) / 2   just to not exceed the limit of int data type we have used the other formula

    while(start <= end) {
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n; 

    int arr[n];

    cout << "Enter the elements: ";

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;

    cout << "The index having "<<key<<" is "<<binarySearch(arr,n,key);
}