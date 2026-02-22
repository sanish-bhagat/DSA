#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int subarrayXor(vector<int> &arr, int k)
{
    // {prefixXor, freq}
    unordered_map<int, int> mp;

    int prefixXor = 0, cnt = 0;

    // empty subarray case -> subarrays ending at index 0
    mp[0] = 1;

    for (int x : arr)
    {
        // include the element in the running XOR
        prefixXor ^= x;

        // check if there exists a prefixXor in the hashmap -> if yes then include the count
        int target = prefixXor ^ k;

        if (mp.find(target) != mp.end())
            cnt += mp[target];

        // update the freq of the curr prefiXor in the hashmap
        mp[prefixXor]++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;

    cout << subarrayXor(arr, k);
}