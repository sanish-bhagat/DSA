#include <bits/stdc++.h>
using namespace std;

// TC is O(log ( n + m))

pair<int, int> search(vector<vector<int>> v, int target)
{
    int n = v.size();
    int m = v[0].size();

    int row = 0, col = m - 1;

    while (row < n && col >= 0)
    {
        if (v[row][col] == target)
            return {row, col};

        else if (v[row][col] < target)
            row++;
        else
            col--;
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