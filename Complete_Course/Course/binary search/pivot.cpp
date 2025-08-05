#include<bits/stdc++.h>
using namespace std;

//pivot can be anything here pivot is the minimum element present in the array
//only applicable for sorted and rotated array

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
        mid = s + (e - s) / 2;
    }

    return s;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << "the pivot is at the index: "<<pivot(arr,n);
}