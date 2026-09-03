#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxDiffSum(vector<int> &arr)
{
    int n = arr.size();

    // dp[i][0] stores the maximum sum when the i-th element is changed to 1
    // dp[i][1] stores the maximum sum when the i-th element remains unchanged
    vector<vector<int>> dp(n, vector<int>(2, 0));

    for (int i = 0; i < n - 1; i++)
    {
        // Case 1: Current element is changed to 1
        dp[i + 1][0] = max(dp[i][0], dp[i][1] + abs(1 - arr[i]));

        // Case 2: Current element remains as arr[i + 1]
        dp[i + 1][1] = max(dp[i][0] + abs(1 - arr[i + 1]), dp[i][1] + abs(arr[i + 1] - arr[i]));
    }

    // return the max possible diff sum
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main()
{
    vector<int> arr = {3, 2, 1, 4, 5};

    cout << maxDiffSum(arr) << endl;

    return 0;
}