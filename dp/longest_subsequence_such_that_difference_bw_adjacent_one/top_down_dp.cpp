#include <bits/stdc++.h>
using namespace std;

int helper(int idx, int prev, vector<int> &arr, vector<vector<int>> &memo)
{
    // base case: traversed all the elements -> return 0
    if (idx == arr.size())
        return 0;

    // already computed subproblem
    if (memo[idx][prev + 1] != -1)
        return memo[idx][prev];

    // exclude the curr element
    int exclude = helper(idx + 1, prev, arr, memo);

    // include the curr element in the sequence, if it satisfies the condition
    int include = 0;
    if (prev == -1 || abs(arr[idx] - arr[prev]) == 1)
        include = 1 + helper(idx + 1, idx, arr, memo);

    // store the max result in memo table
    return memo[idx][prev + 1] = max(exclude, include);
}

//! TC is O(n * n)
//! SC is O(n * n)

int longestSubseq(vector<int> &arr)
{
    int n = arr.size();

    // 2d memo[][]
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

    // recursive approach
    return helper(0, -1, arr, memo);
}

int main()
{

    vector<int> arr = {10, 9, 4, 5, 4, 8, 6};

    cout << longestSubseq(arr);

    return 0;
}