#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int equalSumSpan(vector<int> &a1, vector<int> &a2)
{
    int n = a1.size();

    // diff[]
    vector<int> diff(2 * n + 1, -1);

    // respective preifxSums for both arrays
    int prefixSum1 = 0, prefixSum2 = 0;

    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        // update the running prefixSums
        prefixSum1 += a1[i];
        prefixSum2 += a2[i];

        // find the currDiff
        int currDiff = prefixSum1 - prefixSum2;

        // handle the -ve case
        int index = currDiff + n;

        // diff == 0 -> entire subarray from 0 to i has equal sum
        if (currDiff == 0)
            maxLen = max(maxLen, i + 1);

        // this diff has already seen before
        else if (diff[index] != -1)
            maxLen = max(maxLen, i - diff[index]);

        // store the first occurence of this diff
        else
            diff[index] = i;
    }

    // return the longest span
    return maxLen;
}

int main()
{
    vector<int> a1 = {0, 1, 0, 0, 0, 0}, a2 = {1, 0, 1, 0, 0, 1};

    cout << equalSumSpan(a1, a2);
}