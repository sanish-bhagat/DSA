#include<bits/stdc++.h>
using namespace std;

//TC is O(log (max) * N)

int sumOfD(int arr[],int n,int div) {
    int sum = 0;

    for(int i=0; i<n; i++) {
        sum += ceil((double)arr[i] / (double)div);
    }
    return sum;
}

int divisor(int arr[],int n,int threshold) {
    int low = 1, high = *max(arr,arr+n);

    while(low <= high) {
        int mid = (low + high) / 2;

        if(sumOfD(arr,n,mid) <= threshold) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return low;
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