#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int prev, vector<pair<int, int>> &pairs)
{
    // traversed all the pairs
    if (idx == pairs.size())
        return 0;

    // case1: exclude the curr element
    int noTake = solve(idx + 1, prev, pairs);

    // case2: include the curr element, if it can follow the last chosen pair
    int take = 0;
    if (prev == -1 || pairs[prev].second < pairs[idx].first)
        take = 1 + solve(idx + 1, idx, pairs);

    // pick the max length
    return max(take, noTake);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int maxChainLength(vector<pair<int, int>> &pairs)
{
    // sort the given pairs
    sort(pairs.begin(), pairs.end());
    return solve(0, -1, pairs);
}

int main()
{
    vector<pair<int, int>> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLength(pairs);
    return 0;
}