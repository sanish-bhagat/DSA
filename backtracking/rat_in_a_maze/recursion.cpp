#include <bits/stdc++.h>
using namespace std;
#define MAX 5

//! TC is O(4 * (n * n))
//! SC is O(n * n)

void solve(int i, int j, int m[MAX][MAX], int n, vector<string> &res, string move, vector<vector<int>> &visited)
{
    if (i == n - 1 && j == n - 1)
    {
        res.push_back(move);
        return;
    }

    // mark the cell visited
    visited[i][j] = 1;

    // downward
    if (i + 1 < n && !visited[i + 1][j] && m[i + 1][j] == 1)
        solve(i + 1, j, m, n, res, move + 'D', visited);

    // leftward
    if (j - 1 >= 0 && !visited[i][j - 1] && m[i][j - 1] == 1)
        solve(i, j - 1, m, n, res, move + 'L', visited);

    // rightward
    if (j + 1 < n && !visited[i][j + 1] && m[i][j + 1] == 1)
        solve(i, j + 1, m, n, res, move + 'R', visited);

    // upward
    if (i - 1 >= 0 && !visited[i - 1][j] && m[i - 1][j] == 1)
        solve(i - 1, j, m, n, res, move + 'U', visited);

    // backtrack
    visited[i][j] = 0;
}

vector<string> findPath(int m[MAX][MAX], int n)
{
    vector<string> res;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    if (m[0][0] == 1)
        solve(0, 0, m, n, res, "", visited);

    return res;
}

int main()
{
    int m[MAX][MAX] = {{1, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1},
                       {1, 1, 1, 0, 1},
                       {0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 1}};
    int n = sizeof(m) / sizeof(m[0]);
    vector<string> ans = findPath(m, n);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}