#include <bits/stdc++.h>
using namespace std;

bool isInterleaveRec(string s1, string s2, string s3, int i, int j, vector<vector<bool>> &memo)
{
    int k = i + j;

    // base case: traversed all the strings fully
    if (i == s1.size() && j == s2.size() && k == s3.size())
        return true;

    // already computed subproblem
    if (memo[i][j] != -1)
        return memo[i][j];

    // character of s1 and s3 matches -> move both ptrs forward in both the strings
    bool a = (i < s1.size()) && (s1[i] == s3[k]) && isInterleaveRec(s1, s2, s3, i + 1, j, memo);

    // character of s2 and s3 matches -> move both ptrs forward in both the strings
    bool b = (j < s2.size()) && (s2[j] == s3[k]) && isInterleaveRec(s1, s2, s3, i, j + 1, memo);

    // if any of the above two possibilities return true otherwise return false.
    return memo[i][j] = a || b;
}

//! TC is O(2 ^ (n + m))
//! SC is O(n + m)

bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.size(), m = s2.size();

    if (n + m != s3.size())
        return false;

    // 2d memo[]
    vector<vector<bool>> memo(n + 1, vector<bool>(m + 1, -1));

    return isInterleaveRec(s1, s2, s3, 0, 0, memo);
}

int main()
{
    string s1 = "AAB";
    string s2 = "AAC";
    string s3 = "AAAABC";
    cout << (isInterleave(s1, s2, s3) ? "true" : "false") << endl;
    return 0;
}