#include <bits/stdc++.h>
using namespace std;

int countWaysRec(int n, int k, vector<int> &memo)
{
    // base case
    if (n == 1)
        return k;

    // base case
    if (n == 2)
        return k * k;

    // already processed subproblem
    if (memo[n] != -1)
        return memo[n];

    // ways in which last fence is of different color
    int cnt1 = countWaysRec(n - 1, k, memo) * (k - 1);

    // ways in which last two fences are of same color
    int cnt2 = countWaysRec(n - 2, k, memo) * (k - 1);

    // store and return the total no. of ways
    return memo[n] = cnt1 + cnt2;
}

//! TC is O(n)
//! SC is O(n)

int countWays(int n, int k)
{
    // 1D[] to store already computed values
    vector<int> memo(n + 1, -1);

    return countWaysRec(n, k, memo);
}

int main()
{

    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}