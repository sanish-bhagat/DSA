#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(min(n, m))

int findMinCost(string &s1, string &s2, int costS1, int costS2)
{
    // Ensure the shorter string determines the DP array size.
    if (s1.length() < s2.length())
    {
        swap(s1, s2);
        swap(costS1, costS2);
    }

    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1), curr(m + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }

        // Reuse the current row as the previous row for the next iteration.
        swap(prev, curr);
    }

    int lcsLength = prev[m];

    return (n - lcsLength) * costS1 + (m - lcsLength) * costS2;
}

int main()
{
    string s1 = "abcd", s2 = "acdb";
    int costS1 = 10, costS2 = 20;

    cout << findMinCost(s1, s2, costS1, costS2);

    return 0;
}