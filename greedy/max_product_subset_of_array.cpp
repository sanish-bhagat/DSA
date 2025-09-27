#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

long long int maxProductSubset(int arr[], int n)
{
    const long long MOD = 1e9 + 7;

    // Case 1: Single element → return as is
    if (n == 1)
        return arr[0];

    long long prod = 1;
    int negCount = 0, zeroCount = 0;
    int maxNeg = INT_MIN; // largest negative (closest to zero)

    // count the occurences of zeros, -ve elements and
    // calculate the product
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
            continue;
        }
        if (arr[i] < 0)
        {
            negCount++;
            maxNeg = max(maxNeg, arr[i]);
        }
        prod = (prod * (arr[i] % MOD + MOD) % MOD) % MOD;
    }

    // Case 2: all zeros
    if (zeroCount == n)
        return 0;

    // Case 3: only one negative and rest are zeros
    if (negCount == 1 && (negCount + zeroCount == n))
        return 0;

    // Case 4: odd count of negatives → exclude one with smallest abs value
    if (negCount & 1)
    {
        // skip the max_neg and calculate the product
        prod = 1;
        bool skipped = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                continue;
            if (!skipped && arr[i] == maxNeg)
            {
                skipped = true; // skip once
                continue;
            }
            prod = (prod * (arr[i] % MOD + MOD) % MOD) % MOD;
        }
    }

    return (prod % MOD + MOD) % MOD;
}

int main()
{
    int a[] = {-1, -1, -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}