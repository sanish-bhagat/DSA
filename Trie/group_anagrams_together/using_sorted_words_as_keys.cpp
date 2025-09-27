#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * k * logk)
//! SC is O(n * k)

vector<vector<string>> anagrams(vector<string> &arr)
{
    vector<vector<string>> res;
    unordered_map<string, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        string s = arr[i];

        // find the key by sorting the string, the sorted string of two anagrams will always be same
        sort(s.begin(), s.end());

        // find it in the map, if not present then store the index of the group in hashmap and
        //  push an empty array in res for grouping the words
        if (mp.find(s) == mp.end())
        {
            mp[s] = res.size();
            res.push_back({});
        }

        // push the curr word into it correct group
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