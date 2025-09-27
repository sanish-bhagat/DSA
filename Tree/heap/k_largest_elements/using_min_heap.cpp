#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logk)
//! SC is O(k)

vector<int> kLargest(vector<int> arr, int k)
{
    // create a min heap of first k elements
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);

    // process other elements of arr[]
    for (int i = k; i < arr.size(); i++)
    {

        // if top of min heap is less than the curr element, then remove top and push arr[i]
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    vector<int> res;

    // push the elements of the min heap into res[]
    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    // reverse the res[] to return the elements in decreasing order
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    vector<int> res = kLargest(arr, k);
    for (int ele : res)
        cout << ele << " ";

    return 0;
}