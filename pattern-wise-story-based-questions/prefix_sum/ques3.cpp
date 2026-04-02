// A person tracks daily calorie difference:

// Positive → surplus
// Negative → deficit

// They want:

// “Longest continuous period where total calories = 0”

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int longestPeriod(vector<int> &arr)
{
    // subarray sum -> first occurence
    unordered_map<int, int> mp;

    int sum = 0;

    int maxLen = 0;

    // base case: subarray sum == 0, occurs at index -1
    mp[0] = -1;

    // traverse through the elements of the arr[]
    for (int i = 0; i < arr.size(); i++)
    {
        // include the curr element in the ruuning sum
        sum += arr[i];

        // subarray sum repeats again -> curr subarray has sum == 0-> update the maxLen subarray
        if(mp.count(sum))
            maxLen = max(maxLen, i - mp[sum]);
        
        // store the 1st occurence of the subarray sum
        else
            mp[sum] = i;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {1, -1, 3, 2, -2, -3, 3};
    cout << longestPeriod(arr);
}