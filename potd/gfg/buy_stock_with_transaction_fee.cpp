#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int maxProfit(vector<int> &arr, int k)
{
    int n = arr.size();

    int noStock = 0, inHand = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // choose to buy or skip
        int newNoStock = max(noStock, inHand - arr[i]);

        // choose to sell or skip
        int newInHand = max(inHand, arr[i] - k + noStock);

        // update the states
        noStock = newNoStock, inHand = newInHand;
    }

    // return the maxProfit
    return noStock;
}

int main()
{
    vector<int> arr = {6, 1, 7, 2, 8, 4};
    int k = 2;

    cout << maxProfit(arr, k);
    return 0;
}