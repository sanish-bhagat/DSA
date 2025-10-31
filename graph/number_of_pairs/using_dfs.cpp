#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, int &num)
{
    // mark the node as vis
    vis[node] = true;

    // increase the count of the node in current component
    num++;

    // explore all the neighbors and perform dfs for the unvisited ones
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, num);
    }
}

//! TC is O(v + e)
//! SC is O(v + e)

int numberOfPairs(int N, vector<vector<int>> &arr)
{
    // build the adjacency matrix
    vector<vector<int>> adj(N);
    for (auto it : arr)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // track the visited nodes
    vector<bool> vis(N, false);

    // store the size of every connected components(no. of nodes in every component)
    vector<int> v;

    int num;

    // iteratively traverse every node and perform dfs for the unvisited nodes
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            // start with 0 nodes in the curr component
            num = 0;

            // recursivelly find the no. of nodes in a component
            dfs(i, vis, adj, num);

            // store the size(no. of nodes)
            v.push_back(num);
        }
    }

    // total no. of unique pairs for 'n' nodes
    int ans = (N * (N - 1)) / 2;

    // since these pairs are within the same component, we subtract them from ans
    for (int i : v)
    {
        ans -= (i * (i - 1)) / 2;
    }

    return ans;
}

int main()
{
    int N = 6;
    vector<vector<int>> arr = {{0, 1}, {0, 2}, {2, 5}};
    int res = numberOfPairs(N, arr);
    cout << res;
    return 0;
}