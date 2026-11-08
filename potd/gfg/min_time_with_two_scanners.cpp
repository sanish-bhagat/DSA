#include <bits/stdc++.h>
using namespace std;

bool isPossible(int s1, int s2, int n, int mid)
{
    // totals docs both scanners can scan in mid time
    long long docs = (mid / s1) + (mid / s2);

    return docs >= n;
}

//! TC is O(log n)
//! SC is O(1)

int minTime(int s1, int s2, int n)
{
    // base case
    if (n == 1)
        return min(s1, s2);

    // binary search range
    long long low = 1, high = min(s1, s2) * n;

    long long res = high;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        // valid time -> try to minimise
        if (isPossible(s1, s2, n, mid))
        {
            res = mid;
            high = mid - 1;
        }

        // try to take more time to scan all docs
        else
            low = mid + 1;
    }

    return res;
}

int main()
{
    int n = 44, s1 = 99, s2 = 2;

    cout << minTime(s1, s2, n);
}