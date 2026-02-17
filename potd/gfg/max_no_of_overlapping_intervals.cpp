#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int overlapInt(vector<vector<int>> &arr)
{
    // get the maxtime of occurence
    int maxTime = 0;
    for (auto &it : arr)
        maxTime = max(maxTime, it[1]);

    vector<int> diff(maxTime + 2, 0);

    // Mark intervals
    for (auto &it : arr)
    {
        diff[it[0]]++;     // start
        diff[it[1] + 1]--; // end + 1 (inclusive handling)
    }

    // count the no. of max intervals that overlap
    int cnt = 0, maxOverlap = 0;
    for (auto it : diff)
    {
        cnt += it;
        maxOverlap = max(maxOverlap, cnt);
    }

    return maxOverlap;
}

int main()
{
    vector<vector<int>> arr = {{1, 8}, {2, 5}, {5, 6}, {3, 7}};
    cout << overlapInt(arr);
}