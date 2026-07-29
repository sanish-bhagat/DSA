#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int minSubsets(vector<int> &arr)
{
    // hashset to keep track of elements that are present in the arr[]
    unordered_set<int> st(arr.begin(), arr.end());

    int cnt = 0;

    for (int x : arr)
    {
        // we have to start a new sequence
        // if (x - 1) value is not present in the hashset
        if (!st.count(x - 1))
            cnt++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59};
    cout << minSubsets(arr);
}