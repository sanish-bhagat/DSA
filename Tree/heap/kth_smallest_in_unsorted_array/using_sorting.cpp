#include<bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

int kthSmallest(int arr[], int n, int k) {
    sort(arr, arr+n);

    return arr[k - 1];
}

int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int N = sizeof(arr) / sizeof(arr[0]), K = 2;

    // Function call
    cout << "K'th smallest element is "
         << kthSmallest(arr, N, K);
    return 0;
}