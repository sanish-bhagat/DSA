#include <bits/stdc++.h>
using namespace std;

int LCSRec(string s1, string s2, int i, int j)
{
    // unmatched characters
    if (i == 0 || j == 0 || s1[i - 1] != s2[j - 1])
        return 0;

    // recursively traverse all the substrings ending at this pair of characters
    return 1 + LCSRec(s1, s2, i - 1, j - 1);
}

//! TC is O(n * m * min(n, m))
//! SC is O(min(n, m))

int maxCommStr(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    int res = 0;

    // iteratively generate all the pair of indices
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // recursively find the length of the substring ending at the every pair of characters
            // and pick the max length of all substrings
            res = max(res, LCSRec(s1, s2, i, j));
        }
    }

    return res;
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "practicewritegeekscourses";
    cout << maxCommStr(s1, s2) << endl;
    return 0;
}