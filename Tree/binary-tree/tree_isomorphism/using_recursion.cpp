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
        left = right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(h)

bool isIsomorphic(Node *root1, Node *root2)
{
    // empty trees are said to be isomorphic
    if (!root1 && !root2)
        return true;

    // if either of the one node is empty then return false
    if (!root1 || !root2)
        return false;

    // if node's value differ then they are not isomorphic
    if (root1->data != root2->data)
        return false;

    // recursively check either -
    //  1. (root1 -> left is ismorphic to root2 -> left) and (root1 -> right is ismorphic to root2 -> right), or
    //  2. (root1 -> left is ismorphic to root2 -> right) and (root1 -> right is ismorphic to root2 -> left)
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) ||
            isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}

int main()
{

    // Representation of input binary tree 1
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //       / \
    //      7   8
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(8);

    // Representation of input binary tree 2
    //        1
    //       / \
    //      3   2
    //     /   / \
    //    6   4   5
    //           / \
    //          8   7
    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    // root2->left->left = new Node(6);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);
    root2->right->right->left = new Node(8);
    root2->right->right->right = new Node(7);

    if (isIsomorphic(root1, root2))
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }

    return 0;
}