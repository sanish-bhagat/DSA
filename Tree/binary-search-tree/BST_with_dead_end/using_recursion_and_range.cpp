#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool dfs(Node *root, int mini, int maxi)
{
    if (!root)
        return false;

    // if its a leaf node and the min and max range value matches then its a dead end
    if (!root->left & !root->right && mini == maxi)
        return true;

    // recursively check for left and right subtree
    return dfs(root->left, mini, root->data - 1) || dfs(root->right, root->data + 1, maxi);
}

//! TC is O(n)
//! SC is O(h)

bool isDeadEnd(Node *root)
{
    return dfs(root, 1, INT_MAX);
}

int main()
{

    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->left->left = new Node(1);

    if (isDeadEnd(root))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}