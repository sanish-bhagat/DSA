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

bool checkIsBST(Node *root, int min, int max)
{
    if (!root)
        return true;

    // if node's value is out of range, return false
    if (root->data < min || root->data > max)
        return false;

    // check for left and right subtree with the updated range
    return (checkIsBST(root->left, min, root->data - 1) && checkIsBST(root->right, root->data + 1, max));
}

//! TC is O(n)
//! SC is O(h)

bool isBST(Node *root)
{
    return checkIsBST(root, INT_MIN, INT_MAX);
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
