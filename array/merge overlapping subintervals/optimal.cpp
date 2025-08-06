#include <bits/stdc++.h>
using namespace std;

//! TC is O(nlogn + n)
//! SC is O(n)

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);

        else
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};

    vector<vector<int>> ans = mergeIntervals(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}