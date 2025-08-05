#include<bits/stdc++.h>
using namespace std;

//TC is O(max * N)

int findMax(int arr[],int n) {
    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

int divisor(int arr[],int n,int threshold) {
    for(int d=1; d<=findMax(arr,n); d++) {
        int sum = 0;

        for(int i=0; i<n; i++) {
            sum += ceil((double)arr[i] / (double(d)));
        }
        if(sum <= threshold) return d;
    }
    return -1;
}

int main() {
    int n,threshold;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the threshold: ";
    cin >> threshold;

    cout << divisor(arr,n,threshold);
}