#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

bool isPowerofTwo(int n)
{
    if (n <= 0)
        return false;

    int count = 0;

    // count the no. of set bits in 'n'
    while (n > 0)
    {
        if (n & 1)
            count++;

        n = n >> 1;
    }

    // if only set bit is present in 'n' this means it is a power of 2
    return count == 1;
}

int main()
{
    int n = 15;
    if (isPowerofTwo(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}