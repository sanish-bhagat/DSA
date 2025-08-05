#include<bits/stdc++.h>
using namespace std;

//time complexity is O(3N)
//space complexity is O(max input element i.e maxi)

int numberOnce(int arr[],int n) {
    int maxi = arr[0];

    for(int i=0;i<n;i++) {
        maxi = max(maxi,arr[i]);
    }

    int hash[maxi] = {0};

    for(int i=0;i<n;i++) {
        hash[arr[i]]++;
    }

    for(int i=0;i<n;i++) {
        if(hash[arr[i]] == 1) {
            return arr[i];
        }
    }
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

    cout << numberOnce(arr,n);
}