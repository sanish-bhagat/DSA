#include <bits/stdc++.h>
using namespace std;

bool wordBreakRec(int i, string &s, vector<string> &dictionary)
{
    // traversed the string compeletely -> return true
    if (i == s.length())
        return true;

    string prefix = "";

    // iteratively try for every prefix
    for (int j = i; j < s.length(); j++)
    {
        prefix += s[j];

        // prefix(s[i...j)]) present in the dictionary and
        // the rest of the string can also be broken in words -> then return true
        if (find(dictionary.begin(), dictionary.end(), prefix) != dictionary.end() && wordBreakRec(j + 1, s, dictionary))
            return true;
    }

    // tried all the prefixes and none have given the soln -> return false
    return false;
}

//! TC is O(2 ^ n)
//! SC is O(n)

bool wordBreak(string &s, vector<string> &dictionary)
{
    return wordBreakRec(0, s, dictionary);
}

int main()
{
    string s = "ilike";

    vector<string> dictionary = {"i", "like", "gfg"};

    cout << (wordBreak(s, dictionary) ? "true" : "false") << endl;

    return 0;
}