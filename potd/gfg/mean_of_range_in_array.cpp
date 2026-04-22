#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + q)
//! SC is O(n)

vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();

    // prefix sum[]
    vector<int> prefix(n + 1, 0);

    // build the prefix[]
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i - 1];

    vector<int> res;

    // iterate through queries and find the mean for each one
    for (auto it : queries)
    {
        // curr range
        int i = it[0], j = it[1];

        // mean = sum of elements in range / total elements in the range
        int mean = (prefix[j + 1] - prefix[i]) / (j - i + 1);

        res.push_back(mean);
    }

    return res;
}

int main()
{
    vector<int> arr = {6, 7, 8, 10};
    vector<vector<int>> queries = {{0, 3}, {1, 2}};

    vector<int> res = findMean(arr, queries);

    for (int x : res)
        cout << x << " ";
}