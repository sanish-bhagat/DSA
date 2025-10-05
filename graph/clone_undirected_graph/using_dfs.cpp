#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    vector<Node *> neighbors;
};

Node *cloneGraphHelper(Node *node, map<Node *, Node *> &mp)
{
    if (!node)
        return NULL;

    // curr node not cloned yet, then clone it
    if (mp.find(node) == mp.end())
    {
        Node *clone = new Node();
        clone->val = node->val;
        mp[node] = clone;

        // recursivelly clone all the neighbors of the curr node
        for (auto neighbor : node->neighbors)
            clone->neighbors.push_back(cloneGraphHelper(neighbor, mp));
    }

    // return the cloned node
    return mp[node];
}

//! TC is O(v + e)
//! SC is O(v)

Node *cloneGraph(Node *node)
{
    // map to store the already cloned nodes
    map<Node *, Node *> mp;
    return cloneGraphHelper(node, mp);
}

Node *buildGraph()
{
    Node *node1 = new Node();
    node1->val = 0;
    Node *node2 = new Node();
    node2->val = 1;
    Node *node3 = new Node();
    node3->val = 2;
    Node *node4 = new Node();
    node4->val = 3;

    node1->neighbors = {node2, node3};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node1, node2, node4};
    node4->neighbors = {node3};

    return node1;
}

bool compareGraphs(Node *node1, Node *node2,
                   map<Node *, Node *> &visited)
{
    if (!node1 || !node2)
        return node1 == node2;

    if (node1->val != node2->val || node1 == node2)
        return false;

    visited[node1] = node2;

    if (node1->neighbors.size() != node2->neighbors.size())
        return false;

    for (size_t i = 0; i < node1->neighbors.size(); ++i)
    {
        Node *n1 = node1->neighbors[i];
        Node *n2 = node2->neighbors[i];

        if (visited.count(n1))
        {
            if (visited[n1] != n2)
                return false;
        }
        else
        {
            if (!compareGraphs(n1, n2, visited))
                return false;
        }
    }

    return true;
}

// Driver Code
int main()
{
    Node *original = buildGraph();

    Node *cloned = cloneGraph(original);
    map<Node *, Node *> visited;
    cout << (compareGraphs(original, cloned, visited) ? "true" : "false") << endl;
    return 0;
}