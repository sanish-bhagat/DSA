#include <bits/stdc++.h>
using namespace std;

//! TC is O(n logn)
//! SC is O(n)

int minDeletions(vector<int> &arr)
{
    int n = arr.size();
    vector<int> tails;

    for (int i = 0; i < n; i++)
    {
        // Binary search for first tail >= arr[i]
        int lo = 0, hi = tails.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (tails[mid] < arr[i])
                lo = mid + 1;
            else
                hi = mid;
        }

        // Extend LIS if arr[i] is greater than all tails
        if (lo == tails.size())
            tails.push_back(arr[i]);

        // Replace to maintain smallest possible tail
        else
            tails[lo] = arr[i];
    }

    return n - tails.size();
}

int main()
{
    vector<int> arr = {5, 6, 1, 7, 4};
    cout << minDeletions(arr) << endl;
    return 0;
}