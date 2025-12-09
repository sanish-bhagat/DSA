#include <bits/stdc++.h>
using namespace std;

#define MOD 10000000;

//! TC is O(2 ^ h)
//! SC is O(h)

long long countBT(int h)
{
    // base case: for 0 and 1 node trees its always trivially balanced
    if (h == 0 || h == 1)
        return 1;

    // recursively count the BBT in the subtrees
    long long x = countBT(h - 1);
    long long y = countBT(h - 2);

    // calculate the total no. of BBT explored in the subtrees
    return (x * x + 2 * x * y) % MOD;
}

int main()
{
    int h = 2;

    cout << countBT(h);
}