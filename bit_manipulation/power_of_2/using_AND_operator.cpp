#include <bits/stdc++.h>
using namespace std;

//! TC is O(1)
//! SC is O(1)

bool isPowerofTwo(int n)
{
    if (n <= 0)
        return false;

    // 'n' will have only one set bit to 1
    // 'n - 1' will have all bits to the right of that bit set to 1
    // n & (n - 1) -> will always give 0, if 'n' is a power of 2
    return (n & (n - 1)) == 0;
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