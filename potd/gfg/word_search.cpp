#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, int idx, string &word, vector<vector<char>> &mat)
{
    // complete word is present -> return true
    if (idx == word.size())
        return true;

    // out of bound cells or different letter -> return false
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[idx])
        return false;

    // store the curr cell value
    char temp = mat[i][j];

    // mark the curr cell as visited
    mat[i][j] = '#';

    // recursivelly check in all 4-directions
    bool found = dfs(i, j - 1, idx + 1, word, mat) ||
                 dfs(i, j + 1, idx + 1, word, mat) ||
                 dfs(i - 1, j, idx + 1, word, mat) ||
                 dfs(i + 1, j, idx + 1, word, mat);

    // backtrack -> restore the previous state
    mat[i][j] = temp;

    return found;
}

//! TC is O(n * m * (4 ^ l))
//! SC is O(l)

bool isWordExist(vector<vector<char>> &mat, string &word)
{
    int n = mat.size(), m = mat[0].size();

    // tarverse the cells of the given mat
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // same letter -> perform dfs for the remaining word,
            // recursivelly check in all 4-directions and keep on checking the word
            if (mat[i][j] == word[0])
                if (dfs(i, j, 0, word, mat))
                    return true;
        }
    }

    // word not present in the mat[][] -> return false
    return false;
}

int main()
{
    vector<vector<char>> mat = {
        {'T', 'E', 'E'},
        {'S', 'G', 'K'},
        {'T', 'E', 'L'}};

    string word = "GEEK";

    cout << isWordExist(mat, word);
}