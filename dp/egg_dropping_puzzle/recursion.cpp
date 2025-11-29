#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

int eggDrop(int n, int k)
{
    // base case: less than or equal to one floor
    if (k == 1 || k == 0)
        return k;

    // base case: only one egg left
    if (n == 1)
        return k;

    int res = INT_MAX;

    // iterate through every floor, consider dropping for every floor from 1 to k
    for (int i = 1; i <= k; i++)
    {
        // pick the max b/w
        // 1. either egg breaked from the curr floor, move to  the lower floor with one less egg
        // 2.  or egg does not broke then move to the higher floors with the same no. of eggs
        int curr = 1 + max(eggDrop(n - 1, i - 1), eggDrop(n, k - i));

        // pick the min of the max ones
        if (curr < res)
            res = curr;
    }

    return res;
}

int main()
{
    int n = 2, k = 10;
    cout << eggDrop(n, k);
    return 0;
}