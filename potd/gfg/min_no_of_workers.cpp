#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int minWorker(vector<int> &arr)
{
    int n = arr.size();

    // store (start, end) for every worker i
    vector<pair<int, int>> intervals;

    // store the intervals for every valid worker
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            int start = max(0, i - arr[i]);
            int end = min(n - 1, i + arr[i]);

            intervals.push_back({start, end});
        }
    }

    // no workers available
    if (intervals.empty())
        return -1;

    // sort the workers based on their start interval
    sort(intervals.begin(), intervals.end());

    int count = 0, i = 0, currEnd = -1;

    // min workers required to cover the total interval[0...n-1]
    while (currEnd < n - 1)
    {
        int maxReach = currEnd;

        // no intervals left or gap found -> cannot cover, return -1
        if (i >= intervals.size() || intervals[i].first > currEnd + 1)
            return -1;

        // extend the coverage as far as possible
        while (i < intervals.size() && intervals[i].first <= currEnd + 1)
        {
            maxReach = max(maxReach, intervals[i].second);
            i++;
        }

        // increment the worker count
        count++;

        // update the max curr coverage
        currEnd = maxReach;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 2, 1, 0};
    cout << minWorker(arr) << endl;
    return 0;
}