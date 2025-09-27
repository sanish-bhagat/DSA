#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

bool inorder(Node *root, int &prev)
{
    if (!root)
        return true;

    // recursively check the left subtree
    if (!inorder(root->left, prev))
        return false;

    // if curr node's value is less than prev one,
    //  it means inorder is not in ascending order(which violates BST property)
    if (prev >= root->data)
        return false;

    // store the prev value
    prev = root->data;

    // recursively check the right subtree
    return inorder(root->right, prev);
}

//! TC is O(n)
//! SC is O(h)

bool isBST(Node *root)
{
    int prev = INT_MIN;
    return inorder(root, prev);
}

int main()
{

    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}