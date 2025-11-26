#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(n * k)

int numOfSubsets(vector<int> &arr, int k)
{
    int n = arr.size();

    // 2d dp[]
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1));

    // itertively traverse all the elements
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            // exclude the curr element
            dp[i][j] = dp[i - 1][j];

            // include the curr element, if and only if arr[i - 1] is less than equal to j
            if (j >= arr[i - 1])
                dp[i][j] += dp[i - 1][j / arr[i - 1]];
        }
    }

    // return the total count of subsets, excluding the empty subset
    return dp[n][k] - 1;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4};
    int k = 10;
    cout << numOfSubsets(arr, k);
    return 0;
}