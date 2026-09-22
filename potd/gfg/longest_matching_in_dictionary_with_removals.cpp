#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string &word, vector<vector<int>> &pos)
{
    int prevIdx = -1;

    for (char ch : word)
    {
        // all positions where character 'ch' occurs in s
        vector<int> &indices = pos[ch - 'a'];

        // find first occurrence of ch after prevIndex
        auto it = upper_bound(indices.begin(), indices.end(), prevIdx);

        // no valid next position found
        if (it == indices.end())
            return false;

        // update previously matched index
        prevIdx = *it;
    }

    return true;
}

//! TC is O(|s| + n * maxWordLen * log |s|)
//! SC is O(|s|)

string findLongestWord(string &s, vector<string> &d)
{
    // store positions of every lowercase character in s
    vector<vector<int>> pos(26);

    for (int i = 0; i < s.size(); i++)
        pos[s[i]].push_back(i);

    string res = "";

    for (string word : d)
    {
        // skip smaller words directly
        if (word.size() < res.size())
            continue;

        // check whether word is subsequence of s
        if (isSubsequence(word, pos))
        {
            // prefer longer word
            // if same length, prefer lexicographically smaller word
            if (word.size() > res.size() || (word.size() == res.size() && word < res))
                res = word;
        }
    }

    return res;
}

int main()
{
    string s = "abpcplea";
    vector<string> d = {"ale", "apple", "monkey", "plea"};

    cout << findLongestWord(s, d);

    return 0;
}