#include <bits/stdc++.h>
using namespace std;

#define MOD 10000000

long long countBTRec(int h, vector<long long> &memo)
{

    // base case: for 0 and 1 node trees its always trivially balanced
    if (h == 0 || h == 1)
        return 1;

    // already computed subproblem for this height
    if (memo[h] != -1)
        return memo[h];

    // recursively count the BBT in the subtrees
    long long x = countBTRec(h - 1, memo);
    long long y = countBTRec(h - 2, memo);

    // calculate the total no. of BBT explored in the subtrees
    return memo[h] = (x * x + 2 * x * y) % MOD;
}

//! TC is O(h)
//! SC is O(h)

long long countBT(int h)
{
    // 1d memo[] to keep track of BBT count based on height
    vector<long long> memo(h + 1, -1);

    return countBTRec(h, memo);
}

int main()
{
    int h = 2;
    cout << countBT(h);
}