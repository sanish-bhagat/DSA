#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // mark the adjacent cells of the landmiles as unsafe
    void markCells(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> temp = mat;

        // directions for adjacent cells: (up, down, left, right)
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

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

                        if (ni >= 0 && ni < r && nj >= 0 && nj < c)
                            mat[ni][nj] = 0;
                    }
                }
            }
        }
    }

    int dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int i, int j, int c)
    {
        int r = mat.size();

        // base case: out of bound cell or unsafe cell or already visited one
        if (i < 0 || i >= r || j < 0 || j >= c || mat[i][j] == 0 || visited[i][j])
            return INT_MAX;

        // base case: reached the destination cell
        if (j == c - 1)
            return 1;

        visited[i][j] = true;

        // directions for adjacent cells: (up, down, left, right)
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        int minPath = INT_MAX;

        // try all four directions, and find the shortest path among them
        for (int k = 0; k < 4; k++)
        {
            int ni = i + row[k];
            int nj = j + col[k];

            int pathLength = dfs(mat, visited, ni, nj, c);

            if (pathLength != INT_MAX)
                minPath = min(minPath, pathLength + 1);
        }

        // backtrack: unmark current cell
        visited[i][j] = false;

        return minPath;
    }

    //! TC is O(4 ^ (r * c))
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

        int minPath = INT_MAX;

        // try starting from each safe cell of the first column
        for (int i = 0; i < r; i++)
        {
            if (mat[i][0] == 1)
            {
                int pathLength = dfs(mat, visited, i, 0, c);

                if (pathLength != INT_MAX)
                    minPath = min(minPath, pathLength);
            }
        }

        return (minPath == INT_MAX) ? -1 : minPath;
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