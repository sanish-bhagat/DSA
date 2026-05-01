#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logk)
//! SC is O(n)

vector<int> kthLargest(vector<int> &arr, int k)
{
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> res;

    // traverse through the arr[]
    for (int i = 0; i < arr.size(); i++)
    {
        // push the curr element in the min heap
        pq.push(arr[i]);

        // stream size is < k -> push -1 to the res[]
        if (pq.size() < k)
        {
            res.push_back(-1);
            continue;
        }

        // pop the element to maintain k size stream window
        while (pq.size() > k)
            pq.pop();

        // push the kth largest element into the res[]
        if (pq.size() == k)
            res.push_back(pq.top());
    }

    return res;
}

int main()
{
    vector<int> arr = {3, 2, 1, 3, 3};
    int k = 2;

    vector<int> res = kthLargest(arr, k);
    for (int x : res)
        cout << x << " ";
}