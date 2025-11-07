#include <bits/stdc++.h>
using namespace std;

//! TC is O(r)
//! SC is O(1)

int copySetBits(int x, int y, int l, int r)
{
    // ints are stored using 32 bits
    if (l < 1 || r > 32)
        return x;

    // traverse in range
    for (int i = l; i <= r; i++)
    {
        // find a mask(a no. whose only set bit is at the i-th position)
        int mask = 1 << (i - 1);

        // if i-th bit set in y, set i-th bit in x also
        if (y & mask)
            x = x | mask;
    }

    // return the modified x
    return x;
}

int main()
{
    unsigned x = 10, y = 13, l = 1, r = 32;
    int res = copySetBits(x, y, l, r);
    cout << "Modified x is " << res;
    return 0;
}