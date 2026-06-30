#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int minInsAndDel(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();

    // hashmap to map element with its index
    unordered_map<int, int> mp;

    for (int i = 0; i < m; i++)
        mp[b[i]] = i;

    // store mapped indices, if element present in b
    vector<int> v;
    for (int x : a)
    {
        if (mp.count(x))
            v.push_back(mp[x]);
    }

    // store longest increasing subsequence(LIS)
    vector<int> lis;
    for (int x : v)
    {
        // find first position
        auto it = lower_bound(lis.begin(), lis.end(), x);

        // insert element
        if (it == lis.end())
            lis.push_back(x);

        // replace element
        else
            *it = x;
    }

    int len = lis.size();

    // store final answer
    int res = (n - len) + (m - len);

    return res;
}

int main()
{
    vector<int> a = {1, 2, 5, 3, 1};
    vector<int> b = {1, 3, 5};

    cout << minInsAndDel(a, b);

    return 0;
}