#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int cntSubarrays(vector<int> &arr, int k)
{
    // hash map
    unordered_map<int, int> mp;

    // base case: represnts the empty prefix before the arr[] starts
    // so that the subarrays starting at index 0 can be counted
    mp[0] = 1;

    int cnt = 0;
    int prefixSum = 0;

    // traverse through the given arr[]
    for (int x : arr)
    {

        // 0 -> even, 1 -> odd, this helps reduce the problem to
        // count subarrays with sum == k
        prefixSum += (x % 2);

        // include the count of subarrays that have appeared with the prefixSum before
        if (mp.find(prefixSum - k) != mp.end())
            cnt += mp[prefixSum - k];

        // increment the freq count of curr prefixSum
        mp[prefixSum]++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1, 1, 2, 1};
    int k = 2;

    cout << cntSubarrays(arr, k);
}