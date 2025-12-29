#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int getCount(int n)
{
    // 2d prev[] to store value from the previous row(remaining length)
    vector<vector<int>> prev(4, vector<int>(3, 1));

    // value for cell * and #
    prev[3][0] = 0, prev[3][2] = 0;

    // 2d curr[]
    vector<vector<int>> curr(4, vector<int>(3, 0));

    // directions for traversal at every curr cell
    vector<vector<int>> dir = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // traverse for every remaining length from (2...n)
    for (int k = 2; k <= n; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // reset curr
                curr[i][j] = 0;

                // cell value is * or #
                if (i == 3 && (j == 0 || j == 2))
                    continue;

                // traverse in every direction from the curr cell
                for (auto d : dir)
                {
                    int x = i + d[0], y = j + d[1];

                    // if after visiting the direction, the cell is in-bound ->
                    // calculate the answer for all next 5 cells
                    if (x >= 0 && x < 4 && y >= 0 && y < 3)
                        curr[i][j] += prev[x][y];
                }
            }
        }

        // update the previous[] values by the curr[] values
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                prev[i][j] = curr[i][j];
    }

    // calculate the ans from each cell
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
            ans += prev[i][j];
    }

    return ans;
}

int main()
{

    int n = 2;
    cout << getCount(n);
    return 0;
}