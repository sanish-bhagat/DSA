#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

vector<vector<int>> socialNetwork(vector<int> &arr)
{
    int n = arr.size() + 1;

    // Store all reachable connections.
    vector<vector<int>> ans;

    // Process users from 2 to n.
    for (int i = 2; i <= n; i++)
    {
        // Store the friend chain of user i.
        vector<int> path;

        int curr = i;

        // Follow the friend chain until user 1.
        while (curr != 1)
        {
            curr = arr[curr - 2];

            // Store the reachable user.
            path.push_back(curr);
        }

        // Process the path in reverse so that
        // users j are considered in increasing order.
        int distance = path.size();

        for (int j = path.size() - 1; j >= 0; j--)
        {
            // Distance from i to path[j].
            ans.push_back({i, path[j], distance});

            distance--;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2};

    vector<vector<int>> ans = socialNetwork(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];

            if (j + 1 < ans[i].size())
                cout << " ";
        }

        cout << "\n";
    }

    return 0;
}