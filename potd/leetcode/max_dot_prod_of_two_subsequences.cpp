#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(m)

int maxDotProd(vector<int> &num1, vector<int> &num2)
{
    int n = num1.size(), m = num2.size();
    const int NEG_INF = -1e9;

    // 1d[] to stores dp states
    vector<int> prev(m + 1, NEG_INF);

    // traverse through every sequences
    for (int i = 1; i <= n; i++)
    {
        // reset curr[] for every iteration
        vector<int> curr(m + 1, NEG_INF);
        
        for (int j = 1; j <= m; j++)
        {
            // dot prod of curr pair subsequence
            int prod = num1[i - 1] * num2[j - 1];

            // at every time we have three choices:
            // case1: extend the existing sequence by pairing num1[i - 1] and num2[j - 1],
            // case2: skip num1[i - 1],
            // case3: skip num2[j - 1]
            curr[j] = max({prod,
                           prod + prev[j - 1],
                           curr[j - 1],
                           prev[j]});
        }

        // update the dp states
        prev = curr;
    }

    // return the max dot product
    return prev[m];
}

int main()
{
    vector<int> num1 = {2, 1, -2, 5};
    vector<int> num2 = {3, 0, -6};

    cout << maxDotProd(num1, num2);
}