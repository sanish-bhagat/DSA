#include <bits/stdc++.h>
using namespace std;

//! TC is O(n + m)
//! SC is O(1)

bool matSearch(vector<vector<int>> &arr, int x)
{

    int n = arr.size(), m = arr[0].size();
    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {

        if (arr[i][j] == x)
            return true;

        else if (arr[i][j] < x)
            i++;

        else
            j--;
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