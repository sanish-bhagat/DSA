#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m * min(n, m))
//! SC is O(1)

int maxCommStr(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();

    int res = 0;

    // itertaively generate all pair of indices and try for all substrings starting from index
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int curr = 0;

            // common character in both the strings
            while ((i + curr) < n && (j + curr) < m && s1[i + curr] == s2[j + curr])
                curr++;

            // pick the max length
            res = max(res, curr);
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