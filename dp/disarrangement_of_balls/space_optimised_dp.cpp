#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int disarrange(int n)
{
    // base cases:
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    // base cases: for n == 2 -> 1 i.e (dp[2] = 1), n == 1 -> 0 i.e (dp[1] = 0)
    int prev1 = 1, prev2 = 0;

    // compute the total ways of valid disarrangements
    for (int i = 3; i <= n; i++)
    {
        // total possible ways for i elements
        int curr = (i - 1) * (prev1 + prev2);

        // update the values
        prev2 = prev1;
        prev1 = curr;
    }

    // return the total count of valid derangements
    return prev1;
}

int main()
{
    int n = 4;
    cout << disarrange(n);
    return 0;
}