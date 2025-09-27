#include <bits/stdc++.h>
using namespace std;

void palindromes(string &s, vector<vector<bool>> &dp)
{
    int n = s.size();

    // 1-letter word is always a palindrome
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    // check for two letter word
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = (s[i] == s[i + 1]);

    // check for word having len >= 3 using bottom-up DP
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }
}

void solve(int idx, string &s, vector<string> &curr, vector<vector<string>> &res, vector<vector<bool>> &dp)
{
    // base case
    if (idx == s.size())
    {
        res.push_back(curr);
        return;
    }

    // explore all the combinations of substring
    for (int i = idx; i < s.size(); i++)
    {

        // substring is a palindrome
        if (dp[idx][i])
        {
            // store the substring
            curr.push_back(s.substr(idx, i - idx + 1));

            // recursive call
            solve(i + 1, s, curr, res, dp);

            // backtrack: to explore more combinations
            curr.pop_back();
        }
    }
}

//! TC is O(n * 2^n)
//! SC is O(n * 2^n)

vector<vector<string>> palinParts(string &s)
{
    // dp table: for storing palindrome strings
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));
    palindromes(s, dp);

    vector<vector<string>> res;
    vector<string> curr;

    solve(0, s, curr, res, dp);

    return res;
}

int main()
{
    string s = "geeks";

    vector<vector<string>> res = palinParts(s);

    // Print result: one partition per line
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            cout << res[i][j];
            if (j != res[i].size() - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}