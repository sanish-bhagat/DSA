#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n)

int maxDotProduct(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();

    vector<long long> dp(n + 1, LLONG_MIN);

    dp[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= 1; j--)
        {

            // Calculate the maximum dot product at position j
            // by choosing between not including B[j-1] and including B[j-1]
            // Update dp[j] with the maximum value
            if (dp[j - 1] != LLONG_MIN)
                dp[j] = max(dp[j], dp[j - 1] + (1LL * a[i - 1] * b[j - 1]));
        }
    }

    return (int)dp[n];
}

int main()
{
    vector<int> a = {2, 3, 1, 7, 8};
    vector<int> b = {3, 6, 7};

    cout << maxDotProduct(a, b);

    return 0;
}