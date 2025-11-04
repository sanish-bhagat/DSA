#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = true;

    for (int v : adj[node])
    {
        if (!vis[v])
            dfs(v, vis, adj);
    }
}

int isEulerCircuit(int v, vector<int> adj[])
{
    // track visited nodes
    vector<bool> vis(v + 1, false);

    // find the first node with non-zero degree, i.e from where we can start to traverse the graph
    int start = -1;
    for (int i = 0; i < v; i++)
    {
        if (adj[i].size() > 0)
        {
            start = i;
            break;
        }
    }

    // no edges -> graph is trivially eulerian
    if (start == -1)
        return 2;

    // start the dfs traversal from the start node and visit the nodes in the path
    dfs(start, vis, adj);

    // node having non-zero degree but belongs to different component(was not visited during curr dfs traversal) -> not a eulerian path
    for (int i = 0; i < v; i++)
    {
        if (adj[i].size() > 0 && !vis[i])
            return 0;
    }

    // count vertices having odd degrees
    int odd = 0;
    for (int i = 0; i < v; i++)
    {
        if (adj[i].size() % 2 != 0)
            odd++;
    }

    // eulerian circuit
    if (odd == 0)
        return 2;

    // eulerian path
    else if (odd == 2)
        return 1;

    // none
    else
        return 0;
}

int main()
{

    int v = 5;
    vector<int> adj[5] = {{1, 2, 3}, {0, 2}, {1, 0}, {0, 4}, {3}};

    int res = isEulerCircuit(v, adj);

    if (res == 0)
        cout << "Euler Circuit";

    else if (res == 2)
        cout << "Euler Path";

    else
        cout << "Not Eulerian Cycle or Path";

    return 0;
}