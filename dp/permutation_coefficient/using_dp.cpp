#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(n * k)

int permutationCoeff(int n, int k)
{
    // 2d dp[][] -> store the previously computed subproblems result
    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            // if col == 0 -> set the cell value to 1
            if (j == 0)
                dp[i][j] = 1;

            // fill the cell using the previously computed subproblems
            else
            {
                dp[i][j] = dp[i - 1][j] + (j * dp[i - 1][j - 1]);
            }

            // P(i, j) = 0 for j > i
            dp[i][j + 1] = 0;
        }
    }

    return dp[n][k];
}

int main()
{
    int n = 10, k = 2;
    cout << "Value of P(" << n << " " << k << ") is " << permutationCoeff(n, k);

    return 0;
}