#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(n)

vector<vector<int>> verticalOrder(Node *root)
{
    if (!root)
        return {};

    // hashmap, {dist, nodes[]}
    unordered_map<int, vector<int>> mp;

    // queue for level order traversal
    queue<pair<Node *, int>> q;

    q.push({root, 0});
    int mn = INT_MAX, mx = INT_MIN;

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        // curr node and horizontal distance
        Node *curr = top.first;
        int d = top.second;

        mn = min(mn, d);
        mx = max(mx, d);

        // insert this data in the horizontal distance[]
        mp[d].push_back(curr->data);

        // push the left node with decremented dist
        if (curr->left)
            q.push({curr->left, d - 1});

        // push the left node with incremented dist
        if (curr->right)
            q.push({curr->right, d + 1});
    }

    // build the res[][]
    vector<vector<int>> res;
    for (int i = mn; i <= mx; i++)
        res.push_back(mp[i]);

    return res;
}

int main()
{

    // Constructing the binary tree:
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    //          \  \
    //           8  9
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    vector<vector<int>> res = verticalOrder(root);

    for (vector<int> temp : res)
    {
        cout << "[ ";
        for (int val : temp)
            cout << val << " ";
        cout << "] ";
    }

    return 0;
}