#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();

    //point to first and last row
    int top = 0, down = n - 1;

    while (top < down)
    {
        //top knows down, top++
        if (mat[top][down])
            top++;

        //down know top, down--
        else if (mat[down][top])
            down--;

        //both don't know each other
        else
            top++, down--;
    }

    //ptrs crossed each other therfore no candidate
    if (top > down)
        return -1;

    //verify the potetnial candidate(top or down)
    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;

        if (mat[top][i] == 1 || mat[i][top] == 0)
            return -1;
    }

    return top;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};
    cout << celebrity(mat);
    return 0;
}