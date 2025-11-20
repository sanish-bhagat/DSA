#include <bits/stdc++.h>
using namespace std;

int lcsRec(string &s1, string &s2, string &s3, int n1, int n2, int n3)
{
    // base case -> any of the strings becomes empty, return
    if (n1 == 0 || n2 == 0 || n3 == 0)
        return 0;

    // character matches -> recurse for the remaining characters
    if (s1[n1 - 1] == s2[n2 - 1] && s2[n2 - 1] == s3[n3 - 1])
        return 1 + lcsRec(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1);

    // character doesn't matches -> take the max of the recursive calls
    return max({lcsRec(s1, s2, s3, n1 - 1, n2, n3),
                lcsRec(s1, s2, s3, n1, n2 - 1, n3),
                lcsRec(s1, s2, s3, n1, n2, n3 - 1)});
}

//! TC is O(3^(n1 + n2 + n3))
//! SC is O(min(n1 + n2 + n3))

int lcsOf3(string &s1, string &s2, string &s3)
{
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();

    return lcsRec(s1, s2, s3, n1, n2, n3);
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