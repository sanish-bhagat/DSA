#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * 2 ^ n)
//! SC is O(1)

vector<string> allPossibleStrings(string s)
{
    vector<string> res;
    int n = s.size();

    // explore all the possible subsets (0 -> 2^n - 1)
    for (int i = 0; i < (1 << n); i++)
    {
        string sub = "";

        // if ith bit is set, include in the subset
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sub += s[j];
        }

        // store the current subset
        res.push_back(sub);
    }

    // arrange in lexicographically order
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    string s = "abc";
    vector<string> subsets = allPossibleStrings(s);
    for (string sub : subsets)
        cout << sub << endl;

    return 0;
}