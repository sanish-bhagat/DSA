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
//! SC is O(1)

int maxValue(Node *root)
{
    if (!root)
        return -1;

    Node *curr = root;

    // traversing olny the right subtree as it will contain the max element
    while (curr->right)
        curr = curr->right;

    // return the node's value that does nnot have right subtree as it is the max element of the BST
    return curr->data;
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