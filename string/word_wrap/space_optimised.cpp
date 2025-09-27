#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

int solveWordWrap(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, INT_MAX); // dp[i] stores min cost from i to end
    vector<int> ans(n, 0);      // ans[i] stores last word index on line

    dp[n - 1] = 0; // No extra cost for the last word

    for (int i = n - 2; i >= 0; i--)
    {
        int currLen = -1; // To manage spaces correctly

        for (int j = i; j < n; j++)
        {
            currLen += arr[j] + 1; // Adding word length and a space

            if (currLen > k)
                break; // If line overflows, stop

            int cost;
            if (j == n - 1)
                cost = 0; // No cost for the last line
            else
                cost = (k - currLen) * (k - currLen) + dp[j + 1];

            if (cost < dp[i])
            {
                dp[i] = cost;
                ans[i] = j; // Store where to break the line
            }
        }
    }
    return dp[0]; // Minimum cost for wrapping all words
}

int main()
{
    int k = 6;

    vector<int> arr = {6, 6, 7, 4, 4};
    int res = solveWordWrap(arr, 9);
    cout << res << endl;
    return 0;
}
