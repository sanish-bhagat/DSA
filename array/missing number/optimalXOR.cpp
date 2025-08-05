#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N)
//space complexity is O(1)
//XOR method is better than sum method as it does not exceeds the maximum no.(XOR of all no is not so big)
// whereas in sum it can exceed the max value that can be stored in a datatype 

int missing(int arr[],int n) {
    int XOR1 = 0;

    // for(int i=1;i<=n;i++) {
    //     XOR1 = XOR1 ^ i;   
    // }

    int XOR2 = 0 ; 

    for(int i=0;i<n-1;i++) {
        XOR2 = XOR2 ^ arr[i];
        XOR1 = XOR1 ^ (i+1);
    }
    XOR1 = XOR1 ^ n;

    return XOR1 ^ XOR2;
}

int main() {
    int n;
    cout << "Emter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i =0; i < n-1; i++) {
        cin >> arr[i];
    }

    cout << missing(arr,n);
}