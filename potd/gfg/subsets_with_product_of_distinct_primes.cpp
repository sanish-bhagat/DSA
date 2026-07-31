#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Fast exponentiation
long long power(long long a, long long b)
{
    long long ans = 1;

    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

// Create prime mask for current number
int getMask(int num)
{
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int mask = 0;

    for (int i = 0; i < 10; i++)
    {
        int p = primes[i];
        int cnt = 0;

        while (num % p == 0)
        {
            cnt++;
            num /= p;
        }

        // repeated prime factor
        // invalid number
        if (cnt > 1)
            return -1;

        // store current prime in mask
        if (cnt == 1)
            mask |= (1 << i);
    }

    return mask;
}

//! TC is O(30 * 2^10)
//! SC is O(2^10)

int countSubsets(vector<int> &nums)
{
    // frequency of every number
    vector<int> freq(31, 0);

    for (int x : nums)
        freq[x]++;

    // number of ones
    int ones = freq[1];

    // dp[mask]
    // mask represents used prime factors
    vector<long long> dp(1024, 0);

    // empty subset
    dp[0] = 1;

    // process numbers from 2 to 30
    for (int num = 2; num <= 30; num++)
    {
        // number not present
        if (freq[num] == 0)
            continue;

        int currMask = getMask(num);

        // invalid number
        if (currMask == -1)
            continue;

        // reverse traversal
        // prevents overwriting current states
        for (int mask = 1023; mask >= 0; mask--)
        {
            // overlapping prime factor
            // cannot take together
            if ((mask & currMask) != 0)
                continue;

            dp[mask | currMask] =
                (dp[mask | currMask] +
                 dp[mask] * freq[num]) %
                MOD;
        }
    }

    long long ans = 0;

    // add all good subsets
    // skip empty subset (mask = 0)
    for (int mask = 1; mask < 1024; mask++)
        ans = (ans + dp[mask]) % MOD;

    // every valid subset can be combined
    // with any subset of ones
    ans = (ans * power(2, ones)) % MOD;

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};

    cout << countSubsets(arr);

    return 0;
}