#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(1)

vector<int> missingRange(vector<int> &arr, int low, int high)
{
    // sort the arr[] in increasing order
    sort(arr.begin(), arr.end());

    vector<int> res;

    // our starting of range, behaves as previous element
    int prev = low;

    // traverse through the sorted arr[]
    for (int num : arr)
    {
        // curr element is not in range -> skip
        if (num < low || num > high)
            continue;

        // curr element > prev -> include elements of (prev...num - 1) in result
        // missing element of the range
        if (num > prev)
            for (int i = prev; i < num; i++)
                res.push_back(i);

        // update prev element for future
        prev = num + 1;
    }

    // push the remaining missing elements of the range
    for (int i = prev; i <= high; i++)
        res.push_back(i);

    return res;
}

int main()
{
    vector<int> arr = {10, 12, 11, 15};
    int low = 10, high = 15;

    vector<int> res = missingRange(arr, low, high);

    for (int num : res)
        cout << num << " ";
}