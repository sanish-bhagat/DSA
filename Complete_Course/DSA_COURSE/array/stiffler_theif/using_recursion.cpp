#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 ^ n)
//! SC is O(1)

int maxLootRec(vector<int> &arr, int n)
{

    // if no houses are left
    if (n <= 0)
        return 0;

    // if only house is left
    if (n == 1)
        return arr[0];

    // two choices :
    // 1. either rob the last house
    // 2. or do not rob the last house
    int pick = arr[n - 1] + maxLootRec(arr, n - 2);
    int notPick = maxLootRec(arr, n - 1);

    return max(pick, notPick);
}

int maxLoot(vector<int> &arr)
{
    int n = arr.size();

    return maxLootRec(arr, n);
}

int main()
{
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval);
    return 0;
}