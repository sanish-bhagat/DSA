#include <bits/stdc++.h>
using namespace std;

bool isSafe(int col, int row, vector<int> &board)
{

    // check all previously placed queens
    for (int i = 0; i < board.size(); i++)
    {
        // row of the placed queen
        int placedRow = board[i];

        // same row
        if (placedRow == row)
            return false;

        // 1 based column
        int placedCol = i + 1;

        // check for diagonals: no two queens lie on the same diagonal
        if (abs(placedRow - row) == abs(placedCol - col))
            return false;
    }

    return true;
}

void solve(int col, int n, vector<int> &board, vector<vector<int>> &res)
{
    // base case
    if (col > n)
    {
        res.push_back(board);
        return;
    }

    // try placing a queen in each row of the curr columns
    for (int row = 1; row <= n; row++)
    {

        // if its safe to place the queen
        if (isSafe(col, row, board))
        {
            // place the queen
            board.push_back(row);

            // recursive call for next column
            solve(col + 1, n, board, res);

            // backtrack: remove the queen
            board.pop_back();
        }
    }
}

//! TC is O(n! * n)
//! SC is O(n)

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> res;

    vector<int> board;

    solve(1, n, board, res);

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