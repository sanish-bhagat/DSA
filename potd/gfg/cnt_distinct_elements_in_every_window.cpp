#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(k)

vector<int> countDistinct(vector<int> &arr, int k)
{
    // stores {element, frequency} in every window
    unordered_map<int, int> mp;
    vector<int> ans;

    // 1st window
    for (int i = 0; i < k; i++)
        mp[arr[i]]++;

    // no. of elements present in the mp as key will be the count of distinct elements in the curr window
    ans.push_back(mp.size());

    // traverse the other windows
    for (int i = k; i < arr.size(); i++)
    {
        // exclude the frequency of element from the previous window
        mp[arr[i - k]]--;

        // if freq of element becomes 0 -> this means this element is not present in the curr window ->
        // remove from the mp(curr window)
        if (mp[arr[i - k]] == 0)
            mp.erase(arr[i - k]);

        // include the curr element in the window
        mp[arr[i]]++;

        // store the count of distinct elements in curr window
        ans.push_back(mp.size());
    }

    return ans;
}

int main()
{
    int k = 4;
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};

    vector<int> res = countDistinct(arr, k);

    for (int x : res)
        cout << x << " ";
}