#include <bits/stdc++.h>
using namespace std;

// boolean function that tells whether
// it is possible to paint all the boards in the curr max allowed time using k painters
bool isPossible(vector<int> &arr, int maxTime, int k)
{
    int painters = 1, currLoad = 0;

    for (int length : arr)
    {
        // curr board length takes more time to paint then max allowed time -> return false
        if (length > maxTime)
            return false;

        // if assigning this board exceeds the maxTime -> give it to a new painter
        if (currLoad + length > maxTime)
        {
            painters++;
            currLoad = length;
        }

        // else, add the board load to the curr painter's workload
        else
            currLoad += length;
    }

    // return true if total painters used is within the allowed k
    return painters <= k;
}

//! TC is O(n * logs), s = sum(arr) - max(arr)
//! SC is O(1)

int minTime(vector<int> &arr, int k)
{
    // low denotes the largest single board as our min possible time
    int low = *max_element(arr.begin(), arr.end());

    // high denotes the sum of all baords as our max possible time
    int high = accumulate(arr.begin(), arr.end(), 0);

    int ans = high;

    // binary search on the answer
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // it is possible to paint all the boards in curr time using k painters ->
        // store the time and try to find more min one
        if (isPossible(arr, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }

        // not possible to paint -> move low to larger time
        else
            low = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {5, 10, 30, 20, 15};
    int k = 3;

    cout << minTime(arr, k);
}