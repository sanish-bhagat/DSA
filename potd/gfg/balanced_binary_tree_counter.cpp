#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;

//! TC is O(h)
//! SC is O(1)

int countBt(int h)
{
    // handle base cases
    if (h <= 1)
        return 1;

    long long prev1 = 1, prev2 = 1;

    // calculate the answer for each height
    for (int i = 2; i <= h; i++)
    {
        long long curr = ((prev1 * prev1 % MOD) + (2 * prev1 % MOD * prev2 % MOD)) % MOD;

        // update previous states
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int h = 3;
    cout << countBt(h);
}