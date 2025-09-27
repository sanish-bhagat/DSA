#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

vector<int> minMaxCandy(vector<int> &prices, int k)
{
    int n = prices.size();
    // sort the prices of candies
    sort(prices.begin(), prices.end());

    int minCost = 0;

    // traverse from the begininig and try to buy the cheapest ones and get the expensive ones for free
    for (int i = 0; i < n; i++)
    {
        minCost += prices[i];
        n -= k; // get the expensive ones for free
    }

    n = prices.size();
    int index = -1, maxCost = 0;

    // traverse from the ending and try to buy the expensive ones and get the cheapest ones for free
    for (int i = n - 1; i > index; i--)
    {
        maxCost += prices[i];
        index += k; // get the cheapest ones for free
    }

    return {minCost, maxCost};
}

int main()
{
    vector<int> prices = {3, 2, 1, 4};
    int k = 2;
    vector<int> res = minMaxCandy(prices, k);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}