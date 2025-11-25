#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int maxSumIS(vector<int> &arr)
{
    // key = value in arr, value = max sum ending
    // with that value or less than that value
    map<int, int> dp;
    int ans = 0;

    // itertate through the elements of the arr
    for (int val : arr)
    {
        // Find the best sum among all elements smaller than val,
        // lower bounds give the first value >= val
        auto it = dp.lower_bound(val);
        int bestSmaller = 0;
        if (it != dp.begin())
        {
            // gives the largest key > val(map ensures keys are sorted)
            it--;
            bestSmaller = it->second;
        }

        // best sum ending at the val
        int currSum = bestSmaller + val;

        // update dp[val] in map, if result is better
        if (dp[val] < currSum)
        {
            dp[val] = currSum;

            // remove states that can never lead to better solution
            auto higher = dp.upper_bound(val);
            while (higher != dp.end() && higher->second <= currSum)
                higher = dp.erase(higher);
        }

        // update ans
        ans = max(ans, currSum);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 101, 2, 3, 100};
    cout << maxSumIS(arr);
}