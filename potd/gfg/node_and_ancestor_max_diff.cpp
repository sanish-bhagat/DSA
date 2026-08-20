#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int maxDiffUtil(Node *t, int *res)
{
    // returning Maximum int value if node is null.
    if (t == nullptr)
        return INT_MAX;

    // if there are no child nodes then we just return data at current node.
    if (t->left == nullptr && t->right == nullptr)
        return t->data;

    // recursively calling for left and right subtrees and
    // choosing their minimum.
    int val = min(maxDiffUtil(t->left, res), maxDiffUtil(t->right, res));

    // updating res if (node value - min value from subtrees) is bigger than res.
    *res = max(*res, t->data - val);

    // returning minimum value got so far.
    return min(val, t->data);
}

//! TC is O(n)
//! SC is O(n)

int maxDiff(Node *root)
{
    int res = INT_MIN;
    maxDiffUtil(root, &res);
    return res;
}

int main()
{

    // Construct the following binary tree
    //        5
    //       / \
    //      2   1

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(1);

    cout << maxDiff(root);

    return 0;
}