#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(1)

int startStation(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int startIdx = -1;

    for (int i = 0; i < n; i++)
    {
        int currGas = 0; // initially the car tank is empty
        bool flag = true;

        for (int j = 0; j < n; j++)
        {
            int idx = (i + j) % n;
            currGas = currGas + gas[idx] - cost[idx]; // find the curr gas by adding the next station gas and subtracting the cost to move to the next station

            // it is not possible to move further
            if (currGas < 0)
            {
                flag = false;
                break;
            }
        }

        // you have found the start index
        if (flag)
        {
            startIdx = i;
            break;
        }
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