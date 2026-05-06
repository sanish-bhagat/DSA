#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

//! TC is O(n)
//! SC is O(h)

int getSize(Node *root)
{
    // base case
    if (!root)
        return 0;

    // recurse for left and right subtree
    int left = getSize(root->left);
    int right = getSize(root->right);

    return 1 + left + right;
}

int main()
{
    Node *root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);

    cout << getSize(root);
}