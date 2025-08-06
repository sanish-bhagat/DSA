#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int startStation(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int startIdx = 0, currGas = 0;

    // find the start index
    for (int i = 0; i < n; i++)
    {
        currGas += gas[i] - cost[i];

        if (currGas < 0)
        {
            startIdx = i + 1;
            currGas = 0;
        }
    }

    // check if the start index is a valid starting index for the circular tour
    currGas = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = (i + startIdx) % n;
        currGas = currGas + gas[idx] - cost[idx];

        if (currGas < 0)
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