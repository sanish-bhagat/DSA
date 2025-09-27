#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

vector<int> maxOfSubarrays(vector<int> arr, int k)
{
    int n = arr.size();

    vector<int> res;

    priority_queue<pair<int, int>> pq;

    // push the first k elements into heap
    for (int i = 0; i < k; i++)
        pq.push({arr[i], i});

    // get the first max element of the window
    res.push_back(pq.top().first);

    // now process the other windows
    for (int i = k; i < n; i++)
    {
        pq.push({arr[i], i});

        // if element is out of window, pop it
        if (pq.top().second <= i - k)
            pq.pop();

        // push the max element of the window
        res.push_back(pq.top().first);
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res)
    {
        cout << maxVal << " ";
    }
    return 0;
}