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

int getMaxSumUtil(Node *root, unordered_map<Node *, int> &memo)
{
    if (!root)
        return 0;

    // if the result is already computed, return it from memo
    if (memo.find(root) != memo.end())
        return memo[root];

    int incl = root->data;

    if (root->left)
        incl += getMaxSumUtil(root->left->left, memo) + getMaxSumUtil(root->left->right, memo);

    if (root->right)
        incl += getMaxSumUtil(root->right->left, memo) + getMaxSumUtil(root->right->right, memo);

    int excl = 0;

    if (root->left)
        excl += getMaxSumUtil(root->left, memo);

    if (root->right)
        excl += getMaxSumUtil(root->right, memo);

    // store the max result in the hashmap(memo)
    memo[root] = max(incl, excl);

    // return the value
    return memo[root];
}

//! TC is O(n)
//! SC is O(n)

int getMaxSum(Node *root)
{
    if (!root)
        return 0;

    // using map to store the result with their node
    unordered_map<Node *, int> memo;
    return getMaxSumUtil(root, memo);
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