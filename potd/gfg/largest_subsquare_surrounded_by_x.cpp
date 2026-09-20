#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

int largestSubsquare(vector<vector<char>> &mat)
{
    int n = mat.size();

    // matrices to store count of 'X' to the right
    // and bottom of cells.
    vector<vector<int>> right(n, vector<int>(n, 0));
    vector<vector<int>> down(n, vector<int>(n, 0));

    // fill the right and down matrices
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (mat[i][j] == 'X')
            {
                right[i][j] = (j == n - 1) ? 1 : right[i][j + 1] + 1;
                down[i][j] = (i == n - 1) ? 1 : down[i + 1][j] + 1;
            }
        }
    }

    int maxSize = 0;

    // check each cell as the top-left corner of the square
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // calculate the maximum possible side
            // length for the square starting at (i, j)
            int maxSide = min(right[i][j], down[i][j]);

            // iterate from the maximum side length down to 1
            for (int side = maxSide; side > 0; side--)
            {
                // check if the square of length
                // 'side' has valid borders
                if (right[i + side - 1][j] >= side && down[i][j + side - 1] >= side)
                {
                    maxSize = max(maxSize, side);
                    break;
                }
            }
        }
    }

    return maxSize;
}

int main()
{
    vector<vector<char>> mat = {{'X', 'X', 'X', 'O'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'X', 'X', 'O'},
                                {'X', 'O', 'X', 'X'}};

    cout << largestSubsquare(mat) << endl;
}