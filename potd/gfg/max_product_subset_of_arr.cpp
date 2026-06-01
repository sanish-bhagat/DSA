#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int findMaxProduct(vector<int> &arr)
{
    int n = arr.size();

    // base case
    if (n == 1)
        return arr[0];

    // cnt no. of zeros and negative values
    // we skip zeros from our result subset
    // and wew take only even no. of -ve's for our subset,
    // if odd cnt we remove the one with the lowest abs value
    int zeroCnt = 0, negCnt = 0;
    int maxNeg = INT_MIN, idxMaxNeg = -1;

    long long ans = 1;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        // zero present
        if (arr[i] == 0)
            zeroCnt++;

        // handle -ve no's
        else if (arr[i] < 0)
        {
            negCnt++;

            // keep track of the -ve no. which could be excluded
            if (idxMaxNeg == -1 || arr[i] > maxNeg)
            {
                maxNeg = arr[i];
                idxMaxNeg = i;
            }
        }
    }

    // base cases
    if (zeroCnt == n)
        return 0;

    if (negCnt == 1 && zeroCnt == n - 1)
        return 0;

    // build the max product subset
    for (int i = 0; i < n; i++)
    {
        // skip 0's
        if (arr[i] == 0)
            continue;

        // skip the -ve no. with the least abs value, if we have odd cnt
        if ((negCnt % 2 == 1) && idxMaxNeg == i)
            continue;

        // handle the overflow
        ans = ((1LL * ans * arr[i]) % mod + mod) % mod;
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, -2, 4, 3};
    cout << findMaxProduct(arr);
}