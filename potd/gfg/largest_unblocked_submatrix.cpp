#include <bits/stdc++.h>
using namespace std;

//! TC is O(k * logk)
//! SC is O(k)

int largestArea(int n, int m, int k, vector<vector<int>> &enemy)
{
    // stores the blocked rows and cols
    vector<int> rows;
    vector<int> cols;

    for (auto e : enemy)
    {
        rows.push_back(e[0]);
        cols.push_back(e[1]);
    }

    // push the boundaries
    rows.push_back(0);
    rows.push_back(n + 1);

    cols.push_back(0);
    cols.push_back(m + 1);

    // sort in increasing order
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    int maxRow = 0, maxCol = 0;

    // find the max row gap, which is unblocked
    for (int i = 1; i < rows.size(); i++)
        maxRow = max(maxRow, rows[i] - rows[i - 1] - 1);

    // find the max col gap, which is unblocked
    for (int i = 1; i < cols.size(); i++)
        maxCol = max(maxCol, cols[i] - cols[i - 1] - 1);

    // return the area of the largest continuous unblocked area
    return maxRow * maxCol;
}

int main()
{
    int n = 15;
    int m = 8;
    int k = 3;

    vector<vector<int>> enemy = {{3, 8}, {11, 2}, {8, 6}};

    cout << largestArea(n, m, k, enemy);

    return 0;
}