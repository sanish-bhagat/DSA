#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int helper(int arr[], int i, vector<int> &dp)
{
    // base case: no element left
    if (i < 0)
        return 0;

    // base case: only one element
    if (i == 0)
        return arr[i];

    // already computed subproblem
    if (dp[i] != -1)
        return dp[i];

    // exclude the curr element
    int a = helper(arr, i - 1, dp);

    // include the curr element and the next coonsecutive element in the subsequence
    int b = arr[i] + arr[i - 1] + helper(arr, i - 3, dp);

    // include the curr element and skip the next consecutive element
    int c = arr[i] + helper(arr, i - 2, dp);

    // keep the max sum among the three cases
    return dp[i] = max({a, b, c});
}

int maxSumWO3Consec(int arr[], int n)
{
    // 1d[] to keep track of sum
    vector<int> dp(n + 1, -1);

    // recursive function to calculate the max sum
    return helper(arr, n - 1, dp);
}

int main()
{
    int arr[] = {100, 1000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}