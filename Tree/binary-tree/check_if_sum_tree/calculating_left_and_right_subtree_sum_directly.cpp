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

bool isLeaf(Node *root)
{
    if (root == NULL)
        return false;

    else if (root->left == NULL && root->right == NULL)
        return true;

    return false;
}

//! TC is O(n)
//! Sc is O(h)

bool isSumTree(Node *root)
{
    if (root == NULL || isLeaf(root))
        return true;

    int ls, rs;

    // if left and right subtree are sum trees, then we can find the sum in O(1) time
    if (isSumTree(root->left) && isSumTree(root->right))
    {

        // get the sum of left subtree
        if (root->left == NULL)
            ls = 0;

        else if (isLeaf(root->left))
            ls = root->left->data;

        else
            ls = 2 * (root->left->data);

        // get the sum of right subtree
        if (root->right == NULL)
            rs = 0;

        else if (isLeaf(root->right))
            rs = root->right->data;

        else
            rs = 2 * (root->right->data);

        // If root's data is equal to sum of nodes in left
        // and right subtrees then return true else return false
        return (root->data == ls + rs);
    }

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