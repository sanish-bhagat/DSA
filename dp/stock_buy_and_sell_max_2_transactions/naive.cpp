#include <bits/stdc++.h>
using namespace std;

// return the max profit from the second transaction
int maxProfOne(int idx, vector<int> &prices)
{
    int minSoFar = prices[idx], res = 0;

    // subarray after the curr index
    for (int i = idx + 1; i < prices.size(); i++)
    {
        // pick the min price seen so far
        minSoFar = min(minSoFar, prices[i]);

        // pick the maxProfit
        res = max(res, prices[i] - minSoFar);
    }

    return res;
}

//! TC is O(n * n)
//! SC is O(1)

int maxProfit(vector<int> &prices)
{
    int minSoFar = prices[0], res = 0;

    // traverse the prices[] from left to right
    for (int i = 1; i < prices.size(); i++)
    {
        // curr price > minSofar -> treat this as a 1st transaction and
        // for the 2nd transaction use the subarray after the curr index
        if (prices[i] > minSoFar)
        {
            int curr = prices[i] - minSoFar + maxProfOne(i, prices);

            // keep track of the max profit from both the transactions
            res = max(res, curr);
        }

        // else update the minSofar
        else
            minSoFar = min(minSoFar, prices[i]);
    }

    // return the max profit
    return res;
}

int main()
{
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(prices);
    return 0;
}