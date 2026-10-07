#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int maxSumUtil(Node *root, int &res)
{
    if (!root)
        return 0;

    // leaf node
    if (!root->left && !root->right)
        return root->data;

    // recurse for left and right subtree
    int leftSum = maxSumUtil(root->left, res);
    int rightSum = maxSumUtil(root->right, res);

    if (root->left && root->right)
    {
        // combine both root-to-leaf paths through the current node
        res = max(res, leftSum + rightSum + root->data);

        // and return the max of both the pathSum
        return max(leftSum, rightSum) + root->data;
    }

    if (root->left)
        return leftSum + root->data;

    return rightSum + root->data;
}

//! TC is O(n)
//! SC is O(h)

int maxPathSum(Node *root)
{
    // base case
    if (!root)
        return -1;

    int res = INT_MIN;
    maxSumUtil(root, res);

    return res == INT_MIN ? -1 : res;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(-10);
    root->left->right = new Node(4);

    cout << maxPathSum(root);

    return 0;
}