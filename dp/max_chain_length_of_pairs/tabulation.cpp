#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int maxChainLength(vector<pair<int, int>> &pairs)
{
    // sort all the given pairs in ascending order
    sort(pairs.begin(), pairs.end());

    int n = pairs.size();

    // 1d dp[] -> max chain ending at index i
    vector<int> dp(n, 1);

    // traverse the given pairs and fill the dp[] in bottom up manner
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // if curr pair can follow tha last chosen pair -> include it
            if (pairs[j].second < pairs[i].first)
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }

    // answer is max in dp[]
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<pair<int, int>> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLength(pairs);
    return 0;
}