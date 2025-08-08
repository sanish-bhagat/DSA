#include <bits/stdc++.h>
using namespace std;

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    int i = 0, j = 0;

    vector<int> res;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }

    while (i < n)
    {
        res.push_back(a[i]);
        i++;
    }

    while (j < m)
    {
        res.push_back(b[j]);
        j++;
    }

    return res;
}

vector<int> mergeK(vector<vector<int>> arr, int low, int high)
{
    if (low == high)
        return arr[low];

    // divide the array into two halves until the arr[[]] are not reduced to individual arr[]
    int mid = (low + high) / 2;

    vector<int> left = mergeK(arr, low, mid);
    vector<int> right = mergeK(arr, mid + 1, high);

    // merge the two individual arr[], using merge sort
    return mergeArrays(left, right);
}

//! TC is O(n * k logk)
//! SC is O(n * k)

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    if (k == 0)
        return {};

    return mergeK(arr, 0, k - 1);
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