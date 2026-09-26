#include <bits/stdc++.h>
using namespace std;

//! TC is O(x)
//! SC is O(x)

int minimumCost(int x, int s, int m, int l,
                int cs, int cm, int cl) {

    // Compute DP up to the maximum useful area.
    int limit = x + l;
    vector<int> dp(limit + 1, INT_MAX);

    dp[0] = 0;

    // Build minimum cost for every achievable area.
    for (int i = 0; i <= limit; i++) {

        if (dp[i] == INT_MAX)
            continue;

        if (i + s <= limit)
            dp[i + s] = min(dp[i + s], dp[i] + cs);

        if (i + m <= limit)
            dp[i + m] = min(dp[i + m], dp[i] + cm);

        if (i + l <= limit)
            dp[i + l] = min(dp[i + l], dp[i] + cl);
    }

    // Find the minimum cost for an area of at least x.
    int res = INT_MAX;

    for (int i = x; i <= limit; i++)
        res = min(res, dp[i]);

    return res;
}

int main() {
    int x = 16;
    int s = 3, m = 6, l = 9;
    int cs = 50, cm = 150, cl = 300;

    cout << minimumCost(x, s, m, l, cs, cm, cl) << endl;

    return 0;
}