#include <bits/stdc++.h>
using namespace std;

int lisRec(vector<int> &arr, int idx, vector<int> &memo)
{
    // base case -> if first element then include it in the subsequence(since, no elements in left of it)
    if (idx == 0)
        return 1;

    // already computed subproblem
    if (memo[idx] != -1)
        return memo[idx];

    int mx = 1;

    // include smaller elements in left of idx
    for (int prev = 0; prev < idx; prev++)
        if (arr[prev] < arr[idx])
            mx = max(mx, lisRec(arr, prev, memo) + 1);

    // return the max length fo subsequence till idx
    return memo[idx] = mx;
}

//! TC is O(n * n)
//! SC is O(n)

int lis(vector<int> &arr)
{
    int n = arr.size();

    // 1d memo[] to keep track of computed results
    vector<int> memo(n, -1);

    int res = 1;

    // for every i check for smaller elements at its left -> considering it as a new subsequence 
    for (int i = 1; i < n; i++)
        res = max(res, lisRec(arr, i, memo));

    return res;
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << lis(arr);
    return 0;
}