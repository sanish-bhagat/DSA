#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

string removeDuplicates(string &s)
{

    unordered_set<char> seen;
    string ans = "";

    for (char c : s)
    {

        if (seen.find(c) == seen.end())
        {
            ans.push_back(c);
            seen.insert(c);
        }
    }

    return ans;
}

int main()
{
    string s = "geeksforgeeks";
    cout << removeDuplicates(s) << endl;
    return 0;
}