#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int MOD = 1e9 + 7;

    int power(long long a, long long b)
    {
        int ans = 1;

        while (b)
        {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

public:
    //! TC is O(n)
    //! SC is O(1)
    int computeValue(int n)
    {
        long long fact1 = 1, fact2 = 1;

        // compute (2n)!
        for (int i = 1; i <= 2 * n; i++)
            fact1 = (fact1 * i) % MOD;

        // compute n!
        for (int i = 1; i <= n; i++)
            fact2 = (fact2 * i) % MOD;

        long long denom = (fact2 * fact2) % MOD;

        // use combinatorics formula to find the total valid sequences
        long long ans = (fact1 * power(denom, MOD - 2)) % MOD;

        return ans;
    }
};

int main()
{
    int n = 2;

    class Solution sol;

    cout << sol.computeValue(n);
}