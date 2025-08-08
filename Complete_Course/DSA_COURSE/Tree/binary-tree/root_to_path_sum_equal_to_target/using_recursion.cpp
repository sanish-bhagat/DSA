#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *left, *right;
    int data;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

//! TC is O(n)
//! SC is O(h)

bool hasPathSum(Node *root, int target)
{
    if (!root)
        return 0;

    // decrease the target by the value of curr node
    int subSum = target - root->data;

    // if the remaining node is NULL and remaining sum is 0 then return true
    if (subSum == 0 && root->left == NULL && root->right == NULL)
        return 1;

    // recursively call for the left and right subtree passing subSum as target
    bool left = 0, right = 0;

    if (root->left)
        left = hasPathSum(root->left, subSum);

    if (root->right)
        right = hasPathSum(root->right, subSum);

    return left || right;
}

int main()
{

    int sum = 21;

    // Constructed binary tree is
    //         10
    //       /    \
    //      8      2
    //     / \    /
    //    3   5  2

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    if (hasPathSum(root, sum))
    {
        cout << "True" << endl;
    }
    else
        cout << "False";

    return 0;
}