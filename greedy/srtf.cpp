#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

class Solution
{
public:
    vector<double> averageTimes(vector<int> &arrival, vector<int> &burst, int n)
    {
        vector<int> ct(n), tat(n), wt(n);
        vector<int> remainingTime = burst;

        int completed = 0, currentTime = 0, minRemaining = INT_MAX;
        int shortest = -1;
        bool found = false;

        while (completed < n)
        {
            for (int i = 0; i < n; i++)
            {
                if (arrival[i] <= currentTime && remainingTime[i] > 0)
                {
                    if (remainingTime[i] < minRemaining)
                    {
                        minRemaining = remainingTime[i];
                        found = true;
                        shortest = i;
                    }
                }
            }

            if (!found)
            {
                currentTime++;
                continue;
            }

            remainingTime[shortest]--;
            minRemaining = remainingTime[shortest];

            if (minRemaining == 0)
                minRemaining = INT_MAX;

            if (remainingTime[shortest] == 0)
            {
                completed++;
                found = false;

                int finishTime = currentTime + 1;
                ct[shortest] = finishTime;

                tat[shortest] = ct[shortest] - arrival[shortest];
                wt[shortest] = tat[shortest] - burst[shortest];

                if (wt[shortest] < 0)
                    wt[shortest] = 0;
            }

            currentTime++;
        }

        double total_tat = 0, total_wt = 0;

        for (int i = 0; i < n; i++)
        {
            total_tat += tat[i];
            total_wt += wt[i];
        }

        return {total_wt / n, total_tat / n};
    }
};

int main()
{
    Solution obj;
    vector<int> arrival = {0, 1, 2, 3};
    vector<int> burst = {8, 4, 9, 5};
    int n = arrival.size();

    vector<double> ans = obj.averageTimes(arrival, burst, n);
    cout << "Average Waiting Time: " << ans[0] << endl;
    cout << "Average Turnaround Time: " << ans[1] << endl;
    return 0;
}