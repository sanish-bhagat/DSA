#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(k)

vector<int> maxOfSubarrays(vector<int> &arr, int k)
{
    vector<int> res;

    deque<int> dq(k);

    int n = arr.size();

    // push the useful elements from first window
    // useful element is the element which is in curr window and 
    // is greater than all the elements in its right in curr window
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // process the other windows
    for (int i = k; i < n; i++)
    {

        // push the max element of the first window
        res.push_back(arr[dq.front()]);

        // check for out of window elements
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // check for useless element, and pop them
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // push the max element of the last window
    res.push_back(arr[dq.front()]);

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