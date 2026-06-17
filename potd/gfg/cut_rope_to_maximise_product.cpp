#include <bits/stdc++.h>
using namespace std;

//! TC is O(log n)
//! SC is O(1)

int maxProduct(int n)
{
    // base case
    // Rope of length 2 or 3 must be cut at least once
    if (n == 2 || n == 3)
        return n - 1;

    int product = 1;

    // Keep cutting parts of length 3
    // while remaining length is greater than 4
    while (n > 4)
    {
        product *= 3;

        // reduce rope length by 3
        n -= 3;
    }

    // multiply remaining rope length
    return product * n;
}

int main()
{
    int n = 5;
    cout << maxProduct(n);
}