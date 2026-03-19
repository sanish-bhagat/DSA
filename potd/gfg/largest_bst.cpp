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
        left = right = NULL;
    }
};

// Custom data type to keep track of Minimum,Maximum value,
// and Size of the largest BST
class BSTInfo
{

public:
    int mini, maxi, mxsz;

    BSTInfo(int mn, int mx, int size)
    {
        mini = mn;
        maxi = mx;
        mxsz = size;
    }
};

BSTInfo largestBSTRec(Node *root)
{
    // valid BST of size 0
    if (!root)
        return BSTInfo(INT_MAX, INT_MIN, 0);

    // recusive calls for left and right subtree
    BSTInfo left = largestBSTRec(root->left);
    BSTInfo right = largestBSTRec(root->right);

    // check if the curr subtree is valid or not
    // left subtree max value < root -> data < right subtree min value
    if (left.maxi < root->data && root->data < right.mini)
        return BSTInfo(min(left.mini, root->data),
                       max(right.maxi, root->data), 1 + left.mxsz + right.mxsz);

    // curr subtree is not a valid BST
    return BSTInfo(INT_MIN, INT_MAX, max(left.mxsz, right.mxsz));
}

//! TC is O(n)
//! SC is O(n)

int largestBST(Node *root)
{
    // return the size of the largest BST
    return largestBSTRec(root).mxsz;
}

int main()
{

    // Constructed binary tree
    //         5
    //       /   \
  //      2     4
    //     / \
  //    1   3

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << largestBST(root) << endl;

    return 0;
}