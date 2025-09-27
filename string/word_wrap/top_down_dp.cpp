#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int calculate(int curr, int n, vector<int> &memo, vector<int> arr, int k)
{

    // base case
    if (curr >= n)
        return 0;

    if (memo[curr] != -1)
        return memo[curr];

    int sum = 0, ans = INT_MAX;

    for (int i = curr; i < n; i++)
    {

        sum += arr[i];

        int tot = sum + (i - curr);

        if (tot > k)
            break;

        if (i != n - 1)
        {
            int temp = (k - tot) * (k - tot) + calculate(i + 1, n, memo, arr, k);
            ans = min(ans, temp);
        }

        else
        {
            ans = 0;
        }
    }

    return ans;
}

int solveWordWrap(vector<int> arr, int k)
{
    int n = arr.size();
    vector<int> memo(n, -1);
    return calculate(0, n, memo, arr, k);
}

int main()
{
    int k = 6;

    vector<int> arr = {3, 2, 2, 5};
    int res = solveWordWrap(arr, k);
    cout << res << endl;
    return 0;
}