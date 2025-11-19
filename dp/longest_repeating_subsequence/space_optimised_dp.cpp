#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

int longestRepeatingSubsequence(string s)
{
    int n = s.length();

    // keep track of previous and current row values
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    // iterate through all the characters
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // character matches and are at different indices -> use previous row value to compute the current one
            if (s[i - 1] == s[j - 1] && i != j)
                curr[j] = 1 + prev[j - 1];

            // character doesn't matches or at same index -> use max of previous row and current row values
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }

        // update previous row with the current one
        prev = curr;
    }

    return prev[n];
}

int main()
{

    string s = "AABEBCDD";
    int res = longestRepeatingSubsequence(s);
    cout << res;

    return 0;
}