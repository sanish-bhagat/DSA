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

int getMaxSumRec(Node *root)
{
    if (!root)
        return 0;

    // 1st case - include the curr node and recursively call and include its grandchild into the sum
    int incl = root->data;

    // if left or right exists then call for the grand children of the curr node
    if (root->left)
    {
        incl += getMaxSumRec(root->left->left) + getMaxSumRec(root->left->right);
    }

    if (root->right)
    {
        incl += getMaxSumRec(root->right->left) + getMaxSumRec(root->right->right);
    }

    // 2nd case - exclude the curr node and recursively incllude its children into the sum
    int excl = 0;

    if (root->left)
        excl += getMaxSumRec(root->left);

    if (root->right)
        excl += getMaxSumRec(root->right);

    // return the max of both the results
    return max(incl, excl);
}

//! TC is O(2 ^ n)
//! SC is O(n)

int getMaxSum(Node *root)
{
    if (!root)
        return 0;

    return getMaxSumRec(root);
}

int main()
{

    // Creating a binary tree with the following structure:
    //          1
    //         / \
    //        2   3
    //       /   / \
    //      1   4   5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);

    cout << getMaxSum(root) << endl;
    return 0;
}