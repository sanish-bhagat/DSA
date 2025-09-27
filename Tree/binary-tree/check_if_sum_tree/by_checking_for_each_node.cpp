#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

int sum(Node *root)
{
    if (root == NULL)
        return 0;

    return sum(root->left) + root->data + sum(root->right);
}

//! TC is O(n * n)
//! SC is O(h)

bool isSumTree(Node *root)
{
    // if the node is null or is a leaf node then return true
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return true;

    int ls = sum(root->left);
    int rs = sum(root->right);

    // check for the curr node as well as for the left and right subtree
    if (root->data == (ls + rs) && isSumTree(root->left) && isSumTree(root->right))
        return true;

    return false;
}

int main()
{

    // create hard coded tree
    //       26
    //      /  \
    //     10   3
    //    / \    \
    //   4  6     3
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    if (isSumTree(root))
        cout << "True";
    else
        cout << "False";

    return 0;
}