#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

int findPosition(int n)
{
    // if no. is not a power of 2, it contains more than one bit set to '1' -> return -1
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    int val = 1, pos = 1;

    // process until res is non-zero
    while ((val & n) == 0)
    {
        // left shift on val(multiply by 2)
        val = val << 1;

        // increment the pos
        pos++;
    }

    // return the position of the set bit
    return pos;
}

int main()
{
    int n = 16;
    cout << findPosition(n);
    return 0;
}