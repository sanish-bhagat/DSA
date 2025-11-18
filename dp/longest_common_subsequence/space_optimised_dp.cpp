#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(m)

int lcs(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    // keep track of the values of current and previous row
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // iterate through all the characters
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // character matches -> need value of previous row for computation
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];

            // character doesn't matches -> need max value from prev and curr row
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }

        // update the previous row with the curr row
        prev = curr;
    }

    // return the length of the longest common subsequence
    return prev[m];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();

    cout << lcs(s1, s2) << endl;

    return 0;
}