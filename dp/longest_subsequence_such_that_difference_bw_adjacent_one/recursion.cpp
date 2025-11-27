#include <bits/stdc++.h>
using namespace std;

int helper(int idx, int prev, vector<int> &arr)
{
    // base case: traversed all the elements -> return 0
    if (idx == arr.size())
        return 0;

    // exclude the curr element
    int exclude = helper(idx + 1, prev, arr);

    // include the curr element in the sequence, if it satisfies the condition
    int include = 0;
    if (prev == -1 || abs(arr[idx] - arr[prev]) == 1)
        include = 1 + helper(idx + 1, idx, arr);

    // pick the max one
    return max(exclude, include);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int longestSubseq(vector<int> &arr)
{
    // recursive function to explore all the sequences
    return helper(0, -1, arr);
}

int main()
{

    vector<int> arr = {10, 9, 4, 5, 4, 8, 6};

    cout << longestSubseq(arr);

    return 0;
}