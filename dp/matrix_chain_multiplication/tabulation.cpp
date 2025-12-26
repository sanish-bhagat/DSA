#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();

    // 2d dp[] to store min multiplication cost
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // explore all the chain length, and fill the dp table in bottom up manner
    for (int len = 2; len < n; len++)
    {
        for (int i = 0; i < n - len; i++)
        {
            int j = i + len;
            dp[i][j] = INT_MAX;

            // place the bracket at the every position and pick the min cost
            for (int k = i + 1; k < j; k++)
            {
                int cost = dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // return the min cost
    return dp[0][n - 1];
}

int main()
{

    vector<int> arr = {2, 1, 3, 4};
    cout << matrixMultiplication(arr);
    return 0;
}