#include <bits/stdc++.h>
using namespace std;

void wordBreakHelper(string &s, unordered_set<string> &dictSet, vector<string> &res, string &curr, int start)
{
    // base case: if start reaches the end of the string, append the sentence to result
    if (start == s.length())
    {
        res.push_back(curr);
        return;
    }

    // traverse for all the words that can be formed by the curr start and all possible end letters
    for (int end = start + 1; end <= s.length(); end++)
    {

        // curr substring(word)
        string word = s.substr(start, end - start);

        // present in the dict
        if (dictSet.count(word))
        {
            string prev = curr;

            if (!curr.empty())
                curr += " ";

            // add new word to the curr sentence
            curr += word;

            // recursive call
            wordBreakHelper(s, dictSet, res, curr, end);

            // backtrack and restore the value of curr sentence
            curr = prev;
        }
    }
}

//! TC is O((2 ^ n) * k)
//! SC is O(n)

vector<string> wordBreak(string &s, vector<string> &dict)
{
    // unordered_set to keep track of the words present in the dict
    unordered_set<string> dictSet(dict.begin(), dict.end());

    vector<string> res;
    string curr;

    // start from 0 index(1st letter)
    wordBreakHelper(s, dictSet, res, curr, 0);

    return res;
}

int main()
{

    string s = "ilikesamsungmobile";
    vector<string> dict = {"i", "like", "sam", "sung",
                           "samsung", "mobile", "ice",
                           "and", "cream", "icecream",
                           "man", "go", "mango"};

    vector<string> result = wordBreak(s, dict);

    for (string sentence : result)
    {
        cout << sentence << endl;
    }

    return 0;
}