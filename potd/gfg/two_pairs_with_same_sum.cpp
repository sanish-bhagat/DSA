#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

vector<int> findPairs(vector<int> &arr)
{
    int n = arr.size();

    // hashmap -> {sum, pair of indices}
    unordered_map<int, pair<int, int>> mp;

    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // curr pair sum
            int sum = arr[i] + arr[j];

            // sum occurs for the first time -> make the entry in the hashmap
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = {i, j};
                continue;
            }

            // indices having the same pair sum
            int a = mp[sum].first;
            int b = mp[sum].second;

            // check for distinct indices
            if (a == i || a == j || b == i || b == j)
                continue;

            // curr quarduplet of indices
            vector<int> c = {a, b, i, j};

            // pick the lexicographically smaller quarduplet
            if (res.empty() || c < res)
                res = c;
        }
    }

    if (res.empty())
        return {-1, -1, -1, -1};

    return res;
}

int main()
{
    vector<int> arr = {3, 4, 7, 1, 2, 9, 8};
    vector<int> res = findPairs(arr);

    for (int x : res)
        cout << x << " ";
}