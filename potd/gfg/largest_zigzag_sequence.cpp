#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int zigzagSequence(vector<vector<int>> &mat)
{
    int n = mat.size();

    // DP values for the previous row
    vector<int> prev = mat[0];

    for (int i = 1; i < n; i++)
    {
        int max1 = -1, max2 = -1, maxCol = -1;

        // Find the maximum and second maximum
        // values from the previous row
        for (int j = 0; j < n; j++)
        {
            if (prev[j] > max1)
            {
                max2 = max1;
                max1 = prev[j];
                maxCol = j;
            }
            else if (prev[j] > max2)
            {
                max2 = prev[j];
            }
        }

        vector<int> curr(n);

        for (int j = 0; j < n; j++)
        {

            // Use second maximum if the current column
            // is the same as the column of the maximum value
            curr[j] = mat[i][j] + (j == maxCol ? max2 : max1);
        }

        // Move to the next row.
        prev = curr;
    }

    // Find the maximum zigzag sum
    int res = 0;
    for (int x : prev)
    {
        res = max(res, x);
    }

    return res;
}

int main()
{
    vector<vector<int>> mat = {{3, 1, 2}, {4, 8, 5}, {6, 9, 7}};

    cout << zigzagSequence(mat) << endl;

    return 0;
}