#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int longestSubseq(vector<int> &arr)
{
    int n = arr.size();

    // only element is present in array
    if(n == 1)
        return 1;

    // using hashing based dp table
    unordered_map<int, int> dp;
    int ans = 1;

    // traverse through the elements of the array
    for (int x : arr)
    {
        // arr[i] - 1
        int left = dp.count(x - 1) ? dp[x - 1] : 0;

        // arr[i] + 1
        int right = dp.count(x + 1) ? dp[x + 1] : 0;

        // can extend the sequence by including arr[i]
        dp[x] = 1 + max(left, right);

        // pick the max result
        ans = max(ans, dp[x]);
    }

    return ans;
}

int main()
{

    vector<int> arr = {10, 9, 4, 5, 4, 8, 6};

    cout << longestSubseq(arr);

    return 0;
}