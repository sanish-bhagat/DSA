#include <bits/stdc++.h>
using namespace std;

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

//! TC i O(n * logn)
//! SC is O(n)

vector<int> topView(Node *root)
{
    vector<int> res;

    if (!root)
        return res;

    // map is used to get the first node of each line
    map<int, int> mpp;

    // queue keeps track of every node with thier respective line no.
    queue<pair<int, Node *>> q;
    q.push({0, root});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int line = it.first;
        Node *node = it.second;

        // if it is the first node of the line then map the line no. with node's data
        if (mpp.find(line) == mpp.end())
            mpp[line] = node->data;

        if (node->left)
            q.push({line - 1, node->left});

        if (node->right)
            q.push({line + 1, node->right});
    }

    for (auto it : mpp)
        res.push_back(it.second);

    return res;
}

int main()
{

    // Create a sample binary tree
    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = topView(root);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}