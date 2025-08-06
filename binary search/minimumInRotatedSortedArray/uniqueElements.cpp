#include<bits/stdc++.h>
using namespace std; 

int minimumInRotatedSortedArray(int arr[],int n) {
    int ans = INT_MAX,low = 0 ,high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        //search space is already sorted then always arr[low] will be the minimum element 

        if(arr[low] <= arr[high]) {
            ans = min(ans , arr[low]);
            break;
        }

        if(arr[low] <= arr[mid]) {
            ans = min(ans,arr[low]);
            low = mid + 1;
        } else {
            ans = min(ans,arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
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

    cout << minimumInRotatedSortedArray(arr,n);
}