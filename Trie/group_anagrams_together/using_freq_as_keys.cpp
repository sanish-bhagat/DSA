#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

string getHash(string &s)
{
    string hash = "";
    vector<int> freq(MAX_CHAR, 0);

    // count the freq of each char
    for (char c : s)
        freq[c - 'a']++;

    // generate the string for the hashmap key, using the freq of every char separated by delimiter
    for (int i = 0; i < MAX_CHAR; i++)
    {
        hash.append(to_string(freq[i]));
        hash.append("$");
    }

    return hash;
}

//! TC is O(n * k)
//! SC is O(n * k)

vector<vector<string>> anagrams(vector<string> &arr)
{
    vector<vector<string>> res;
    unordered_map<string, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        // get the freq string, which serves as a key for hashmap
        string s = getHash(arr[i]);

        // check if the freq string is present or not,
        // if not then create a new group and store the index in the hashmap
        if (mp.find(s) == mp.end())
        {
            mp[s] = res.size();
            res.push_back({});
        }

        // push the string into its correct position
        res[mp[s]].push_back(arr[i]);
    }

    return res;
}

int main()
{
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};

    vector<vector<string>> res = anagrams(arr);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}