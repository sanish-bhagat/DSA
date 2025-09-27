#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logk)
//! SC is O(n)

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> res;

    // min heap -> {arr[element], {arr-index, element-index}}
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    // push the first element of every k sorted array into the min heap
    for (int i = 0; i < k; i++)
    {
        if (!arr[i].empty())
            pq.push({arr[i][0], {i, 0}});
    }

    // process all arrays using min heap
    while (!pq.empty())
    {
        // get the smallest element among all the arrays
        auto top = pq.top();
        pq.pop();

        // get the element, arr-index, element-index
        int val = top.first;
        int i = top.second.first;
        int j = top.second.second;

        res.push_back(val);

        // push the next element of the popped element from the same arr[] into the the min-heap
        if (j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], {i, j + 1}});
    }

    return res;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7},
                               {2, 4, 6, 8},
                               {0, 9, 10, 11}};

    int k = 3;
    vector<int> res = mergeKArrays(arr, k);

    // Print the array elements
    for (int val : res)
    {
        cout << val << " ";
    }

    return 0;
}