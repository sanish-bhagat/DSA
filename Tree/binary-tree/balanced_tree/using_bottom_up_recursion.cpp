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

int isBalancedRec(Node *root)
{
    if (!root)
        return 0;

    // calculate the height of the leftSubtree and rightSubtree for the current root node
    int leftHeight = isBalancedRec(root->left);
    int rightHeight = isBalancedRec(root->right);

    // if the leftsubtree or rightsubtree is not balanced then return -1
    if (leftHeight == -1 || rightHeight == -1)
        return -1;

    // if the height difference is greater than 1 then return -1
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // else return the heigth of the subtree
    return 1 + max(leftHeight, rightHeight);
}

//! TC is O(n)
//! SC is O(h)

bool isBalanced(Node *root)
{
    // if the height of the tree is greater than 0 then return true else false
    return (isBalancedRec(root) > 0);
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