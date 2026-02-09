#include <bits/stdc++.h>
using namespace std;

//! TC is O(logn)
//! SC is O(1)

int findKRotation(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;

    // binary search on rotated sorted array =>
    // rotation = index of min element
    while (left < right)
    {
        int mid = left + (right - left) / 2;

        // min is in right part
        if (arr[mid] > arr[right])
            left = mid + 1;

        // min is in left part
        else
            right = mid;
    }

    // return the index of min element as the no. of rotations
    return left;
}

int main()
{
    vector<int> arr = {5, 1, 2, 3, 4};

    cout << findKRotation(arr);
}