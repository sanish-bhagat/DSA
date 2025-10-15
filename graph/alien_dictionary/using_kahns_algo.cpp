#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(26)

string findOrder(vector<string> &words)
{
    // adjcancey graph
    vector<vector<int>> graph(26);

    // bool[] to track the present characters
    vector<bool> exists(26, false);

    // in-degree for each character
    vector<int> inDegree(26);

    // mark existing characters
    for (auto word : words)
    {
        for (auto ch : word)
            exists[ch - 'a'] = true;
    }

    // build the graph from adjacent words
    for (int i = 0; i < words.size() - 1; i++)
    {
        // compare words in pairs
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.size(), s2.size());

        int j = 0;

        // same characters -> skip them
        while (j < len && s1[j] == s2[j])
            j++;

        // mark the edge
        if (j < len)
        {
            int u = s1[j] - 'a';
            int v = s2[j] - 'a';

            graph[u].push_back(v);
            inDegree[v]++;
        }

        // word1 size is greater than the word2 -> invalid check
        else if (s1.size() > s2.size())
            return "";
    }

    // topo sort
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (exists[i] && inDegree[i] == 0)
            q.push(i);
    }

    string res;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // store the character in the curr order
        res += (char)(u + 'a');

        // explore the adjacent nodes(characters)
        for (int v : graph[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    // check there was a cycle or not -> if present return "", ordering is not possible
    for (int i = 0; i < 26; i++)
    {
        if (exists[i] && inDegree[i] != 0)
            return "";
    }

    return res;
}

int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    string order = findOrder(words);

    cout << order;
    return 0;
}