#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, vector<vector<char>> &mat, string &word)
{
    // first letter mismatches
    if (mat[i][j] != word[0])
        return false;

    int n = mat.size(), m = mat[0].size();
    int len = word.size();

    // moving directions
    vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> dy = {0, 0, 1, -1, 1, -1, -1, 1};

    for (int d = 0; d < 8; d++)
    {
        int k, nx = i + dx[d], ny = j + dy[d];

        // match for all the letters of the word
        for (k = 1; k < len; k++)
        {
            // out of bound index
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                break;

            // letter mismatch
            if (mat[nx][ny] != word[k])
                break;

            // move in particular direction
            nx += dx[d], ny += dy[d];
        }

        // all characters of the word have been matched
        if (k == len)
            return true;
    }

    // word is not found in any direction
    return false;
}

//! TC is O(n * m * k)
//! SC is O(1)

vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word)
{
    int n = mat.size(), m = mat[0].size();

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // word is found from this coordinate, store the starting coordinates
            if (solve(i, j, mat, word))
                res.push_back({i, j});
        }
    }

    return res;
}

int main()
{
    vector<vector<char>> mat =
        {{'a', 'b', 'a', 'b'}, {'a', 'b', 'e', 'b'}, {'e', 'b', 'e', 'b'}};
    string word = "abe";

    vector<vector<int>> ans = searchWord(mat, word);

    for (auto it : ans)
        cout << it[0] << " " << it[1] << endl;
}