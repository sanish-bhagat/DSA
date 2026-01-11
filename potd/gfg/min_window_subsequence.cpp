#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(1)

string minWindow(string s1, string s2)
{
    int n = s1.size(), m = s2.size();

    int minLen = INT_MAX;
    string ans = "";

    int i = 0;

    // scan s1 and try to match s2 as a subsequence
    while (i < n)
    {
        int j = 0;

        // try to match subsequence s2 with s1
        while (i < n)
        {
            // char matches, move ptr
            if (s1[i] == s2[j])
                j++;

            // s2 matches fully -> break this loop
            if (j == m)
                break;

            // move ptr forward in s1
            i++;
        }

        // s2 doesn't matches completely -> no window possible
        if (j != m)
            break;

        int end = i;
        j = m - 1;

        // backtrack -> shrink the window from left
        while (i >= 0)
        {
            if (s1[i] == s2[j])
                j--;

            if (j < 0)
                break;

            i--;
        }

        // curr window len
        int start = i;
        int len = end - start + 1;

        // minimise the window length
        if (len < minLen)
        {
            minLen = len;
            ans = s1.substr(start, len);
        }

        // update i ptr for next iteration
        i = start + 1;
    }

    return ans;
}

int main()
{
    string s1 = "abcdebdde";
    string s2 = "bde";
    string res = minWindow(s1, s2);

    for (char c : res)
        cout << c;
}