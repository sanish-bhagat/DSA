#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

int findPosition(int n)
{
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    int pos = 1;

    // process until 'n' becomes 1
    while ((n & 1) == 0)
    {
        // keep dividing 'n' by 2
        n = n >> 1;
        pos++;
    }

    return pos;
}

int main()
{
    int n = 16;
    cout << findPosition(n);
    return 0;
}