#include <bits/stdc++.h>
using namespace std;

//! TC is O(1)
//! SC is O(1)

bool isSumOfConsecutive(int n)
{
    // base case
    if (n == 1)
        return false;

    // if n is power of two, it cannot be expressed as sum of consecutive no.s
    if ((n & (n - 1)) == 0)
        return false;

    // n can be expressed as a sum of consecutive no.s -> return true
    return true;
}

int main()
{
    int n = 24;
    cout << isSumOfConsecutive(n);
}