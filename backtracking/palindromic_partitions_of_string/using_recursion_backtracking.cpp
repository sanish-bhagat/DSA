#include <bits/stdc++.h>
using namespace std;

// checks whether a substring is palindrome or not
bool isPalindrome(string &s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }

    return true;
}

void solve(int idx, string &s, vector<string> &curr, vector<vector<string>> &res)
{
    // base case
    if (idx == s.size())
    {
        res.push_back(curr);
        return;
    }

    string temp = "";

    // explore all the combination of the substring
    for (int i = idx; i < s.size(); i++)
    {
        temp += s[i];

        // curr substring is a palindrome
        if (isPalindrome(temp))
        {
            // store it
            curr.push_back(temp);

            // recursive call
            solve(i + 1, s, curr, res);

            // bacltrack: to explore other combinations
            curr.pop_back();
        }
    }
}

//! TC is O(n * n * 2^n)
//! SC is O(n * 2^n)

vector<vector<string>> palinParts(string &s)
{
    vector<vector<string>> res;
    vector<string> curr;

    solve(0, s, curr, res);

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