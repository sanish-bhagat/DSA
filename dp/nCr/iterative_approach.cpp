#include <bits/stdc++.h>
using namespace std;

//! TC is O(r)
//! SC is O(1)

int nCr(int n, int r)
{
    // base case
    if (r > n)
        return 0;

    // base case
    if (r == 0 || n == 1)
        return 1;

    // nCr = nC(n - r), pick the smaller value of 'r'
    if (r > (n - r))
        r = n - r;

    long long res = 1;

    // iteratively calculate the coefficient -> nCr
    for (int i = 0; i < r; i++)
    {
        // res = (res * (n - i)) / (i + 1)
        res *= (n - i);
        res /= (i + 1);
    }

    return (int)res;
}

int main()
{
    int n = 5, r = 2;

    cout << "nCr = " << nCr(n, r) << endl;
    return 0;
}