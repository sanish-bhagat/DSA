#include <bits/stdc++.h>
using namespace std;

//! TC is O(n logn)
//! SC is O(1)

vector<int> lexicographicallyLargest(vector<int> &arr)
{
    int n = arr.size();

    int i = 0;

    // process each maximal contiguous subarray having the same parity
    while (i < n)
    {
        int j = i + 1;

        // keep on expanding until same parity
        while (j < n && arr[j] % 2 == arr[j - 1] % 2)
            j++;

        // sort the curr subarray in desc order
        sort(arr.begin() + i, arr.begin() + j, greater<int>());

        i = j;
    }

    return arr;
}

int main()
{

    vector<int> arr = {1, 3, 4, 2};

    vector<int> res = lexicographicallyLargest(arr);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i + 1 < res.size())
            cout << ", ";
    }
    cout << "]";

    return 0;
}