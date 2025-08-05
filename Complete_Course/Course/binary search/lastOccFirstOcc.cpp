#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[],int n,int key) {
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;
    int ans = -1;

    while(s <= e) {
        if(arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        } else if(arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(int arr[],int n,int key) {
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e) {
        if(arr[mid] == key) {
            ans = mid;
            s = mid + 1;    
        } else if(arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

pair<int,int> occ(int arr[],int n,int key) {
    pair<int,int> p;
    p.first = firstOcc(arr,n,key);
    p.second = lastOcc(arr,n,key);

    return p;
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

    // direct call bhi krr sakte h functions ko aur print krwa sakte h as needed

    pair<int,int> res = occ(arr,n,key);
    cout << res.first << "," << res.second << endl;

    // Total no. of occurence nikalne k liye just (lastOcc - firstOcc) + 1 krrdo =>

    // int total = (lastOcc(arr,n,key) - firstOcc(arr,n,key)) + 1;
    // cout << total;
}