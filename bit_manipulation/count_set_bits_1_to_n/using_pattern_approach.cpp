#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

int countSetBits(int n)
{
    // increment n, as the pattern works good from(0 -> n)
    n++;

    int res = 0;

    // for each bit position
    for (int i = 0; i < 30; i++)
    {
        // size of pattern
        int size = (1 << (i + 1));

        // Mutiply total groups and set bits in each group.
        res += (n / size) * (size / 2);

        // bits in last grp
        int rem = n % size;

        // add set bits from last grp
        if (rem - size / 2 > 0)
            res += (rem - size / 2);
    }

    return res;
}

int main()
{
    int i = 3;
    cout << countSetBits(i);
    return 0;
}