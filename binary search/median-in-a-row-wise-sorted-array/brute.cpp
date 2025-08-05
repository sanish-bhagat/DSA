#include <bits/stdc++.h>
using namespace std;

// TC is O(n*m) + O(n*m (log n*m))

int median(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();

    vector<int> ls;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ls.push_back(v[i][j]);
        }
    }

    sort(ls.begin(), ls.end());

    return ls[(n * m) / 2];
}

int main()
{
    vector<vector<int>> v = {
        {1, 5, 7, 9, 11},
        {2, 3, 4, 5, 10},
        {9, 10, 12, 14, 16}};

    cout << median(v);
}