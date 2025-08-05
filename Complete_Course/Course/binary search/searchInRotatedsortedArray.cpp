#include<bits/stdc++.h>
using namespace std;

//TC is O(log n) + O(log n)

int pivot(int arr[],int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s)/2;

    while(s < e) {
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s)/2;
    }
    return s;
}

int binarySearch(int arr[],int start,int end,int key) {
    int s = start;
    int e = end;
    int mid = s + (e - s)/2;

    while(s <= e) {
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s)/2;
    }
    return -1;
}

int findPosition(int arr[],int n,int key) {
    int piv = pivot(arr,n);

    if(key >= arr[piv] && key <= arr[n - 1]) {
        return binarySearch(arr,piv,n - 1,key);
    } else {
        return binarySearch(arr,0,piv - 1,key);
    }
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

    cout << "The element is present at index: " << findPosition(arr,n,key);
}