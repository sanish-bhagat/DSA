#include<bits/stdc++.h>
using namespace std;

//TC is O(log N)   logarithmic having base 2
//to avoid overflow case use mid = low + (high - low) / 2;

int binarySearch(int arr[],int low,int high,int target) {
   if(low > high) return -1;

   int mid = (low + high) / 2;

   if(arr[mid] == target) return mid;
   else if (target > arr[mid]) {

    return binarySearch(arr,mid + 1,high,target);

   }
   else {
    return binarySearch(arr,low,mid-1,target);
   }
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

    cout << binarySearch(arr,0,n-1,target);
}