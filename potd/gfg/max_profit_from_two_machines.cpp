#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

int maxProfit(int x, int y, vector<int> &a, vector<int> &b)
{
    int n = a.size();

    // build the absolute diff[]
    vector<vector<int>> diff(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        diff[i] = {abs(a[i] - b[i]), i};
    }

    // sort the diff[] based on decreasing order, to maximise profit
    sort(diff.begin(), diff.end(), greater<vector<int>>());

    int ans = 0;
    int i = 0;

    // pick the task with greater profit
    while (i < n && x > 0 && y > 0)
    {
        int index = diff[i][1];

        // machine A can give more profit for the curr task
        if (a[index] > b[index])
        {
            ans += a[index];
            x--;
        }

        // machine B can give more profit for the curr task
        else
        {
            ans += b[index];
            y--;
        }

        i++;
    }

    // include the remaining machine A tasks
    while (i < n && x > 0)
    {
        int index = diff[i][1];
        ans += a[index];
        x--;
        i++;
    }

    // include the remaining machine B tasks
    while (i < n && y > 0)
    {
        int index = diff[i][1];
        ans += b[index];
        y--;
        i++;
    }

    // return the max profit from all the tasks
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {5, 4, 3, 2, 1};
    int x = 3, y = 3;
    cout << maxProfit(x, y, a, b);

    return 0;
}