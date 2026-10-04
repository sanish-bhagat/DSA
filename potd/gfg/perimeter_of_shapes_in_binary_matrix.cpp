#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(1)

int findPerimeter(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int perimeter = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
                continue;

            // Check all four sides of the current 1 cell.
            for (int d = 0; d < 4; d++)
            {
                int ni = i + dr[d];
                int nj = j + dc[d];

                // Count the side if it is exposed.
                if (ni < 0 || ni >= n || nj < 0 || nj >= m ||
                    mat[ni][nj] == 0)
                {
                    perimeter++;
                }
            }
        }
    }

    return perimeter;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0},
        {1, 1}};

    cout << findPerimeter(mat);

    return 0;
}