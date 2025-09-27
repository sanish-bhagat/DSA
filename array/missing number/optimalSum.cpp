#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N)
//space complexity is O(1)

int missing(int arr[],int n) {
    int sum1 = (n*(n+1))/2;
    int sum2 = 0;

    for(int i=0;i<n-1;i++) {
        sum2 += arr[i];
    }

    return sum1 - sum2;
}

int main() {
    int n;
    cout << "Emter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i =0; i < n-1 ; i++) {
        cin >> arr[i];
    }

    cout<<missing(arr,n);
}