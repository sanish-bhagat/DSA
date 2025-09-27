#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N)
//space complexity is O(1)

int maxConsecutiveOne(int arr[],int n) {
    int maxi=0;
    int count=0;

    for(int i=0;i<n;i++) {
        if(arr[i] == 1) {
            count++;
            maxi = max(count,maxi);
        } else {
            count = 0;
        }
    }
    return maxi;
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

    cout << maxConsecutiveOne(arr,n);
}