#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

int maxLootRec(vector<int> &arr, int n, vector<int> &memo)
{
    // base case
    if (n <= 0)
        return 0;

    if (n == 1)
        return arr[0];

    // value is already computed
    if (memo[n] != -1)
        return memo[n];

    int pick = arr[n - 1] + maxLootRec(arr, n - 2, memo);
    int notPick = maxLootRec(arr, n - 1, memo);

    memo[n] = max(pick, notPick);

    return memo[n];
}

int maxLoot(vector<int> &arr)
{
    int n = arr.size();
    vector<int> memo(n + 1, -1);

    return maxLootRec(arr, n, memo);
}

int main()
{
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval);
    return 0;
}