#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

vector<int> optimalArray(vector<int> &arr)
{
    int n = arr.size();

    // stores min operations
    vector<int> ans(n);

    // 1st element needs 0 operations
    ans[0] = 0;

    for (int i = 1; i < n; i++)
    {
        // curr operations = prev operations + (curr element - median)
        ans[i] = ans[i - 1] + (arr[i] - arr[i / 2]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 6, 9, 12};

    vector<int> ans = optimalArray(arr);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}