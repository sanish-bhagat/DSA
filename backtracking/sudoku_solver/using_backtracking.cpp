#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &mat, int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        // 1 - num to be filled should not be present in the curr row
        if (mat[i][col] == num)
            return false;

        // 2 - num to be filled should not be present in the curr row
        if (mat[row][i] == num)
            return false;

        // 3 - num must occur exactly once in each of the 9 3*3 sub-boxes of the sudoku grid
        if (mat[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return false;
    }

    // all the conditions are met, then its a valid num for the empty cell
    return true;
}

bool solve(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            // found the empty cell
            if (mat[i][j] == 0)
            {

                // check which num will be valid for this empty cell
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(mat, i, j, num))
                    {
                        mat[i][j] = num;

                        // found a valid sudoku
                        if (solve(mat) == true)
                            return true;

                        // backtrack
                        else
                            mat[i][j] = 0;
                    }
                }

                // not found any valid num to be filled in this empty cell
                return false;
            }
        }
    }

    // all the empty cells have been filled
    return true;
}

//! TC is O(9^(n * n))
//! SC is O(1)

void solveSudoku(vector<vector<int>> &mat)
{
    solve(mat);
}

int main()
{
    vector<vector<int>> mat = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSudoku(mat);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}