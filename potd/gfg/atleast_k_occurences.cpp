#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int firstElementKTime(vector<int> &arr, int k)
{
    unordered_map<int, int> freq;

    for (int x : arr)
    {
        freq[x]++;

        if (freq[x] == k)
            return x;
    }

    return -1;
}

int main()
{
    vector<int> arr = {3, 1, 3, 4, 5, 1, 3, 3, 5, 4};
    int k = 3;

    cout << firstElementKTime(arr, k);
}