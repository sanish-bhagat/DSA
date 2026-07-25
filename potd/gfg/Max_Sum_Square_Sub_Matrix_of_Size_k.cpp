#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n * n)

int maximumSum(vector<vector<int>> &mat, int k)
{
    int n = mat.size();

    // keep track of running colSum
    vector<int> columnSum(n, 0);

    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // build the colSum for curr row
        for (int j = 0; j < n; j++)
        {
            // include the curr element
            columnSum[j] += mat[i][j];

            // exclude the out of window element
            if (i >= k)
                columnSum[j] -= mat[i - k][j];
        }

        // out of window row
        if (i >= k - 1)
        {
            // find the max sum possible
            int windowSum = 0;

            for (int j = 0; j < n; j++)
            {
                // include curr element in windowSum
                windowSum += columnSum[j];

                // exlcude out of window element
                if (j >= k)
                    windowSum -= columnSum[j - k];

                // update the global max sum
                if (j >= k - 1)
                    res = max(res, windowSum);
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, -1, 4}, {-8, -3, 4, 2}, {3, 8, 10, -8}, {-4, -1, 1, 7}};
    cout << maximumSum(mat, 3) << endl;
    return 0;
}