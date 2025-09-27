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

bool findVal(Node *root, int val)
{
    // if val is 0 or -ve then return true, as only val > 0 are present in the BST
    if (val <= 0)
        return true;

    if (!root)
        return false;

    if (root->data == val)
        return true;

    else if (root->data < val)
        return findVal(root->right, val);

    return findVal(root->left, val);
}

bool dfs(Node *curr, Node *root)
{
    if (!curr)
        return false;

    // for leaf node check if it a dead node or not
    // by traversing the tre and checking if val - 1 and val + 1 both are present already in the BST
    //  then the curr node is a dead end int BST
    if (curr->left == NULL && curr->right == NULL)
    {
        int val = curr->data;

        return findVal(root, val - 1) && findVal(root, val + 1);
    }

    // recursively check for left and right subtree
    return dfs(curr->left, root) || dfs(curr->right, root);
}

//! TC is O(n * h)
//! SC is O(h)

bool isDeadEnd(Node *root)
{
    // recursively traverse the tree
    return dfs(root, root);
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