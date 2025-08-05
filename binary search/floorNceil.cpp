#include<bits/stdc++.h>
using namespace std;

int floor(int arr[],int n,int target) {
    int low = 0, high = n - 1,ans = n;

    while(low <= high) {
        int mid = (low + high) / 2 ;

        if(arr[mid] <= target) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int ceil(int arr[],int n,int target) {
    int low = 0,high = n - 1,ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] >= target) {
            ans = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
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

    int target;
    cout << "Enter the no. to be searched: ";
    cin >> target;

    cout << "Floor is " << floor(arr,n,target) << endl;
    cout << "Ceil is " << ceil(arr,n,target) << endl;
}