#include <bits/stdc++.h>
using namespace std;

// custom compare function -> used for sorting the pairs based on the decreasing order of profit values
static bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

//! TC is O(n * n)
//! SC is O(n)

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();

    vector<pair<int, int>> jobs;

    // create pairs of (profit, deadline)
    for (int i = 0; i < n; i++)
        jobs.push_back({profit[i], deadline[i]});

    // sort them in descending order
    sort(jobs.begin(), jobs.end(), compare);

    int cnt = 0, totalProfit = 0;

    // slot[] to track the available slot
    vector<int> slot(n, 0);

    for (int i = 0; i < n; i++)
    {
        // find the max slot position, at which the job can be allocated
        int start = min(n, jobs[i].second) - 1;

        // traverse the slot[] from the start -> 0 in the backward direction and
        // if found any slot availabel then allocate the job and update the cnt and totalprofit
        for (int j = start; j >= 0; j--)
        {
            if (slot[j] == 0)
            {
                slot[j] = 1;
                cnt++;
                totalProfit += jobs[i].first;
                break;
            }
        }
    }

    return {cnt, totalProfit};
}

int main()
{
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobSequencing(deadline, profit);
    cout << ans[0] << " " << ans[1];
    return 0;
}