#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

int findPosition(int n)
{
    // if no. is not a power of 2, it contains more than one bit set to '1' -> return -1
    if (n == 0 || (n & (n - 1)) != 0)
        return -1;

    // log2() -> gives the value of m in (2 ^ m) 
    return log2(n) + 1;
}

int main()
{
    int n = 16;
    cout << findPosition(n);
    return 0;
}