#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

//! TC is O(n * m * log n)
//! SC is O(n * m)

vector<vector<int>> findUniqueRows(int M[ROW][COL])
{
    map<vector<int>, bool> mp;

    vector<vector<int>> res;

    for (int i = 0; i < ROW; i++)
    {
        vector<int> currentRow;

        // get the current row
        for (int j = 0; j < COL; j++)
            currentRow.push_back(M[i][j]);

        // if the current row is unique, then push into the res[][]
        if (mp.find(currentRow) == mp.end())
        {
            mp[currentRow] = true;

            res.push_back(currentRow);
        }
    }

    return res;
}

int main()
{
    int M[ROW][COL] = {{0, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 0, 1},
                       {1, 0, 1, 0, 0}};

    vector<vector<int>> res = findUniqueRows(M);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";

        cout << endl;
    }

    return 0;
}