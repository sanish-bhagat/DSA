#include <bits/stdc++.h>
using namespace std;

// TC is O(n*m)

pair<int, int> search(vector<vector<int>> v, int target)
{
    int n = v.size();
    int m = v[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> v = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int target = 14;

    pair<int, int> res = search(v, target);

    cout << res.first << "," << res.second;
}