#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N*N)
//space complexity is O(1)

void longestSubarray(int arr[],int n,int m) {
    int length = 0;

    for(int i=0;i<n;i++) {

        int sum = 0;

        for(int j=i;j<n;j++) {
            
            sum += arr[j];

            //time complexity is O(N^3) =>
            
            // for(int k=i;k<=j;k++) {
            //     sum += arr[k];
            // }


            if(sum == m) length = max(length,j-i+1);
        }
    }

    cout<<length;
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

    int m;
    cout << "Enter the sum of the subarray: ";
    cin >> m;

    longestSubarray(arr,n,m);
}