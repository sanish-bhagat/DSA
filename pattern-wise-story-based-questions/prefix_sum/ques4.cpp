// A company tracks employee productivity:

// 1 → productive day
// 0 → unproductive day

// They want:

// “Longest period where productive and unproductive days are equal”

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int longestPeriod(vector<int> &arr)
{
    // hashmap, {sum, first occ index}
    unordered_map<int, int> mp;

    // sum 0 appears at index -1
    mp[0] = -1;

    int sum = 0, maxLen = 0;

    // traverse through the elements of the arr[]
    for (int i = 0; i < arr.size(); i++)
    {
        // include the curr element in the running prefix sum
        sum += (arr[i] == 0) ? -1 : 1; 

        // sum == 0 -> whole subarray is valid
        if (sum == 0)
            maxLen = max(maxLen, i + 1);

        // sum already exists in hashmap -> this means a subarray is present whose sum == 0
        if (mp.count(sum))
            maxLen = max(maxLen, i - mp[sum]);

        // include the first occ. of the sum
        else
            mp[sum] = i;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {1, 0, 1, 1, 0, 0, 1};
    cout << longestPeriod(arr);
}