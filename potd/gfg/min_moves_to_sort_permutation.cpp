#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int minMoves(vector<int> &arr)
{
    int n = arr.size();

    // 1d [] to keep track of longest consecutive subsequence ending at i
    vector<int> count(n + 1, 0);

    for (int x : arr)
    {
        // extend the subsequence
        if (count[x - 1] != 0)
            count[x] = count[x - 1] + 1;

        // new subsequence
        else
            count[x] = 1;
    }

    // find the longest consecutive subsequence that are in correct related order
    int longest = 0;
    for (int i = 0; i <= n; i++)
        longest = max(longest, count[i]);

    // remaining elements have to be moved
    return n - longest;
}

int main()
{
    vector<int> arr = {2, 1, 3};
    cout << minMoves(arr) << endl;

    arr = {4, 3, 1, 2};
    cout << minMoves(arr) << endl;
}