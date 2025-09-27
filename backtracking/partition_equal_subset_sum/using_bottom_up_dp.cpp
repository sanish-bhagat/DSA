#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * sum)
//! SC is O(n * sum)

bool equalPartition(vector<int> &arr)
{
    int n = arr.size();

    // sum of arr[]
    int sum = accumulate(arr.begin(), arr.end(), 0);

    // sum is odd, arr[] cannot be partitioned in equal sum
    if (sum % 2 != 0)
        return false;

    // target subset sum
    sum = sum / 2;

    // dp to store results of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // for empty subset, sum is 0, so fill with true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // fill the table in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // current element is greater than the sum, ignore it
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];

            else
            {
                // include or exclude the curr element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    vector<int> arr = {1, 5, 11, 5};
    if (equalPartition(arr))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}