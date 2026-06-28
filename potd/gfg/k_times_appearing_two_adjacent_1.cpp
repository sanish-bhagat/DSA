#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int MOD = 1e9 + 7;

    // dp table
    vector<vector<vector<int>>> dp;

    int solve(int i, int n, int k, int prev, int cnt)
    {
        // base case
        if (cnt > k)
            return 0;

        // base case
        if (i == n)
        {
            if (cnt == k)
                return 1;

            return 0;
        }

        // already computed subproblem
        if (dp[i][cnt][prev] != -1)
            return dp[i][cnt][prev];

        // place 0 in curr place
        int ans0 = solve(i + 1, n, k, 0, cnt);

        // if prev and curr state is 1, increment the cnt
        int newCnt = cnt;
        if (prev == 1)
            newCnt++;

        // recurse with the new cnt
        int ans1 = solve(i + 1, n, k, 1, newCnt);

        // get the total no. of such strings
        return dp[i][cnt][prev] = (ans0 + ans1) % MOD;
    }

public:

    //! TC is O(n * k)
    //! SC is O(n * k)

    int countStrings(int n, int k)
    {
        // initialise the dp with -1
        dp.assign(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        // start the recursion, one by placeing 0 at start
        // and other by placing 1 at start
        int ans0 = solve(1, n, k, 0, 0);
        int ans1 = solve(1, n, k, 1, 0);

        return (ans0 + ans1) % MOD;
    }
};

int main()
{
    int n = 5, k = 2;

    Solution sol;

    cout << sol.countStrings(n, k);
}