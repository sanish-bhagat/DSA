#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(1)

vector<int> exitPoint(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();

    int i = 0, j = 0;
    int dir = 0;

    while (true)
    {
        // moving direction
        dir = (dir + mat[i][j]) % 4;

        // mark the curr cell as traversed
        if (mat[i][j] == 1)
            mat[i][j] = 0;

        // move right
        if (dir == 0)
            j++;

        // move down
        else if (dir == 1)
            i++;

        // move left
        else if (dir == 2)
            j--;

        // move up
        else if (dir == 3)
            i--;

        // exit point founded -> return the curr cell
        if (i < 0)
        {
            i++;
            break;
        }

        else if (i >= n)
        {
            i--;
            break;
        }

        else if (j < 0)
        {
            j++;
            break;
        }

        else if (j >= m)
        {
            j--;
            break;
        }
    }

    return {i, j};
}

int main()
{
    vector<vector<int>> mat{{0, 1, 0},
                            {0, 1, 1},
                            {0, 0, 0}};

    vector<int> exitPoints = exitPoint(mat);

    cout << exitPoints[0] << " " << exitPoints[1];

    return 0;
}