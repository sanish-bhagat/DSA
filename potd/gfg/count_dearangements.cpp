#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int derangeCount(int n)
{
    // base case: only one position -> no possible disarrangement possible
    if (n == 1)
        return 0;

    // base case: two positions -> can swap them to make a valid disarrangement
    if (n == 2)
        return 1;

    // base cases: for n == 2 -> 1 i.e (dp[2] = 1), n == 1 -> 0 i.e (dp[1] = 0)
    int prev2 = 0, prev1 = 1;

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
    cout << derangeCount(n);
}