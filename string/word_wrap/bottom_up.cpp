#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int solveWordWrap(vector<int> arr, int k)
{

    int n = arr.size();
    vector<int> dp(n + 1, INT_MAX);

    // base case
    dp[n] = 0;

    for (int curr = n - 1; curr >= 0; curr--)
    {

        int sum = 0;

        for (int i = curr; i < n; i++)
        {

            sum += arr[i];
            int tot = sum + (i - curr);

            if (tot > k)
                break;

            if (i == n - 1)
                dp[curr] = min(dp[curr], 0);

            else
            {

                int cost = (k - tot) * (k - tot);
                dp[curr] = min(dp[curr], cost + dp[i + 1]);
            }
        }
    }

    return dp[0];
}

int main()
{
    int k = 6;

    vector<int> arr = {3, 2, 2, 5};
    int res = solveWordWrap(arr, k);
    cout << res << endl;
    return 0;
}