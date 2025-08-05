
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        int data = d;
        left = right = NULL;
    }
};

int height(Node *root)
{
    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

//! TC is O(n * n)
//! SC is O(h)

bool isBalanced(Node *root)
{
    if (!root)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    // Representation of input BST:
    //            1
    //           / \
    //          2   3
    //         /  \
    //        4   5
    //       /
    //      8
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    cout << (isBalanced(root) ? "True" : "False");
    return 0;
}