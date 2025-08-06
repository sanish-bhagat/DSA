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

int minValue(Node *root)
{
    if (!root)
        return -1;

    Node *curr = root;

    // traverse only the left edges
    while (curr->left)
        curr = curr->left;

    // if node have node left child then return its value as its the min element
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

    cout << minValue(root) << "\n";

    return 0;
}