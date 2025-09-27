#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int celebrity(vector<vector<int>> &mat)
{
    int n = mat.size();

    //initialse two vectors with 0 to tracj who knows whom
    vector<int> knowsMe(n, 0), iKnow(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            //skip the diagonal elements
            if (i == j)
                continue;

            int x = mat[i][j];

            knowsMe[j] += x;
            iKnow[i] += x;
        }
    }

    //check for the celebrity
    //knowsMe[i] == n - 1 as every one should know me except him so it will be eqaul tp n - 1
    //iKnow[i] == 0 as celebrity should not know anyone
    for (int i = 0; i < n; i++)
    {
        if (knowsMe[i] == n - 1 && iKnow[i] == 0)
            return i;
    }

    return -1;
}

int main()
{
    vector<vector<int>> mat = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};
    cout << celebrity(mat);
    return 0;
}