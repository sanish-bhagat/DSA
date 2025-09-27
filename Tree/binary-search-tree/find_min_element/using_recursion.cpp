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

int minValue(Node *root)
{
    // base case -> if no left child of the node then that node is the min element
    if (!root || root->left == NULL)
        return root->data;

    // recursively traverse the left subtree for the min value
    return minValue(root->left);
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