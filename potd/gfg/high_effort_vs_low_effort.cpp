#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxTask(vector<int> &h, vector<int> &l)
{
    int n = h.size();

    // edge case: no days
    if (n == 0)
        return 0;

    // prev2 -> dp[i-2], prev1 -> dp[i-1]
    int prev2 = 0;

    // day 0: choose best of h or l
    int prev1 = max(h[0], l[0]);

    // if only one day
    if (n == 1)
        return prev1;

    // day 1: either take h, or l + prev best
    int curr = max(h[1], l[1] + prev1);

    prev2 = prev1;
    prev1 = curr;

    // process remaining days
    for (int i = 2; i < n; i++)
    {
        // option 1: take l today + best till yesterday
        // option 2: take h today + best till day before yesterday
        curr = max(l[i] + prev1, h[i] + prev2);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> h = {3, 6, 8, 7, 6};
    vector<int> l = {1, 5, 4, 5, 3};

    cout << maxTask(h, l) << endl;

    return 0;
}