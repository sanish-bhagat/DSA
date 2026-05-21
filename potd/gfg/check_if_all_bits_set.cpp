#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

bool isBitSet(int n)
{
    // base case
    if (n == 0)
        return false;

    while (n > 0)
    {
        // not a set bit -> return false
        if ((n & 1) == 0)
            return false;

        // right shift
        n = n >> 1;
    }

    // all bits are set bit
    return true;
}

int main()
{
    int n = 7;
    cout << isBitSet(n);
}