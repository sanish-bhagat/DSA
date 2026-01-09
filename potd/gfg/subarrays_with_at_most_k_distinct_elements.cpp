#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(k)

int countAtMost(vector<int> &arr, int k)
{
    // {element, freq}
    unordered_map<int, int> mp;
    int left = 0, cnt = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        // insert the element in the map with its count frequency
        mp[arr[right]]++;

        // if we have more distincts elements tha required(k) ->
        // shrink the window from the left
        while (mp.size() > k)
        {
            mp[arr[left]]--;

            // remove the element from the window if count frequency becomes 0
            if (mp[arr[left]] == 0)
                mp.erase(arr[left]);

            // move the window from the left
            left++;
        }

        // no. of valid subarrays ending at right
        cnt += (right - left + 1);
    }

    return cnt;
}

int main()
{
    int k = 2;
    vector<int> arr = {1, 2, 2, 3};
    cout << countAtMost(arr, k);
}