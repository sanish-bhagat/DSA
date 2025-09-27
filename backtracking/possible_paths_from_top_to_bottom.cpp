#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void findPaths(int i, int j, vector<vector<int>> &grid, vector<int> &curr, vector<vector<int>> &res)
    {
        int n = grid.size(), m = grid[0].size();

        // reached the bottom right cell
        if (i == n - 1 && j == m - 1)
        {
            // push in curr path
            curr.push_back(grid[i][j]);

            // store the curr path in res
            res.push_back(curr);

            // backtrack: explore more possible paths
            curr.pop_back();
            return;
        }

        // index out of range
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        // include the cell in curr path
        curr.push_back(grid[i][j]);

        // move in downward direction
        if (i + 1 < n)
            findPaths(i + 1, j, grid, curr, res);

        // move in rightward direction
        if (j + 1 < m)
            findPaths(i, j + 1, grid, curr, res);

        // backtrack: explore more possible paths
        curr.pop_back();
    }

public:
    //! TC is O(2 ^ (n * m))
    //! SC is O(n + m)

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // to store all possible paths
        vector<vector<int>> res;

        // keep track of curr path
        vector<int> curr;

        // recursive function to get all the possible paths
        findPaths(0, 0, grid, curr, res);

        return res;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = arr.size(), m = arr[0].size();

    Solution obj;
    vector<vector<int>> ans = obj.findAllPossiblePaths(n, m, arr);

    for (auto &path : ans)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}