#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int longestSubseq(vector<int> &arr)
{
    int n = arr.size();

    // base case
    if (n == 1)
        return 1;

    int ans = 1;

    // hash table
    unordered_map<int, int> dp;

    for (int x : arr)
    {
        // curr element can be included to a previous subsequence
        if (dp.count(x - 1) || dp.count(x + 1))
            dp[x] = 1 + max(dp[x - 1], dp[x + 1]);

        // new subsequence
        else
            dp[x] = 1;

        // update the max
        ans = max(ans, dp[x]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {10, 9, 4, 5, 4, 8, 6};
    cout << longestSubseq(arr);
}