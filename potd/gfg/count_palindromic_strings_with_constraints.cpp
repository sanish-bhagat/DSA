#include <bits/stdc++.h>
using namespace std;

//! TC is O(k * k)
//! SC is O(k * k)

int palindromicStrings(int n, int k)
{
    int MOD = 1e9 + 7;

    long long nPr[k + 1][k + 1];

    memset(nPr, 0, sizeof(nPr));

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // Base case
            if (j == 0)
                nPr[i][j] = 1;

            // Calculate using previously stored values
            else
                nPr[i][j] = (nPr[i - 1][j] % MOD + (j * nPr[i - 1][j - 1]) % MOD) % MOD;
        }
    }

    long long res = 0;

    // Add ways for odd and even length palindromes
    for (int i = 1; i <= n / 2; i++)
        res = (res + nPr[k][i]) % MOD;

    res = (res * 2) % MOD;

    // Add the extra odd length when n is odd
    if (n & 1)
        res = (res + nPr[k][n / 2 + 1]) % MOD;

    return (int)res;
}

int main()
{
    int n = 4;
    int k = 3;

    cout << palindromicStrings(n, k) << endl;

    return 0;
}