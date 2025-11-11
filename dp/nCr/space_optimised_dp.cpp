#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * r)
//! SC is O(r)

int nCr(int n, int r)
{
    // base case
    if (r > n)
        return 0;

    if (r == 0 || n == 1)
        return 1;

    // 1D array for dp
    int C[r + 1] = {0};
    C[0] = 1;

    // build the pascal's traingle, row based
    for (int i = 1; i <= n; i++)
    {
        // always pick the min 'r'
        for (int j = min(i, r); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }

    return C[r];
}

int main()
{
    int n = 5, r = 2;

    cout << "nCr = " << nCr(n, r) << endl;
    return 0;
}