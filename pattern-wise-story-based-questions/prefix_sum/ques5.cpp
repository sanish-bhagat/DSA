// A server logs load changes:

// arr = [84, -37, 32, 40, 95]
// K = 167

// 👉 Find:

// Shortest subarray with sum ≥ K

#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int shortestSub(int k, vector<int> &arr)
{
    // stores index in a monotonic increasing order for prefix sum
    deque<int> dq;
    int n = arr.size();

    // build the prefix sum[]
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
        prefix[i] += prefix[i - 1] + arr[i];

    int minLen = n;

    // traverse through every size subarray and find the shortest that is valid
    for (int j = 0; j < n; j++)
    {
        // valid subarray -> try to shrink it, and find the shortest one
        while (!dq.empty() && (prefix[j] - prefix[dq.front()]) >= k)
        {
            minLen = min(minLen, j - dq.front());
            dq.pop_front();
        }

        // maintain increasing order -> remove useless index,
        // as a larger prefix is useless if a smaller one exist later
        while (!dq.empty() && prefix[j] <= prefix[dq.back()])
            dq.pop_back();

        // push curr index
        dq.push_back(j);
    }

    // return the shortest length of the valid subarray
    return minLen == n ? -1 : minLen;
}

int main()
{
    vector<int> arr = {84, -37, 32, 40, 95};
    int k = 167;

    cout << shortestSub(k, arr);
}