#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

vector<double> averageTimes(vector<int> &arrivalTime, vector<int> &burstTime, int n)
{
    double total_tat = 0, total_wt = 0;
    int ct = 0;

    for (int i = 0; i < n; i++)
    {
        // CPU is idle till the arrival of process
        if (ct < arrivalTime[i])
            ct = arrivalTime[i];

        // update the completion time of the curr process
        ct += burstTime[i];

        // calculate for the curr process
        double tat = ct - arrivalTime[i];
        double wt = tat - burstTime[i];

        // update the total times
        total_tat += tat;
        total_wt += wt;
    }

    // return the average of the total times
    return {total_tat / n, total_wt / n};
}

int main()
{
    vector<int> arrivalTime = {0, 1, 2, 3};
    vector<int> burstTime = {5, 3, 8, 6};
    int n = 4;

    vector<double> res = averageTimes(arrivalTime, burstTime, n);

    cout << res[0] << " " << res[1];
}