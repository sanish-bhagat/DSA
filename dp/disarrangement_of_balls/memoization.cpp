#include <bits/stdc++.h>
using namespace std;

int disarrangeRec(int n, vector<int> &memo)
{
    // base cases
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    // already computed subproblem
    if (memo[n] != -1)
        return memo[n];

    // case1:
    int placed = disarrangeRec(n - 1, memo);

    // case2:
    int notPlaced = disarrangeRec(n - 2, memo);

    // total ways:
    return memo[n] = (n - 1) * (placed + notPlaced);
}

//! TC is O(n)
//! SC is O(n)

int disarrange(int n)
{
    // 1d memo[] -> stores the total ways count for every i elements
    vector<int> memo(n + 1, -1);

    return disarrangeRec(n, memo);
}

int main()
{
    int n = 4;
    cout << disarrange(n);
    return 0;
}