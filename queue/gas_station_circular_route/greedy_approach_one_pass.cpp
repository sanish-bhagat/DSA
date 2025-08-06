#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int startStation(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int startIdx = 0;
    int currGas = 0, totalGas = 0;

    for (int i = 0; i < n; i++)
    {
        currGas += gas[i] - cost[i];
        totalGas += gas[i] - cost[i]; // keeps track of the net available gas over the entire tour

        if (currGas < 0)
        {
            startIdx = i + 1;
            currGas = 0;
        }
    }

    // if the net gas i negative then there is no such starting point for the circular tour
    if (totalGas < 0)
    {
        return -1;
    }

    return startIdx;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << startStation(gas, cost) << endl;
    return 0;
}