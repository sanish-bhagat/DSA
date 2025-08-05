#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

//! TC is O(h)
//! SC is O(h)

int maxValue(Node *root)
{
    // if node has no right child then that node is the max element
    if (!root || root->right == NULL)
        return root->data;

    // recursively traverse the right subtree
    return maxValue(root->right);
}

int main()
{

    // Representation of input binary search tree
    //        5
    //       / \
    //      4   6
    //     /     \
    //    3       7
    //   /
    //  1
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << maxValue(root) << "\n";

    return 0;
}