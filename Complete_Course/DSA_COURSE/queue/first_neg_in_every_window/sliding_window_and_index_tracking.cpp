#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

vector<int> firstNegInt(vector<int> &arr, int k)
{
    int firstNegIdx = 0;
    vector<int> res;
    int n = arr.size();

    for (int i = k - 1; i < n; i++)
    {
        // skip the elements that are +ve or out of the window
        while (firstNegIdx < i && (firstNegIdx <= i - k || arr[firstNegIdx] >= 0))
            firstNegIdx++;

        // push the element if it is -ve
        if (firstNegIdx < n && arr[firstNegIdx] < 0)
            res.push_back(arr[firstNegIdx]);
        else
            res.push_back(0);
    }

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