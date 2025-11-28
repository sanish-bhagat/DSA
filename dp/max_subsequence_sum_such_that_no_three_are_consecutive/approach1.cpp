#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxSumWO3Consec(int arr[], int n)
{
    int sum[n];

    // base cases
    if (n >= 1)
        sum[0] = arr[0];

    if (n >= 2)
        sum[1] = arr[0] + arr[1];

    // pick the max sum of two elements among the first three
    if (n > 2)
        sum[2] = max(sum[1], max(arr[0] + arr[2], arr[1] + arr[2]));

    // three cases:
    // exclude arr[i] => sum[i - 1],
    // exclude arr[i - 1] => sum[i - 2] + arr[i],
    // exclude arr[i - 2] => sum[i - 3] + arr[i - 1] + arr[i]
    for (int i = 3; i < n; i++)
    {
        sum[i] = max({sum[i - 1], sum[i - 2] + arr[i], sum[i - 3] + arr[i - 1] + arr[i]});
    }

    // return the max sum
    return sum[n - 1];
}

int main()
{
    int arr[] = {100, 1000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}