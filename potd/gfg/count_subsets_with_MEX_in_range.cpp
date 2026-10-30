#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + r)
//! SC is O(n)

int cntSubsets(vector<int> &arr, int l, int r)
{
    const long long M = 1000000007;
    int n = arr.size();

    unordered_map<int, int> mp;
    for (int num : arr)
    {
        mp[num]++;
    }

    // Precompute powers of 2 modulo M.
    vector<long long> power(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        power[i] = (power[i - 1] * 2) % M;
    }

    long long res = 0;
    long long cur = 1;
    int seen = 0;

    // Ensure every value smaller than l is present.
    for (int i = 0; i < l; i++)
    {
        int freq = mp[i];

        if (freq == 0)
        {
            return 0;
        }

        seen += freq;
        cur = (cur * (power[freq] - 1 + M)) % M;
    }

    // Count subsets for each possible MEX.
    for (int i = l; i <= r; i++)
    {
        int freq = mp[i];

        long long here = (cur * power[n - seen - freq]) % M;
        res = (res + here) % M;

        // No larger MEX is possible if i is absent.
        if (freq == 0)
        {
            return res;
        }

        seen += freq;
        cur = (cur * (power[freq] - 1 + M)) % M;
    }

    return (int)res;
}

int main()
{
    vector<int> arr = {2, 0, 1, 0};
    int l = 1, r = 2;

    cout << cntSubsets(arr, l, r) << "\n";

    return 0;
}