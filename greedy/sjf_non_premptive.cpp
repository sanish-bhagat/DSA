#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

class Solution
{
public:
    vector<double> averageTimes(vector<int> &arrival, vector<int> &burst, int n)
    {
        vector<int> ct(n), tat(n), wt(n);
        vector<bool> done(n, false);

        double total_tat = 0, total_wt = 0;
        int completed = 0, currentTime = 0;

        while (completed < n)
        {
            int idx = -1;
            int minBurst = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                // pick the process with the min burst time among those that have arrived
                if (!done[i] && arrival[i] <= currentTime)
                {
                    if (burst[i] < minBurst)
                    {
                        idx = i;
                        minBurst = burst[i];
                    }
                    else if (burst[i] == minBurst)
                    {
                        // if two processes have same burst time, then pick up the one that have arrived first
                        if (arrival[i] < arrival[idx])
                            idx = i;
                    }
                }
            }

            // if no processes have arrived yet, increase the time
            if (idx == -1)
            {
                currentTime++;
                continue;
            }

            // calculate for the choosen process(execute the process)
            currentTime += burst[idx];
            ct[idx] = currentTime;
            tat[idx] = ct[idx] - arrival[idx];
            wt[idx] = tat[idx] - burst[idx];

            total_tat += tat[idx];
            total_wt += wt[idx];

            completed++;
            done[idx] = true;
        }

        return {total_wt / n, total_tat / n};
    }
};

int main()
{
    Solution obj;
    vector<int> arrival = {0, 2, 4, 5};
    vector<int> burst = {7, 4, 1, 4};
    int n = arrival.size();

    vector<double> ans = obj.averageTimes(arrival, burst, n);
    cout << "Average Waiting Time: " << ans[0] << endl;
    cout << "Average Turnaround Time: " << ans[1] << endl;
    return 0;
}