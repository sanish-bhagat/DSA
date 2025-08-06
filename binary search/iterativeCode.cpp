#include<bits/stdc++.h>
using namespace std;

//TC is O(log N)   logarithmic having base 2
//to avoid overflow case use mid = low + (high - low) / 2;


int binarySearch(int arr[],int n,int target) {
    int low = 0,high = n - 1;

    for(int i=low; i<=high; i++) {
        int mid = (low + high) / 2;

        if(arr[mid] == target) return mid;
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the no. to be searched: ";
    cin >> target;

    cout << binarySearch(arr,n,target);
}