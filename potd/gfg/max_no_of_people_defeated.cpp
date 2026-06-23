#include <bits/stdc++.h>
using namespace std;

// return sum of squares: 1^2 + 2^2 + .... h^2
int sum(int h)
{
    return h * (h + 1) * (2 * h + 1) / 6;
}

//! TC is O(log n)
//! SC is O(1)

int maxPeopleDefeated(int p)
{
    // search range
    int low = 0, high = 1000;

    int ans = 0;

    // binary search on no. of people
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // can defeat these peoples using the curr strength ->
        // move low to maximise the no. of people we can defeat
        if (sum(mid) <= p)
        {
            ans = mid;
            low = mid + 1;
        }

        // move high as we cannot defeat
        // these many no. of peoples using the curr strength
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    int p = 14;
    cout << maxPeopleDefeated(p);
}