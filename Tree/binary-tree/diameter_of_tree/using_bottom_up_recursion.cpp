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

int diameterRec(Node *root, int &res)
{
    if (root == NULL)
        return 0;

    int lHeight = diameterRec(root->left, res);
    int rHeight = diameterRec(root->right, res);

    res = max(res, lHeight + rHeight);

    return 1 + max(lHeight, rHeight);
}

//! TC is O(n)
//! SC is O(h)

int diameter(Node *root)
{
    int res = 0;
    diameterRec(root, res);
    return res;
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