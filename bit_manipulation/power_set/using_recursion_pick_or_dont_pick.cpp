#include <bits/stdc++.h>
using namespace std;

//! TC is O(2 * n)
//! SC is O(n)

void powerSet(string s, int index, vector<string> &res, string curr = "")
{
    int n = s.size();

    // base case -> include the subset in res
    if (index == n)
    {
        res.push_back(curr);
        return;
    }

    // either consider the character as part of curr subset
    // or do not consider it as a part of curr subset
    powerSet(s, index + 1, res, curr + s[index]);
    powerSet(s, index + 1, res, curr);
}

vector<string> allPossibleStrings(string s)
{
    vector<string> res;
    powerSet(s, 0, res, "");

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