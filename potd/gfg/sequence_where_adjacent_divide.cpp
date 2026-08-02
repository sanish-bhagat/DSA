#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

//! TC is O(n * m * logm)
//! SC is O(n * m)

int count(int n, int m)
{
    // dp[len][val]
    // Number of valid arrays of length len
    // ending with value val
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // factors[x]  -> all factors of x
    // multiples[x] -> all multiples of x
    vector<vector<int>> factors(m + 1);
    vector<vector<int>> multiples(m + 1);

    // Precompute factors and multiples
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j += i)
        {
            factors[j].push_back(i);

            // Avoid duplicate insertion
            if (j != i)
            {
                multiples[i].push_back(j);
            }
        }
    }

    // Base Case:
    // Arrays of length 1
    for (int val = 1; val <= m; val++)
    {
        dp[1][val] = 1;
    }

    // Build DP table
    for (int len = 2; len <= n; len++)
    {
        for (int curr = 1; curr <= m; curr++)
        {
            // Add all factors
            for (int prev : factors[curr])
            {
                dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % mod;
            }

            // Add all multiples
            for (int prev : multiples[curr])
            {
                dp[len][curr] = (dp[len][curr] + dp[len - 1][prev]) % mod;
            }
        }
    }

    // Final Answer
    int ans = 0;

    for (int val = 1; val <= m; val++)
    {
        ans = (ans + dp[n][val]) % mod;
    }

    return ans;
}

int main()
{
    int n = 3;
    int m = 3;

    cout << count(n, m);

    return 0;
}