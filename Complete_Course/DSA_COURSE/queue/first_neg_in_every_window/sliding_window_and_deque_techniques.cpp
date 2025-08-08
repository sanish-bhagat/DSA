#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(k)

vector<int> firstNegInt(vector<int> &arr, int k)
{
    deque<int> dq;
    vector<int> res;
    int n = arr.size();

    // push the -ve elements of the first window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            dq.push_back(i);
    }

    // process the rest of the lements
    for (int i = k; i < n; i++)
    {
        // the current front index is the index of the -ve element of the curr window
        //if it exists then push the -ve element into the res array
        if (!dq.empty())
            res.push_back(arr[dq.front()]);

        else
            res.push_back(0);

        // remove the elements that are out of the window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // push the curr element if it is -ve
        if (arr[i] < 0)
            dq.push_back(i);
    }

    // process the last window
    if (!dq.empty())
        res.push_back(arr[dq.front()]);
    else
        res.push_back(0);

    return res;
}

int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};

    int k = 3;
    vector<int> res = firstNegInt(arr, k);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i < res.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
    return 0;
}