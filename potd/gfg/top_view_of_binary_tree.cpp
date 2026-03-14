#include <bits/stdc++.h>
using namespace std;

// Node Structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<int> topView(Node *root)
{
    // base case
    if (!root)
        return {};

    // queue for level order traversal -> {node, dist}
    queue<pair<Node *, int>> q;

    // map stores nodes at a particular horizontal distance
    unordered_map<int, int> mp;
    int mn = INT_MAX;

    Node *temp = NULL;

    q.push({root, 0});

    while (!q.empty())
    {
        // front node and its distance
        temp = q.front().first;
        int d = q.front().second;

        mn = min(mn, d);
        q.pop();

        // store the temp data in map
        if (mp.find(d) == mp.end())
            mp[d] = temp->data;

        // if left child of temp exists, pushing it in
        // the queue with the horizontal distance.
        if (temp->left)
            q.push({temp->left, d - 1});

        // if right child of temp exists, pushing it in
        // the queue with the horizontal distance.
        if (temp->right)
            q.push({temp->right, d + 1});
    }

    vector<int> ans(mp.size());

    // traversing the map and storing the nodes in list
    // at every horizontal distance.
    for (auto it = mp.begin(); it != mp.end(); it++)
        ans[it->first - mn] = it->second;

    return ans;
}

int main()
{

    // Create a sample binary tree
    //     10
    //    / \
    //   20  30
    //  / \   / \
    // 40  60 90  100

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->right->left = new Node(90);
    root->right->right = new Node(100);

    vector<int> result = topView(root);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}