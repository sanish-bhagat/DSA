#include<bits/stdc++.h>
using namespace std;

//time complexity is O(2N)
//space complexity is O(N)

int missing(int arr[],int n) {
    int hash[n+1]={0};

    for(int i=0;i<n-1;i++) {
        hash[arr[i]]=1;
    }

    for(int i=1;i<n;i++) {
        if(hash[i] == 0) return i;
    }
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