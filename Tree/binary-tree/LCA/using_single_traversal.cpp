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
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(h)

Node *lca(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    // if either of the keys matches with the root data then simply return the root as the lca
    if (root->data == n1 || root->data == n2)
        return root;

    // if no match then recursivelly call for the left and right subtree
    Node *leftLca = lca(root->left, n1, n2);
    Node *rightLca = lca(root->right, n1, n2);

    // if leftLca is NULL then return rightLca no matter if it is null or non-null
    if (leftLca == NULL)
        return rightLca;

    // if rightLca is NULL then return leftLca no matter if it is null or non-null
    else if (rightLca == NULL)
        return leftLca;

    // if both the above calls return non-null
    //  then one data is present in one subtree and the other data is present in the other subtree,
    //  so return the curr node as the LCA
    else
        return root;
}

int main()
{

    // construct the binary tree
    //			   1
    //           /   \
    //          2     3
    //         / \   / \
    //        4  5  6   7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *ans = lca(root, 4, 5);
    if (ans == nullptr)
        cout << "No common ancestor found";
    else
        cout << ans->data;
    return 0;
}