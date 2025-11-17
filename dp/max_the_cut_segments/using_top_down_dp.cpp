#include <bits/stdc++.h>
using namespace std;

int maxCutHelper(int n, int x, int y, int z, vector<int> &memo)
{
    // base case
    if (n == 0)
        return 0;

    // base case -> on dividing the rod, length becomes negative -> invlaid cut
    if (n < 0)
        return -1;

    // already computed subproblem
    if (memo[n] != -1)
        return memo[n];

    // try all the three ways to cut the rod
    int cut1 = maxCutHelper(n - x, x, y, z, memo);
    int cut2 = maxCutHelper(n - y, x, y, z, memo);
    int cut3 = maxCutHelper(n - z, x, y, z, memo);

    // pick the maximum cut segment
    int maxi = max(cut1, max(cut2, cut3));

    // invalid cut
    if (maxi == -1)
        return memo[n] = -1;

    return memo[n] = 1 + maxi;
}

//! TC is O(n)
//! SC is O(n)

int maximizeTheCuts(int n, int x, int y, int z)
{
    // 1D[] memo to store computed results
    vector<int> memo(n + 1, -1);

    int res = maxCutHelper(n, x, y, z, memo);

    return (res == -1) ? -1 : res;
}

int main()
{

    int n = 11;
    int x = 2, y = 3, z = 5;

    cout << maximizeTheCuts(n, x, y, z);

    return 0;
}