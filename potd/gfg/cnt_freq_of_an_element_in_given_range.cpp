#include <bits/stdc++.h>
using namespace std;

//! TC(n * logn + q * logk)
//! SC is O(n)

vector<int> freqInRange(vector<int> &arr, vector<vector<int>> &queries)
{
    // indexed map to store all indexes of the element
    map<int, vector<int>> idxMap;

    // build the indexed map
    for (int i = 0; i < arr.size(); i++)
        idxMap[arr[i]].push_back(i);

    vector<int> res;

    // process the queries
    for (auto q : queries)
    {
        int l = q[0], r = q[1], x = q[2];

        // target not present in the arr[] -> store freq cnt as 0
        if (idxMap.find(x) == idxMap.end())
        {
            res.push_back(0);
            continue;
        }

        // indexes of curr target
        vector<int> temp = idxMap[x];

        // find the first and last occuring index of the target in the curr range
        auto left = lower_bound(temp.begin(), temp.end(), l);
        auto right = upper_bound(temp.begin(), temp.end(), r);

        // use the indexes to calculate the freq cnt
        res.push_back(right - left);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 1, 2, 3};
    vector<vector<int>> queries = {
        {0, 4, 1},
        {2, 5, 2},
        {1, 6, 3},
        {0, 6, 5}};

    vector<int> ans = freqInRange(arr, queries);

    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
}