#include <bits/stdc++.h>
using namespace std;

int maximumAmount(vector<int> &arr)
{
    int n = arr.size();

    // 2d dp[]
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // fill the table using recurrence relation
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

            // pick the max one by either picking the first value or the picking the last value
            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    // return the max amount of money
    return dp[0][n - 1];
}

int main()
{

    vector<int> arr = {5, 3, 7, 10};
    int res = maximumAmount(arr);
    cout << res << endl;

    return 0;
}