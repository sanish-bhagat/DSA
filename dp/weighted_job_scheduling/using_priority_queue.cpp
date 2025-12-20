#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int maxProfit(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end());

    // min-heap -> {end time, max profit so far}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int maxProfit = 0;

    // traverse through every job
    for (auto job : jobs)
    {
        int start = job[0], end = job[1], profit = job[2];

        // job have end time less or equal to the start time of the previous included job -> pick this job
        while (!pq.empty() && pq.top().first <= start)
        {
            // pick the max profit so far
            maxProfit = max(maxProfit, pq.top().second);
            pq.pop();
        }

        // push the included jobs end time and max profit so far
        pq.push({end, profit + maxProfit});
    }

    // final max profit among all included jobs
    while (!pq.empty())
    {
        maxProfit = max(maxProfit, pq.top().second);
        pq.pop();
    }

    // return the max profit
    return maxProfit;
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