#include <bits/stdc++.h>
using namespace std;

// TC is O(n * m)

bool search(vector<vector<int>> v, int target)
{
    int n = 3, m = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> v = {
        {3, 4, 7, 9},
        {12, 13, 16, 18},
        {20, 21, 23, 29}};

    int target = 23;

    cout << search(v, target);
}