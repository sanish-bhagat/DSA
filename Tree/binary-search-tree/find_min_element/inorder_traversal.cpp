#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void inorder(Node *root, vector<int> &inorderArray)
{
    if (!root)
        return;

    inorder(root->left, inorderArray);

    inorderArray.push_back(root->data);

    inorder(root->right, inorderArray);
}

//! TC is O(n)
//! SC is O(n)

int minValue(Node *root)
{
    vector<int> inorderArray;

    // find the inorder of BST which will be in the sorted order(property of BST)
    inorder(root, inorderArray);

    // return the  first element of the inorderArray
    return inorderArray[0];
}

int main()
{

    // Representation of input binary search tree
    //        5
    //       / \
    //      4   6
    //     /     \
    //    3       7
    //   /
    //  1
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << minValue(root) << "\n";

    return 0;
}