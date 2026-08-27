#include <iostream>
#include <vector>
using namespace std;

//! TC is O(n * (n + m))
//! SC is O(n * m)

int maxArea(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> height(n, vector<int>(m, 0));

    // height[i][j] stores consecutive 1s ending at row i in column j.
    for (int j = 0; j < m; j++)
    {
        height[0][j] = mat[0][j];

        for (int i = 1; i < n; i++)
        {
            if (mat[i][j] == 1)
            {
                height[i][j] = height[i - 1][j] + 1;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> count(n + 1, 0);

        // Count frequency of each height.
        for (int j = 0; j < m; j++)
        {
            count[height[i][j]]++;
        }

        int col = 0;

        // Rearrange heights in decreasing order using counting sort.
        for (int h = n; h >= 0; h--)
        {
            while (count[h] > 0)
            {
                height[i][col] = h;
                col++;
                count[h]--;
            }
        }

        // Calculate maximum area for this row.
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, height[i][j] * (j + 1));
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0}};
    cout << maxArea(mat) << endl;

    mat = {
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1}};
    cout << maxArea(mat) << endl;

    return 0;
}