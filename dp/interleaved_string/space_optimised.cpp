#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.size(), m = s2.size();

    if (n + m != s3.size())
        return false;

    // 1d[] to store intermediate results
    vector<bool> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = true;

    // fill first row, s1 is empty
    for (int j = 1; j <= m; j++)
        prev[j] = prev[j - 1] && (s2[j - 1] == s3[j - 1]);

    // fill the dp rows
    for (int i = 1; i <= n; i++)
    {
        // first column, s2 is empty
        curr[0] = prev[0] && (s1[i - 1] == s3[i - 1]);

        for (int j = 1; j <= m; j++)
        {
            // curr index of s3
            int k = i + j;

            // use the reccurence relation to fill the dp table
            curr[j] = (prev[j] && s1[i - 1] == s3[k - 1]) ||
                      (curr[j - 1] && s2[j - 1] == s3[k - 1]);
        }

        // update the values
        prev = curr;
    }

    return prev[m];
}

int main()
{
    string s1 = "AAB";
    string s2 = "AAC";
    string s3 = "AAAABC";
    cout << (isInterleave(s1, s2, s3) ? "true" : "false") << endl;
    return 0;
}