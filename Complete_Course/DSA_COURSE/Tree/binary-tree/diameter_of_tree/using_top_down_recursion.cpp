#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node *root)
{
    if (root == 0)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

//! TC is O(n * n)
//! SC is O(h)

int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max({lHeight + rHeight, lDiameter, rDiameter});
}

int main()
{

    // Constructed binary tree is
    //          5
    //        /   \
    //       8     6
    //      / \   /
    //     3   7 9
    Node *root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);
    cout << diameter(root) << endl;

    return 0;
}