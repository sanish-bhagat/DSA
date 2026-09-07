#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n * n)
//! SC is O(n * n)

int minCount(vector<int> &arr)
{
    int n = arr.size();

    // dp states
    vector<vector<int>> next(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> curr(n + 1, vector<int>(n + 1, 0));

    // build the dp states
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int incLast = -1; incLast < n; incLast++)
        {
            for (int decLast = -1; decLast < n; decLast++)
            {
                // case 1: skip the curr element
                int ans = 1 + next[incLast + 1][decLast + 1];

                // case 2: include in increasing sequence
                if (incLast == -1 || arr[idx] > arr[incLast])
                    ans = min(ans, next[idx + 1][decLast + 1]);

                // case 3: include in decreasing sequence
                if (decLast == -1 || arr[idx] < arr[decLast])
                    ans = min(ans, next[incLast + 1][idx + 1]);

                curr[incLast + 1][decLast + 1] = ans;
            }
        }

        // update the states
        next = curr;
    }

    return next[0][0];
}

int main()
{
    vector<int> arr = {3, 1, 2, 5, 4};
    cout << minCount(arr) << endl;

    return 0;
}