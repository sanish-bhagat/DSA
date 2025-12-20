#include <bits/stdc++.h>
using namespace std;

// find the next valid possible job using binary search
int findNextJob(int i, vector<vector<int>> &jobs)
{
    int low = i + 1, high = jobs.size() - 1, ans = jobs.size();

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // job's start time is greater than or equal to the curr job's start time -> pick this job as next job
        if (jobs[mid][0] >= jobs[i][1])
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

//! TC is O(n logn)
//! SC is O(n)

int maxProfit(vector<vector<int>> &jobs)
{
    int n = jobs.size();

    // sort the jobs based on their starting time
    sort(jobs.begin(), jobs.end());

    // 1d dp[] to keep track of max profit till i job
    vector<int> dp(n + 1, 0);

    // fill the dp table in bottom up manner
    for (int i = n - 1; i >= 0; i--)
    {
        // case 1: skip the curr job
        int skip = dp[i + 1];

        // take the curr job and
        // pick the next job whose start time is greater than or equal to the curr job's end time
        int next = findNextJob(i, jobs);
        int take = jobs[i][2] + dp[next];

        // pick the max profit
        dp[i] = max(skip, take);
    }

    // return the max profit by exploring all the combinations of the job selections
    return dp[0];
}

int main()
{
    vector<vector<int>> jobs = {
        {1, 2, 50},
        {3, 5, 20},
        {6, 19, 100},
        {2, 100, 200}};

    cout << maxProfit(jobs);
    return 0;
}