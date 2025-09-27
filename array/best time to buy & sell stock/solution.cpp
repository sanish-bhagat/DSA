#include <bits/stdc++.h>
using namespace std;

// TC is O(N)
// SC is O(1)

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int mini = arr[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        mini = min(mini, arr[i]);
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maxProfit(prices) << endl;
}