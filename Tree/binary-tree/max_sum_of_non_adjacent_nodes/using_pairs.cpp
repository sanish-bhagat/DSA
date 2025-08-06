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

pair<int, int> solve(Node *root)
{
    if (!root)
        return {0, 0};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    // curr node is inlcuded and left and right children are excluded
    res.first = root->data + left.second + right.second;

    // node is excluded
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

//! TC is O(n)
//! SC is O(h)

int getMaxSum(Node *root)
{
    if (!root)
        return 0;

    pair<int, int> res = solve(root);
    return max(res.first, res.second);
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