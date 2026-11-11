#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

bool checkWithinK(vector<int> &arr, int k)
{
    // stores the indices of the element
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        // duplicate element exists and valid diff -> return true
        if (mp.count(arr[i]) && i - mp[arr[i]] <= k)
            return true;

        // mark the entry
        mp[arr[i]] = i;
    }

    return false;
}

int main()
{
    vector<int> arr = {10, 2, 3, 4, 10, 5};
    int k = 3;

    cout << checkWithinK(arr, k);
}