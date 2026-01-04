#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int prev, vector<pair<int, int>> &pairs, vector<vector<int>> &memo)
{
    // base case: traversed all the pairs
    if (idx == pairs.size())
        return 0;

    // already computed subproblem
    if (memo[idx][prev + 1] != -1)
        return memo[idx][prev + 1];

    // case1: exclude the curr element
    int noTake = solve(idx + 1, prev, pairs, memo);

    // case2: include the curr element -> if it follows the last chosen pair
    int take = 0;
    if (prev == -1 || pairs[prev].second < pairs[idx].first)
        take = 1 + solve(idx + 1, idx, pairs, memo);

    // pick the max length
    return memo[idx][prev + 1] = max(take, noTake);
}

//! TC is O(n * n)
//! SC is O(n * n)

int maxChainLength(vector<pair<int, int>> &pairs)
{
    // sort the given pairs
    sort(pairs.begin(), pairs.end());

    int n = pairs.size();

    // 2d memo[] -> to store max length
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));

    return solve(0, -1, pairs, memo);
}

int main()
{
    vector<pair<int, int>> pairs = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLength(pairs);
    return 0;
}