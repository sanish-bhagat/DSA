#include <bits/stdc++.h>
using namespace std;

void solve(int col, int n, vector<int> &board, vector<vector<int>> &res, vector<bool> &rows, vector<bool> &uDiagonals, vector<bool> &lDiagonals)
{
    // base case: found a solution
    if (col > n)
    {
        res.push_back(board);
        return;
    }

    // try placing a queen in each row of the curr columns
    for (int row = 1; row <= n; row++)
    {
        // if curr row, upper-diagonal and lower-diagonal is not occupied
        if (!rows[row] && !lDiagonals[row + col] && !uDiagonals[row - col + n])
        {

            // place the queen
            board.push_back(row);

            // update the boolean[]
            rows[row] = lDiagonals[row + col] = uDiagonals[row - col + n] = true;

            // recursive call for next columns
            solve(col + 1, n, board, res, rows, uDiagonals, lDiagonals);

            // backtrack: remove queen
            board.pop_back();
            rows[row] = lDiagonals[row + col] = uDiagonals[row - col + n] = false;
        }
    }
}

//! TC is O(n!)
//! SC is O(n)

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> res;

    vector<int> board;

    // boolean arr[] for occupied rows
    vector<bool> rows(n + 1, false);

    // boolean arr[] for occupied diagonals
    vector<bool> uDiagonals(2 * n + 1, false), lDiagonals(2 * n + 1, false);

    solve(1, n, board, res, rows, uDiagonals, lDiagonals);

    return res;
}

int main()
{
    int n = 4;
    vector<vector<int>> res = nQueen(n);

    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < n; ++j)
        {
            cout << res[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }
    return 0;
}