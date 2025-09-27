#include <bits/stdc++.h>
using namespace std;

// TC is O(n*m)

int count(vector<vector<int>> v)
{
    int n = 5, m = 5;
    int ind = -1, maxCnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int cntRow = 0;
        for (int j = 0; j < m; j++)
        {
            cntRow += v[i][j];
        }
        if (cntRow > maxCnt)
        {
            maxCnt = cntRow;
            ind = i;
        }
    }
    return ind;
}

int main()
{
    vector<vector<int>> v = {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1}};

    cout << count(v);
}