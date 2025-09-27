#include <bits/stdc++.h>
using namespace std;

vector<int> jobSequencing(vector<int> deadline, vector<int> profit)
{
    int n = deadline.size();

    vector<pair<int, int>> jobs;

    // create pairs of (deadline, profit)
    for (int i = 0; i < n; i++)
        jobs.push_back({deadline[i], profit[i]});

    // sort the pairs based on the deadline in increasing order
    sort(jobs.begin(), jobs.end());

    vector<int> ans = {0, 0};

    // min heap -> to maintain the scheduled jobs based on profit
    priority_queue<int, vector<int>, greater<int>> pq;

    // traverse the jobs pair[]
    for (const auto &job : jobs)
    {
        // the curr job can be scheduled within the deadline
        if (job.first > pq.size())
            pq.push(job.second);

        // replace the job with the lowest profit
        else if (!pq.empty() && pq.top() < job.second)
        {
            pq.pop();
            pq.push(job.second);
        }
    }

    // calculate the totalprofit and no. of scheduled jobs
    while (!pq.empty())
    {
        ans[1] += pq.top();
        pq.pop();
        ans[0]++;
    }

    return ans;
}

int main()
{
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobSequencing(deadline, profit);
    cout << ans[0] << " " << ans[1];
    return 0;
}