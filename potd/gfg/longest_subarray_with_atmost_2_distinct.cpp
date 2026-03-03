#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int LongestSubarray(vector<int> &arr)
{
    // {element, count freq}
    unordered_map<int, int> mp;

    int left = 0, maxLen = 0;

    // traverse through the arr[] in a sliding window manner
    for (int right = 0; right < arr.size(); right++)
    {
        // expand window -> include the curr element
        mp[arr[right]]++;

        // shrink the window -> until the window becomes valid
        while (mp.size() > 2)
        {
            // remove the element from map
            mp[arr[left]]--;

            // erase the element if having 0 freq count
            if (mp[arr[left]] == 0)
                mp.erase(arr[left]);

            // shrink
            left++;
        }

        // update the maxLen
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {3, 1, 2, 2, 2, 2};
    cout << LongestSubarray(arr);
}