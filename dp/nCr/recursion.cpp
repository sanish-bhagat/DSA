#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(n)

int nCr(int n, int r)
{
    if (r > n)
        return 0;

    if (r == 0 || n == 1)
        return 1;

    // based on pascal's triangle
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    int n = 5, r = 2;

    cout << "nCr = " << nCr(n, r) << endl;
    return 0;
}