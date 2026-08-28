#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(1)

int minCost(vector<vector<int>> &mat)
{
    int n = mat.size();

    // Minimum cost when the first row
    // selects each of the three choices.
    int prev0 = mat[0][0];
    int prev1 = mat[0][1];
    int prev2 = mat[0][2];

    // Process remaining rows.
    for (int i = 1; i < n; i++)
    {
        // Current row selects choice 0.
        int curr0 = mat[i][0] + min(prev1, prev2);

        // Current row selects choice 1.
        int curr1 = mat[i][1] + min(prev0, prev2);

        // Current row selects choice 2.
        int curr2 = mat[i][2] + min(prev0, prev1);

        // Move current row values to previous row.
        prev0 = curr0;
        prev1 = curr1;
        prev2 = curr2;
    }

    // The last row can end with any choice.
    return min(prev0, min(prev1, prev2));
}

int main()
{
    vector<vector<int>> mat = {{1, 50, 50}, {50, 50, 50}, {1, 50, 50}};
    cout << minCost(mat) << endl;

    return 0;
}