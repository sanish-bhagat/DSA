#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[],int n) {
    int s = 0;
    int e = n - 1;

    int mid = s + (e - s) / 2;

    while(s < e) {
        if(arr[mid] < arr[mid + 1]) {
            s = mid + 1;
        } else{
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    //e bhi return krr sakte ho

    return s;  //element ko print krrne k liye arr[s] krrdo
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout  << "Enter the elements: ";

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << "The peak element is at index "<< peakElement(arr,n);
}