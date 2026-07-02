#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k)
//! SC is O(k)

bool divisibleByK(vector<int> &arr, int k)
{
    int n = arr.size();

    // base case: no. of elements > k -> return true, according to pigeon hole principle
    if (n > k)
        return true;

    // Stores achievable remainders modulo k
    vector<bool> dp(k, false);

    for (int i = 0; i < n; i++)
    {
        // Subset with divisible sum found
        if (dp[0])
            return true;

        vector<bool> temp(k, false);

        // Extend existing remainders
        for (int j = 0; j < k; j++)
        {

            if (dp[j] && !dp[(j + arr[i]) % k])
                temp[(j + arr[i]) % k] = true;
        }

        // Update dp with new remainders
        for (int j = 0; j < k; j++)
            if (temp[j])
                dp[j] = true;

        // single element subset
        dp[arr[i] % k] = true;
    }

    return dp[0];
}

int main()
{
    vector<int> arr = {1, 7};
    int k = 5;

    divisibleByK(arr, k) ? cout << "true" : cout << "false";

    return 0;
}