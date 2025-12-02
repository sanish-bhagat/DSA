#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n)

int maximumPath(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    // keep track of prev and curr row elements
    vector<int> prev(m), curr(m);

    // first row is same as matrix
    for (int j = 0; j < m; j++)
        prev[j] = mat[0][j];

    // iteratively fill the dp row by row
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // for every cell, we can come from the following three directions
            int up = prev[j];
            int left = (j > 0) ? prev[j - 1] : 0;
            int right = (j < m - 1) ? prev[j + 1] : 0;

            // pick up the max of all the three moves and include in the curr path
            curr[j] = mat[i][j] + max({up, left, right});
        }

        // update the previous row values by current ones
        prev = curr;
    }

    // max sum of path is stored in the last row 
    return *max_element(prev.begin(), prev.end());
}

int main()
{

    // Input matrix
    vector<vector<int>> mat = {{10, 10, 2, 0, 20, 4},
                               {1, 0, 0, 30, 2, 5},
                               {0, 10, 4, 0, 2, 0},
                               {1, 0, 2, 20, 0, 4}};

    // Output the maximum path sum
    cout << maximumPath(mat) << endl;
    return 0;
}