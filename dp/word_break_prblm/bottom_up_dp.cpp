#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k * m)
//! SC is O(n)

bool wordBreak(string &s, vector<string> &dictionary)
{
    int n = s.size();

    // 1d dp[] -> check whether the substring from 0 to the curr position(i) can be broken into dictionary words or not
    vector<bool> dp(n + 1, 0);

    // empty string can always be broken
    dp[0] = 1;

    // iteratively traverse through the given substring
    for (int i = 1; i <= n; i++)
    {
        // traverse through dictionary words
        for (string &w : dictionary)
        {
            // start position of the substring
            int start = i - w.size();

            // current word is present and the prefix before the word is also breakable
            if (start >= 0 && dp[start] && (s.substr(start, w.size()) == w))
            {
                // substring can be broken into dictionary words
                dp[i] = 1;
                break;
            }
        }
    }

    // return whether the string can be broken into words of dictionary or not
    return dp[n];
}

int main()
{
    string s = "ilike";

    vector<string> dictionary = {"i", "like", "gfg"};

    cout << (wordBreak(s, dictionary) ? "true" : "false") << endl;

    return 0;
}