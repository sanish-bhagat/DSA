#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>> &graph, vector<int> &vis, vector<int> &st, string &ans)
{
    // mark the curr node as visited
    vis[u] = st[u] = 1;

    // explore all the adjacent nodes(characters) and perform dfs
    for (int v = 0; v < 26; v++)
    {
        if (graph[u][v])
        {
            if (!vis[v])
            {
                // recurse and check for cycle
                if (!dfs(v, graph, vis, st, ans))
                    return false;
            }
            // v(character) is already in stack -> leads to cycle
            else if (st[v])
                return false;
        }
    }

    // add the character to the string
    ans.push_back(char('a' + u));

    /// remove the character from the recursion stack(curr dfs path)
    st[u] = 0;
    return true;
}

//! TC is O(n * m)
//! SC is O(26)

string findOrder(vector<string> &words)
{
    // adjacency graph for the words
    vector<vector<int>> graph(26, vector<int>(26, 0));

    // bool[] to mark the current characters
    vector<bool> exists(26, false);

    // bool[] to mark teh visited ones
    vector<int> vis(26, 0);

    // used to store the curr dfs recursive path
    vector<int> st(26, 0);

    string ans = "";

    // mark the existing chars
    for (string word : words)
    {
        for (char ch : word)
            exists[ch - 'a'] = 1;
    }

    // traverse through the words and compare in pairs
    for (int i = 0; i < words.size() - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];
        int n = s1.size(), m = s2.size();
        int ind = 0;

        // same characters -> skip
        while (ind < n && ind < m && s1[ind] == s2[ind])
            ind++;

        // s1.size() is greater than s2.size() -> ordering not possible
        if (ind != n && ind == m)
            return "";

        // build the graph
        if (ind < n && ind < m)
            graph[s1[ind] - 'a'][s2[ind] - 'a'] = 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (exists[i] && !vis[i])
        {
            // cycle is found -> ordering not possible
            if (!dfs(i, graph, vis, st, ans))
                return "";
        }
    }

    // reverse the ans string to get the correct topological order
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string order = findOrder(words);

    if (order.empty())
    {
        cout << "No Ordering Possible" << endl;
    }
    else
    {
        cout << order << endl;
    }

    return 0;
}