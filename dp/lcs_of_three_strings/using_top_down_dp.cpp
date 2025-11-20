#include <bits/stdc++.h>
using namespace std;

int lcsRec(string &s1, string &s2, string &s3, int n1, int n2, int n3, vector<vector<vector<int>>> &memo)
{
    // base case -> any of the strings becomes empty, return
    if (n1 == 0 || n2 == 0 || n3 == 0)
        return 0;

    // already computed subproblem
    if (memo[n1][n2][n3] != -1)
        return memo[n1][n2][n3];

    // character matches -> recurse for the remaining characters
    if (s1[n1 - 1] == s2[n2 - 1] && s2[n2 - 1] == s3[n3 - 1])
        return memo[n1][n2][n3] = 1 + lcsRec(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1, memo);

    // character doesn't matches -> take the max of the recursive calls
    return memo[n1][n2][n3] = max({lcsRec(s1, s2, s3, n1 - 1, n2, n3, memo),
                                   lcsRec(s1, s2, s3, n1, n2 - 1, n3, memo),
                                   lcsRec(s1, s2, s3, n1, n2, n3 - 1, memo)});
}

//! TC is O(n1 * n2 * n3)
//! SC is O(n1 * n2 * n3)

int lcsOf3(string &s1, string &s2, string &s3)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    // keep track of the computed values
    vector<vector<vector<int>>> memo(n1 + 1, (vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1))));

    return lcsRec(s1, s2, s3, n1, n2, n3, memo);
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