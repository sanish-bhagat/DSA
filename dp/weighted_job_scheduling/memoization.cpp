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

int maxProfitRec(int i, vector<vector<int>> &jobs, vector<int> &memo)
{
    // base case: explored all the jobs
    if (i >= jobs.size())
        return 0;

    // already computed subproblem
    if (memo[i] != -1)
        return memo[i];

    // skip this job
    int skip = maxProfitRec(i + 1, jobs, memo);

    // take the curr job and
    // pick the next job whose start time is greater than or equal to the curr job's end time
    int next = findNextJob(i, jobs);

    // include the curr job profit and recusively explore the next jobs
    int take = jobs[i][2] + maxProfitRec(next, jobs, memo);

    // pick and store the max profit
    return memo[i] = max(skip, take);
}

//! TC is O(n * logn)
//! SC is O(n)

int maxProfit(vector<vector<int>> &jobs)
{
    // sort the jobs based on their starting time
    sort(jobs.begin(), jobs.end());

    // 1d memo[] to keep track of max profit till i job
    vector<int> memo(jobs.size(), -1);

    // recursively explore all the combinations of job scheduling
    return maxProfitRec(0, jobs, memo);
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