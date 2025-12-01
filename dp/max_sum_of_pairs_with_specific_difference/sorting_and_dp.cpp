#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // sort the given array in increasing order
    sort(arr, arr + N);

    // 1d dp[] to store the valid pairs sum
    int dp[N];

    dp[0] = 0;

    // traverse through the elements of the array
    for (int i = 1; i < N; i++)
    {
        // exclude the curr element
        dp[i] = dp[i - 1];

        // include the current pair if it is valid
        if (arr[i] - arr[i - 1] < K)
        {
            // more than two elements, update dp by choosing the max b/w pairing and not pairing sum
            if (i >= 2)
                dp[i] = max(dp[i], dp[i - 2] + arr[i] + arr[i - 1]);

            // less than two elements in the array -> can form only one pair, pick the max sum
            else
                dp[i] = max(dp[i], arr[i] + arr[i - 1]);
        }
    }

    // return the max sum of valid pairs
    return dp[N - 1];
}

int main()
{
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr) / sizeof(int);

    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K);
    return 0;
}