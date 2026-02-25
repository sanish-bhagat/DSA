#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int longestSubarray(vector<int> &arr, int k)
{
    int ans = 0, sum = 0;

    // {prefix sum, first occ. index}
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        // +1
        if (arr[i] > k)
            sum++;

        // -1
        else
            sum--;

        // entire subarray is valid
        if (sum > 0)
            ans = i + 1;

        else
        {
            // sum - 1 present in hashmap ->
            // find earlier inidex where prefix was valid
            if (mp.find(sum - 1) != mp.end())
                ans = max(ans, i - mp[sum - 1]);
        }

        // store the first occurence of the prefix sum
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }

    return ans;
}

int main()
{
    int k = 2;
    vector<int> arr = {1, 2, 3, 4, 1};
    cout << longestSubarray(arr, k);
}