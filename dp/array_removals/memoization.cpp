#include <bits/stdc++.h>
using namespace std;

int helper(int a[], int i, int j, int k, vector<vector<int>> &dp)
{
    // base case: all elements are removeed
    if (i >= j)
        return 0;

    // already computed subproblem
    if (dp[i][j] != -1)
        return dp[i][j];

    // condition satisfied
    if ((a[j] - a[i]) <= k)
        return 0;

    // pick the min from either of the two removal case - either we can remove from start or from the last
    else
        dp[i][j] = 1 + min(helper(a, i + 1, j, k, dp), helper(a, i, j - 1, k, dp));

    // return the computed removals
    return dp[i][j];
}

//! TC is O(n * n)
//! SC is O(n * n)

int removals(int a[], int n, int k)
{
    // sort the given arr[] in ascending order
    sort(a, a + n);

    // 2d memo[][] to keep track of min removals which can give difference b/w max and min <= k
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    if (n == 1)
        return 0;

    return helper(a, 0, n - 1, k, dp);
}

int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}