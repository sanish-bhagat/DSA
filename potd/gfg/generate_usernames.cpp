#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m), m -> avg no. of suffix colissions
//! SC is O(n * m)

vector<string> generateUsernames(vector<string> &arr)
{
    // used -> usernames already assigned
    unordered_set<string> used(arr.begin(), arr.end());

    // nextSuffix -> already used suffix for a username
    unordered_map<string, int> nextSuffix;

    vector<string> res;

    for (string s : arr)
    {
        // original username can be assigned
        if (nextSuffix.find(s) == nextSuffix.end())
        {
            res.push_back(s);
            nextSuffix[s] = 1;
        }

        // generate a new username by adding suffix
        else
        {
            int suffix = nextSuffix[s];
            string name = s + to_string(suffix);

            // keep on incrementing suffix until we find a non-assigned one
            while (used.find(name) != used.end())
            {
                suffix++;
                name = s + to_string(suffix);
            }

            // assign the generated username
            used.insert(name);
            res.push_back(name);
            nextSuffix[s] = suffix + 1;
        }
    }

    return res;
}

int main()
{
    vector<string> arr = {"a", "a", "a1", "a"};
    vector<string> res = generateUsernames(arr);

    for (string s : res)
        cout << s << " ";
}