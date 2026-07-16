#include <iostream>
#include <vector>
using namespace std;

//! TC is O(n * sum)
//! SC is O(n * sum)

int countWays(int n, int sum)
{
    if (sum > 9 * n)
        return -1;

    // dp[len][s] = count of len-digit sequences
    // having digit sum equal to s.
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    dp[0][0] = 1;

    // Build the DP table.
    for (int len = 1; len <= n; len++)
    {
        for (int s = 0; s <= sum; s++)
        {
            for (int digit = 0; digit <= 9; digit++)
            {
                if (s >= digit)
                {
                    dp[len][s] += dp[len - 1][s - digit];
                }
            }
        }
    }

    int ans = 0;

    // First digit must be from 1 to 9.
    for (int digit = 1; digit <= 9; digit++)
    {
        if (sum >= digit)
        {
            ans += dp[n - 1][sum - digit];
        }
    }

    return (ans == 0) ? -1 : ans;
}

int main()
{
    int n = 2;
    int sum = 5;
    int ans = countWays(n, sum);
    cout << ans;
    return 0;
}