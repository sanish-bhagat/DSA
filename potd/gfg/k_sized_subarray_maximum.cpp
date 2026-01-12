#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(k)

vector<int> maxOfSubarrays(vector<int> &arr, int k)
{
    // store the indices of the elements
    deque<int> dq;
    vector<int> ans;

    // traverse through arr[]
    for (int i = 0; i < arr.size(); i++)
    {
        // remove elements that are out of the window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // remove smaller elements -> as they are of no use
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        // push curr element index
        dq.push_back(i);

        // start adding elements when the window size is k
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }

    return ans;
}

int main()
{
    int k = 3;
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> ans = maxOfSubarrays(arr, k);

    for (int x : ans)
        cout << x << " ";
}