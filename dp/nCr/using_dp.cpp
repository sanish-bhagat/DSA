#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * r)
//! SC is O(n * r)

int nCr(int n, int r)
{
    // base case
    if (r > n)
        return 0;

    // base case
    if (r == 0 || n == 1)
        return 1;

    // 2D matrix for dp
    int C[n + 1][r + 1];

    // build the pascal's triangle
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            // base case -> fill with 1(first column and last column, of the row)
            if (j == 0 || j == i)
                C[i][j] = 1;

            // pascal's identity -> C(n, r) = C(n - 1, r - 1) + C(n - 1, r)
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][r];
}

int main()
{
    int n = 5, r = 2;

    cout << "nCr = " << nCr(n, r) << endl;
    return 0;
}