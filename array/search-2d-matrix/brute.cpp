#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(1)

bool matSearch(vector<vector<int>> &arr, int x)
{

    int n = arr.size(), m = arr[0].size();

    for (int i = 0l; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == x)
                return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if (matSearch(mat, x))
        cout << "true";
    else
        cout << "false";
    return 0;
}