#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int k)
    {
        data = k;
        left = nullptr;
        right = nullptr;
    }
};

int countNodes(Node *root)
{
    if (!root)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCompleteTree(Node *root, int index, int noOfNodes)
{
    // base case - leaf node is always complete tree
    if (!root)
        return true;

    // if curr index is greater than the no of nodes in the tree then
    // the tree is not complete
    if (index >= noOfNodes)
        return false;

    // recursivelly check for the left and right subtree
    return isCompleteTree(root->left, 2 * index + 1, noOfNodes) && isCompleteTree(root->right, 2 * index + 2, noOfNodes);
}

bool isHeapUtil(Node *root)
{
    // base case - 0 child -> leaf nodes
    if (!root->left && !root->right)
        return true;

    // 1 child - always should be the left child as it is complete tree,
    // and the child's value <= parent's value
    if (!root->right)
        return root->data >= root->left->data;

    // 2 child -
    else
    {
        // check for the heap property and recursivelly check for left and right subtree
        if ((root->data >= root->left->data) && (root->data >= root->right->data))
            return isHeapUtil(root->left) && isHeapUtil(root->right);

        // else if it doesn't satisfy heap property return false
        else
            return false;
    }
}

//! TC is O(n)
//! SC is O(h)

bool isHeap(Node *root)
{
    int noOfNodes = countNodes(root);

    // first check if the given tree is complete or not,
    // and then check for the heap property at every node
    return (isCompleteTree(root, 0, noOfNodes) && isHeapUtil(root));
}

int main()
{

    // Construct the Binary Tree
    //        10
    //       /  \
    //      9    8
    //     / \   / \
    //    7   6 5   4

    Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    if (isHeap(root))
    {
        cout << "true";
    }
    else
        cout << "false";

    return 0;
}