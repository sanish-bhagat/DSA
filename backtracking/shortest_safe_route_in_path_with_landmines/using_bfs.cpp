#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // mark the adjacent cells of the landmiles as unsafe
    void markCells(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();

        // directions for adjacent cells: (up, down, left, right)
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        vector<vector<int>> temp = mat;

        // mark the adjacent cells of landmines as unsafe
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (temp[i][j] == 0)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + row[k];
                        int nj = j + col[k];

                        // cell is in-bound, then mark the cell as unsafe
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c)
                            mat[ni][nj] = 0;
                    }
                }
            }
        }
    }

    //! TC is O(r * c)
    //! SC is O(r * c)

public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();

        // mark the adjacent cells of the landmiles as unsafe
        markCells(mat);

        // keep track of the visited cell
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        // queue for bfs traversal({i, j, dist})
        queue<array<int, 3>> q;

        // enqueue the first column safe cells
        for (int i = 0; i < r; i++)
        {
            if (mat[i][0] == 1)
            {
                q.push({i, 0, 1});
                visited[i][0] = true;
            }
        }

        // directions for adjacent cells: (up, down, left, right)
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        // bfs traversal
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            // get the row, col, and dist
            int i = front[0], j = front[1], dist = front[2];

            // if reached the last cloumn, return the shortest dist
            if (j == c - 1)
                return dist;

            // try for all four directions
            for (int k = 0; k < 4; k++)
            {
                int ni = i + row[k];
                int nj = j + col[k];

                // cell is in-bound and cell is safe and cell is not visited,
                // then move to this cell and update the dist,
                // mark the cell as visited
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && mat[ni][nj] == 1 && !visited[ni][nj])
                {
                    q.push({ni, nj, dist + 1});
                    visited[ni][nj] = true;
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}};

    Solution s;

    int result = s.findShortestPath(mat);
    cout << result << endl;

    return 0;
}