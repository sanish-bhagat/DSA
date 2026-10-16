#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int countAlwaysFound(vector<int> &arr)
{
    int n = arr.size();

    // build the prefix(stores the max from left to right)
    // and suffix(stores the min from right to left)
    vector<int> prefix(n), suffix(n);

    prefix[0] = arr[0];

    // pick the max till curr idx
    for (int i = 1; i < n; i++)
        prefix[i] = max(prefix[i - 1], arr[i]);

    suffix[n - 1] = arr[n - 1];

    // pick the min till curr idx
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = min(suffix[i + 1], arr[i]);

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        // curr element is max of its prefix and min of its suffix -> valid element
        if (arr[i] == prefix[i] && arr[i] == suffix[i])
            cnt++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {3, 7, 9, 8, 15};
    int result = countAlwaysFound(arr);

    cout << result << endl;

    return 0;
}