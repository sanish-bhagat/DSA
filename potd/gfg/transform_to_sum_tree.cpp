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
        left = nullptr;
        right = nullptr;
    }
};

int solve(Node *root)
{
    // base case
    if (!root)
        return 0;

    // leaf node
    if (!root->left && !root->right)
    {
        int sum = root->data;
        root->data = 0;
        return sum;
    }

    // recurse for left and right subtree
    int left = solve(root->left);
    int right = solve(root->right);

    // store the curr value of the node, as we are going to modify it
    // this will be treated as the older value
    int temp = root->data;

    // assign the new value
    root->data = left + right;

    // return the sum from the left and right subtree
    return left + right + temp;
}

//! TC is O(n)
//! SC is O(h)

Node *toSumTree(Node *root)
{
    solve(root);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    root->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    toSumTree(root);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);
    }
}