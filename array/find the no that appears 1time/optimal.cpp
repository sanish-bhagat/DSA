#include<bits/stdc++.h>
using namespace std;

//time complexity is O(N)
//space complexity is O(1)

int numberOnce(int arr[],int n) {
    int XOR = 0;
    for (int i=0;i<n;i++) {
        XOR ^= arr[i];
    }

    return XOR;
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