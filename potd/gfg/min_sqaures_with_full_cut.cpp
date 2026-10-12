#include <bits/stdc++.h>
using namespace std;

//! TC is O(log min(n, m))
//! SC is O(1)

int minSquares(int n, int m)
{
    int res = 0;

    // continue until the rectangle becomes empty
    while (n > 0 && m > 0)
    {
        // make n the larger dimension
        if (n < m)
            swap(n, m);

        // count all possible squares of size m * m
        res += (n / m);

        // keep the remaining rectangles
        n %= m;
    }

    return res;
}

int main()
{
    int n = 4, m = 5;
    cout << minSquares(n, m) << endl;

    return 0;
}