#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int size(Node *root)
{
    if (!root)
        return 0;

    // count the no. of nodes
    return 1 + size(root->left) + size(root->right);
}

bool isValidBst(Node *root, int mini, int maxi)
{
    if (!root)
        return true;

    // violates BST property
    if (root->data <= mini || root->data >= maxi)
        return false;

    // recursivelly check left and right subtree
    return isValidBst(root->left, mini, root->data) && isValidBst(root->right, root->data, maxi);
}

//! TC is O(n * n)
//! SC is O(n)

int largestBst(Node *root)
{
    if (!root)
        return 0;

    // check for the curr node if it is a BST
    //  if yes, then return the count of the nodes rooted to curr node
    if (isValidBst(root, INT_MIN, INT_MAX))
        return size(root);

    // else, return the max of left and right recursive call
    return max(largestBst(root->left), largestBst(root->right));
}

int main()
{

    // Constructed binary tree looks like this:
    //         50
    //       /    \
    //     75      45
    //    /
    //  40

    Node *root = new Node(50);
    root->left = new Node(75);
    root->right = new Node(45);
    root->left->left = new Node(40);

    cout << largestBst(root) << endl;
    return 0;
}