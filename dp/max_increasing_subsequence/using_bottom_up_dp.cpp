#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int maxSumIS(vector<int> &arr)
{
    int n = arr.size();

    // track only the precious indices
    vector<int> dp(n + 1);

    dp[0] = arr[0];
    int ans = 0;

    // iteratively traverse throught all the elements
    for (int i = 0; i < n; i++)
    {
        int maxSum = 0;

        // pick the max element from left of the ith index
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                maxSum = max(maxSum, dp[j]);
        }

        // include in the curr subsequence
        dp[i] = maxSum + arr[i];

        // update the ans with the max one
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 101, 2, 3, 100};
    cout << maxSumIS(arr);
}