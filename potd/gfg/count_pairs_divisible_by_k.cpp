#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(k)

int countKdivPairs(vector<int> &arr, int k)
{
    // hashmap to store -> {rem, freq}
    unordered_map<int, int> mp;

    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        // remainder of curr element
        int rem = arr[i] % k;

        // handle -ve rem case, the rem should lie in range [0...k-1]
        if (rem < 0)
            rem += k;

        // the target rem we are looking for
        int target = (k - rem) % k;

        // target present -> means pairs exists that is divisble by k -> include its count
        if (mp.count(target))
            cnt += mp[target];

        // include the rem in hashmap
        mp[rem]++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {2, 2, 1, 7, 5, 3};
    int k = 4;

    cout << countKdivPairs(arr, k);

    return 0;
}