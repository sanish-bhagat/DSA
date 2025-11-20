#include <bits/stdc++.h>
using namespace std;

//! TC is O(n1 * n2 * n3)
//! SC is O(n2 * n3)

int lcsOf3(string &s1, string &s2, string &s3)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    // stores previous row values
    vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {

        // reset curr row every time
        vector<vector<int>> curr(n2 + 1, vector<int>(n3 + 1, 0));

        for (int j = 1; j <= n2; j++)
        {
            for (int k = 1; k <= n3; k++)
            {
                // character matches -> use the previous row for the computation
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                    curr[j][k] = 1 + prev[j - 1][k - 1];

                // character doesn't matches -> use the max from previous and curr row values
                else
                    curr[j][k] = max({prev[j][k], curr[j - 1][k], curr[j][k - 1]});
            }
        }

        // update the previous row value with the curr row value
        prev = curr;
    }

    return prev[n2][n3];
}

int main()
{
    string s1 = "AGGT12";
    string s2 = "12TXAYB";
    string s3 = "12XBA";
    int res = lcsOf3(s1, s2, s3);
    cout << res;
    return 0;
}