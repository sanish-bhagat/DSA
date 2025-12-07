#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(m)

int maxCommStr(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    // second string is longer than first string
    if(n < m)
        return maxCommStr(s2, s1);

    // 1d[] tp keep track of values of previous row
    vector<int> prev(m + 1, 0);

    int res = 0;

    // iteratively generate all the pairs of indexes
    for (int i = 1; i <= n; i++)
    {
        // compute and store the curr row values
        vector<int> curr(m + 1, 0);

        for (int j = 1; j <= m; j++)
        {
            // character matches -> include it in the curr suffix of the substring
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                res = max(res, curr[j]);
            }
            // character not matches -> start a new substring
            else
                curr[j] = 0;
        }

        // update the previous row values with the curr row
        prev = curr;
    }

    return res;
}

int main()
{
    string s1 = "practicewritegeekscourses";
    string s2 = "geeksforgeeks";
    cout << maxCommStr(s1, s2) << endl;
    return 0;
}